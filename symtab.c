#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

static int hash (char* key, char* Escopo) { 
    int temp = 0;
    int i = 0;
    while (key[i] != '\0') { 
        temp = ((temp << SHIFT) + key[i]) % SIZE;
        ++i;
    }
    i = 0;
    while (Escopo[i] != '\0') { 
        temp = ((temp << SHIFT) + Escopo[i]) % SIZE;
        ++i;
    }
    return temp;
}

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
typedef struct LineListRec
{ 
    int lineno;
    struct LineListRec * next;
    
} * LineList;

typedef struct BucketListRec
{ 
     char* name;
     LineList lines;
     int memloc ; /* memory location for variable */
	 char* Escopo;
	 char* typeID;
	 char* typeData; 
     int paramQt; /* Stores the number of parameter of a function -> funcK */
     struct BucketListRec * next;
     
 } * BucketList;

static BucketList hashTable[SIZE];

void st_insert( char *name, int lineno, int loc, char* Escopo, char* typeID, char* typeData, int paramQt) { 
    int h = hash(name, Escopo);
    BucketList l =  hashTable[h];
    while ((l != NULL) && (strcmp(name,l->name) != 0) && (strcmp(Escopo,l->Escopo) != 0)) 
            l = l->next;
    if (l == NULL) {/* variable not yet in table */
        l = (BucketList) malloc(sizeof(struct BucketListRec));
        l->name = name;
        l->lines = (LineList) malloc(sizeof(struct LineListRec));
        l->lines->lineno = lineno;
        l->memloc = loc;
        l->lines->next = NULL;
        l->Escopo = Escopo;
        l->typeID = typeID;
        l->typeData = typeData;
        l->paramQt = paramQt;
        l->next = hashTable[h];
        hashTable[h] = l; 
    }
    else { /* found in table, so just add line number */
        LineList t = l->lines;
        while (t->next != NULL) 
            t = t->next;
        t->next = (LineList) malloc(sizeof(struct LineListRec));
        t->next->lineno = lineno;
        t->next->next = NULL;  
    }
} 

int st_lookup (char* name, char* Escopo,char* typeID) { 
  int h = hash(name, Escopo);
  BucketList l =  hashTable[h];

  while ((l != NULL) && (strcmp(name,l->name) != 0) && (strcmp(Escopo,l->Escopo) != 0)){
        l = l->next;
  }
  if (l == NULL){ 
      return -1;
  }
  else{
      
      return l->memloc;
  }
}

char* st_lookup_type (char* name, char* Escopo) { 
  int h = hash(name, Escopo);	
  BucketList l =  hashTable[h];

  while ((l != NULL) && (strcmp(name,l->name) != 0) && (strcmp(Escopo,l->Escopo) != 0)){
        l = l->next;
  }
  if (l == NULL) 
      return "null";
  else 
      return l->typeData;
}

int st_lookup_paramQt(char *name, char *scope){
    int h = hash(name, scope);	
    BucketList l =  hashTable[h];

    while ((l != NULL) && (strcmp(name,l->name) != 0) && (strcmp(scope,l->Escopo) != 0)){
        l = l->next;
    }
  if (l == NULL) 
      return -1;
  else 
      return l->paramQt;
}

void printSymTab(FILE * listing) { 
    int i;
    fprintf(listing,"Location       Name           Escopo         TypeID         TypeData        Param Numb.   Line Numbers  \n");
    fprintf(listing,"-------------  -------------  -------------  -------------  -------------  -------------  -------------  \n");
    for (i=0;i<SIZE;++i) { 
        if (hashTable[i] != NULL) { 
            BucketList l = hashTable[i];
        while (l != NULL) { 
            LineList t = l->lines;
            fprintf(listing,"%-14d ",l->memloc);
            fprintf(listing,"%-13s  ",l->name);
            fprintf(listing,"%-13s  ",l->Escopo);
            fprintf(listing,"%-13s  ",l->typeID);
            fprintf(listing,"%-15s  ",l->typeData);	
            fprintf(listing,"%-11d  ",l->paramQt);
            while (t != NULL) { 
                fprintf(listing,"%4d ",t->lineno);
                t = t->next;
            }
            fprintf(listing,"\n");
            l = l->next;
        }
        }
    }
} 