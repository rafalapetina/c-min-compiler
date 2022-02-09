#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash(char * key) {
  int temp = 0;
  int i = 0;
  while (key[i] != '\0') {
    temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

Scope newScope(char * scopeName) {
  Scope newScope = (Scope) malloc(sizeof(struct EscopoLista));
  newScope->name = scopeName;
  return newScope;
}

void pushScope(Scope escopo) {
  scopeList[sizeOfList++] = escopo;
}

Scope getScope() {
  return scopeList[sizeOfList-1];
}

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */

void st_insert( char * scopeName,
                char * name,
                ExpType type,
                TreeNode * treeNode,
                int loc ) {

  int h = hash(name);
  Scope escopo = getScope();

  BucketList l = escopo->hashTable[h];

  /** try to find bucket */
  while ((l != NULL) && (strcmp(name, l->name) != 0)) l = l->next;

  /* variable not yet in BucketList */
  if (l == NULL) {
    l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->treeNode = treeNode;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = treeNode->lineno;
    l->type = type;
    l->memloc = loc;
    l->lines->next = NULL;
    l->next = escopo->hashTable[h];
    escopo->hashTable[h] = l;
  } else {
    /* already exist in the BucketList */
    LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
  }
} /* st_insert */

/* Function st_lookup returns Bucket
 * location of a variable or NULL if not found
 */
BucketList st_lookup(char * name) {

  Scope escopo = getScope();
  int h = hash(name);
  BucketList bucket = escopo->hashTable[h];

  while ((bucket != NULL) && (strcmp(name, bucket->name) != 0)) bucket = bucket->next;
  return bucket;
}

BucketList st_lookup_all_scope(char * name) {
  Scope escopo = getScope();
  int h = hash(name);
  BucketList bucket;

  while (escopo != NULL ) {
    BucketList bucket = escopo->hashTable[h];
    while ((bucket != NULL) && (strcmp(name, bucket->name) != 0)) bucket = bucket->next;
    if (bucket != NULL) return bucket;
    escopo = escopo->parent;
  }
  return NULL;
}
/* Function st_lookup returns Bucket
 * location of a variable or NULL if not found
 * To check redefinition of function
 */
Scope st_lookup_scope(char * scopeName) {
  Scope escopo = NULL;
  for (int i=0; i<sizeOfList; i++) {
    if (strcmp(scopeList[i]->name, scopeName) == 0) {
      escopo = scopeList[i];
      break;
    }
  }
  return escopo;
}

void insertLines(char* name, int lineno) {
  Scope escopo = getScope();
  int h = hash(name);
  BucketList l = escopo->hashTable[h];

  while (escopo != NULL) {
    if (l != NULL) {
      LineList lines = l->lines;
      while (lines->next != NULL) {
        lines = lines->next;
      }
      lines->next =  (LineList) malloc(sizeof(struct LineListRec));
      lines->next->lineno = lineno;
      lines->next->next = NULL;
      return;
    }
    escopo = escopo->parent;
  }
}

void printSymTabRows(Scope escopo) {

  BucketList * hashTable = escopo->hashTable;

  for (int i=0; i<SIZE; ++i) {
    if (hashTable[i] != NULL) {
      BucketList l = hashTable[i];
      TreeNode *node = l->treeNode;
      while (l != NULL) {

        LineList lines = l->lines;
        fprintf(symTab,"%-10s", l->name);

        switch (node->nodekind) {
          case declK:
          switch (node->kind.decl) {
            case varK:
              fprintf(symTab, "Variable          ");
              break;
            case paramK:
              fprintf(symTab, "Parameter         ");
              break;
            case funcK:
              fprintf(symTab, "Function          ");
              break;
            case vectparamK:
              fprintf(symTab, "Array Parameter   ");
              break;
            case vectvarK:
              fprintf(symTab, "Array Variable    ");
              break;
            default:
            break;
          }
          break;
          default:
          break;
        }

        fprintf(symTab, "%-10s", escopo->name);

        switch (l->type) {
          case Void:
          fprintf(symTab, "   Void          ");
          break;
          case Integer:
          fprintf(symTab, "   Integer       ");
          break;
          case VectInt:
          fprintf(symTab, "   Integer Array ");
          break;
          default:
          break;
        }
        //print memory location
        fprintf(symTab, "%-10d", l->memloc);

        // print line numbers
        while (lines->next != NULL) {
          fprintf(symTab, "%d, ", lines->lineno);
          lines = lines->next;
        }
        fprintf(symTab, "%d\n", lines->lineno);
        l = l->next;
      }
    }
  }
}
/* Procedure printSymTab prints a formatted
 * symTab of the symbol table contents
 * to the symTab file
 */
void printSymTab(FILE * symTab) {

  fprintf(symTab, "  Symbol table  \n\n");

  fprintf(symTab, "---------------------------------------------------------------------------\n");
  fprintf(symTab, "Name       Type             Scope       Data Type     Location   Line Numbers \n");
  fprintf(symTab, "---------  ---------------  ----------  ------------  ---------  --------------\n");

  for (int i = 0; i<sizeOfList; ++i) {
    Scope escopo = scopeList[i];
    printSymTabRows(escopo);
  }
  fprintf(symTab, "---------------------------------------------------------------------------\n");
}
