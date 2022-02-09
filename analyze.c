#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include "util.h"

typedef int bool;
#define true 1
#define false 0

/*
 * Insere input()
 * Cria um TreeNode do tipo fun_decl
 */
static void insertInputFunc(void) {
  TreeNode * fun_decl = newDeclNode(funcK);
  fun_decl->type = Integer;

  TreeNode * tipo = newExpNode(typeK);
  tipo->attr.type = INT;

  TreeNode * composto_stmt = newStmtNode(compostoK);
  composto_stmt->child[0] = NULL;
  composto_stmt->child[1] = NULL;

  fun_decl->lineno = 0;
  fun_decl->attr.name = "input";
  fun_decl->child[0] = tipo;
  fun_decl->child[1] = NULL;
  fun_decl->child[2] = composto_stmt;

  /* Insert input function*/
  st_insert("global", "input", Integer, fun_decl, 1);
}

/*
 * Insere output()
 * Cria um TreeNode do tipo fun_decl
 */
static void insertOutputFunc(void) {

  TreeNode * fun_decl = newDeclNode(funcK);
  fun_decl->type = Void;

  TreeNode * tipo = newDeclNode(funcK);
  tipo->attr.type = VOID;

  TreeNode * params = newDeclNode(paramK);
  params->attr.name = "arg";
  params->child[0] = newExpNode(typeK);
  params->child[0]->attr.type = INT;

  TreeNode * composto_stmt = newStmtNode(compostoK);
  composto_stmt->child[0] = NULL;
  composto_stmt->child[1] = NULL;

  fun_decl->lineno = 0;
  fun_decl->attr.name = "output";
  fun_decl->child[0] = tipo;
  fun_decl->child[1] = params;
  fun_decl->child[2] = composto_stmt;

  /* Insert output function*/
  st_insert("global", "output", Void, fun_decl, 0);
}

/* Procedure traverse is a generic recursive
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc
 * in postorder to tree pointed to by t
 */
static void traverse(TreeNode * t, void (* preProc) (TreeNode *), void (* postProc) (TreeNode *)) {
  if (t != NULL) {
    preProc(t);
    for (int i=0; i < MAXCHILDREN; i++) {
      traverse(t->child[i], preProc, postProc);
    }
    postProc(t);
    traverse(t->sibling, preProc, postProc);
  }
}

/* nullProc is a do-nothing procedure to
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t) {
  if (t==NULL) return;
  else return;
}

static void symbolError(TreeNode * t, char * message) {
  fprintf(listing,"Symbol Table error at line %d: %s\n", t->lineno, message);
  Error = TRUE;
  exit(-1);
}

// this is needed to check parameters
static bool isFirstcompostoK = false;
static int locationCounter = 0;

/* Procedure insertNode inserts
 * identifiers stored in t into
 * the symbol table
 */
static void insertNode(TreeNode * t) {
  switch (t->nodekind) {
    case expK: {
      switch (t->kind.exp){
        case IdK:
        case vectIdK:
        case callK: {
          if (st_lookup_all_scope(t->attr.name) == NULL){
            symbolError(t, "Undefined Symbol");
          } else {
            BucketList list = st_lookup_all_scope(t->attr.name);
            t->type = list->type;
            insertLines(t->attr.name, t->lineno);
          }
        }
        default:
          break;
      }
      break;
    }
    case stmtK: {
      switch (t->kind.stmt) {
        case compostoK: {
          if (!isFirstcompostoK) {
            Scope escopo = newScope(getScope()->name);
            escopo->parent = getScope();
            pushScope(escopo);
          }
          isFirstcompostoK = false;
          break;
        }
        default:
          break;
      }
      break;
    }
    case declK: {
      switch (t->kind.decl) {
        case funcK: {
          // initialize location counter
          locationCounter = 0;
          if (st_lookup_scope(t->attr.name) != NULL) {
            symbolError(t, "Redefinition of function");
            break;
          }
          if (strcmp(getScope()->name, "global") == 0) {
            st_insert(getScope()->name, t->attr.name, t->child[0]->type, t, locationCounter++);
          }
          Scope escopo = newScope(t->attr.name);
          escopo->parent = getScope();
          pushScope(escopo);
          isFirstcompostoK = true;
          break;
        }
        case varK: {
          if (st_lookup(t->attr.name) != NULL) {
            symbolError(t, "Redefinition of variable");
            break;
          }
          if (t->child[0]->type == Void) {
            symbolError(t, "Variable should not be void type.");
            break;
          }
          st_insert(getScope()->name, t->attr.name, t->child[0]->type, t, locationCounter++);
          break;
        }
        case vectvarK: {
          if (t->child[0]->type == Void) {
            symbolError(t, "Redefinition of Array variable");
            break;
          }
          if (st_lookup(t->attr.arr.name) != NULL) {
            symbolError(t, "Array Variable has already declared.");
            break;
          }
          st_insert(getScope()->name, t->attr.arr.name, t->child[0]->type, t, locationCounter++);
          break;
        }
        case vectparamK: {
          if (t->child[0]->type == Void) {
            symbolError(t, "Array Parameter should not be void type.");
            break;
          }
          if (st_lookup(t->attr.name) != NULL) {
            symbolError(t, "Redefinition of Array Parameter");
            break;
          }
          st_insert(getScope()->name, t->attr.name, t->child[0]->type, t, locationCounter++);
          break;
        }
        case paramK: {
          if (t->attr.name != NULL) {
            /*  Look up to check parameter existence  */
            if (st_lookup(t->attr.name) != NULL) {
              symbolError(t, "Redefinition of Parameter");
              break;
            }
            st_insert(getScope()->name, t->attr.name, t->child[0]->type, t, locationCounter++);
          }
          break;
        }
        default:
          break;
      }
      break;
    }
    default:
      break;
   }
 }

static void typeError(TreeNode * t, char * message) {
  fprintf(listing,"Type error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
  exit(-1);
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t) {
  switch (t->nodekind) {
    case stmtK:
      switch (t->kind.stmt) {
        case assignK: {
          // Verify the type match of two operands when assigning.
          if (t->child[0]->attr.arr.type == VectInt) {
            typeError(t->child[0], "Assignment to Integer Array Variable");
          }

          if (t->child[0]->attr.type == Void) {
            typeError(t->child[0], "Assignment to Void Variable");
          }
          break;
        }
        case returnK: {
          const TreeNode * funcDecl;
          const ExpType funcType = funcDecl->type;
          const TreeNode * expr = t->child[0];

          if (funcType == Void && (expr != NULL && expr->type != Void)) {
             typeError(t,"expected no return value");
           } else if (funcType == Integer && (expr == NULL || expr->type == Void)) {
             typeError(t,"expected return value");
           }
        }
        default:
          break;
       }
       break;
     default:
       break;
   }
}

/* Procedure typeCheck performs type checking
* by a postorder syntax tree traversal
*/
void typeCheck(TreeNode * syntaxTree) {
  traverse(syntaxTree, nullProc, checkNode);
}

/* Function buildSymtab constructs the symbol
* table by preorder traversal of the syntax tree
*/
void buildSymtab(TreeNode * syntaxTree) {
  globalScope = newScope("global");
  // push global scope
  pushScope(globalScope);

  insertInputFunc();
  insertOutputFunc();

  traverse(syntaxTree, insertNode, nullProc);
  if (TraceAnalyze) {
    printSymTab(symTab);
  }
}
