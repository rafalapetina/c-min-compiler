#include "globals.h"
#include "util.h"

/* Procedure printToken prints a token
 * and its lexeme to the listing file
 */
 void printToken(FILE* file, TokenType token, const char* tokenString ) { 
   switch (token) { 
      case IF:            fprintf(file, "Palavra reservada: IF, Lexema: %s\n",tokenString); break;
      case ELSE:          fprintf(file, "Palavra reservada: ELSE, Lexema: %s\n",tokenString); break;
      case RETURN:        fprintf(file, "Palavra reservada: RETURN, Lexema: %s\n",tokenString); break;
      case INT:		        fprintf(file, "Palavra reservada: INT, Lexema: %s\n",tokenString); break;
      case VOID:	        fprintf(file, "Palavra reservada: VOID, Lexema: %s\n",tokenString); break;
      case WHILE:         fprintf(file, "Palavra reservada: WHILE, Lexema: %s\n",tokenString); break;
      case IGUAL:         fprintf(file, "=\n"); break;
      case SEMICOL:       fprintf(file, ";\n"); break;
      case LPAREN:        fprintf(file, "(\n"); break;
      case RPAREN:        fprintf(file, ")\n"); break;
      case MENOR:         fprintf(file, "<\n"); break;
      case MENORIGUAL:    fprintf(file, "<=\n"); break;
      case MAIOR:         fprintf(file, ">\n"); break;
      case MAIORIGUAL:    fprintf(file, ">=\n"); break;
      case IGUALIGUAL:    fprintf(file, "==\n"); break;
      case DIFERENTE:     fprintf(file, "!=\n"); break;
      case VIRGULA:       fprintf(file, ",\n"); break;
      case LCOLCHETE:     fprintf(file, "[\n"); break;
      case RCOLCHETE:     fprintf(file, "]\n"); break;
      case LCHAVE:        fprintf(file, "{\n"); break;
      case RCHAVE:        fprintf(file, "}\n"); break;
      case SOM:           fprintf(file, "+\n"); break;
      case SUB:           fprintf(file, "-\n"); break;
      case MUL:           fprintf(file, "*\n"); break;
      case DIV:           fprintf(file, "/\n"); break;
      case FIM:           fprintf(file, "EOF\n"); break;
      case NUM:           fprintf(file, "NUM, val= %s\n",tokenString); break;
      case ID:            fprintf(file, "ID, name= %s\n",tokenString); break;
      case ERROR:           fprintf(file, "Lexema: %s\n",tokenString); break;
     default: /* should never happen */
       fprintf(listing,"Unknown token: %d\n",token);
   }
 }

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmtNode(stmtKind kind) {
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL) fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = stmtK;
    t->kind.stmt = kind;
    t->lineno = lineno;
  }
  return t;
}

/* Function newExpNode creates a new expression
 * node for syntax tree construction
 */
TreeNode * newExpNode(expKind kind) {
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL) fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = expK;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = Void;
  }
  return t;
}

/* Function newDeclNode creates a new declaration
 * node for syntax tree construction
 */
TreeNode * newDeclNode(declKind kind) {
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = declK;
    t->kind.decl = kind;
    t->lineno = lineno;
    t->type = Void;
  }
  return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(char * s)
{ int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = malloc(n);
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else strcpy(t,s);
  return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void) {
  int i;
  for (i=0;i<indentno;i++)
    fprintf(synTree," ");
}

void printTypes(TreeNode* tree) {
  if (tree->child[0] != NULL) {
    switch (tree->child[0]->type) {
      case Void:
        fprintf(synTree,"void");
        break;
      case Integer:
        fprintf(synTree,"int");
        break;
      case VectInt:
        fprintf(synTree,"int array");
        break;
      default: return;
    }
  } else {
    switch (tree->type) {
      case Void:
        fprintf(synTree,"void");
        break;
      case Integer:
        fprintf(synTree,"int");
        break;
      case VectInt:
        fprintf(synTree,"int array");
        break;
      default: return;
    }
  }
}

/* procedure printTree prints a syntax tree to the
 * synTree file using indentation to indicate subtrees
 */
void printTree( TreeNode * tree )
{ int i;
  INDENT;
  while (tree != NULL) {
    if (tree->nodekind==stmtK) {
      printSpaces();
      switch (tree->kind.stmt) {
        case ifK:
          fprintf(synTree,"If\n");
          break;
        case whileK:
          fprintf(synTree, "While\n");
          break;
        case compostoK:
          fprintf(synTree, "Composto declaracao\n");
          break;
        case returnK:
          fprintf(synTree, "Return\n");
          break;
        case assignK:
          fprintf(synTree, "Assign\n");
          break;
        default:
          fprintf(synTree, "Unknown stmtNode kind\n");
          break;
        }
    }
    else if (tree->nodekind==expK) {
      if (tree->kind.exp != typeK) printSpaces();
      switch (tree->kind.exp) {
        case opK:
          fprintf(synTree,"Op: ");
          printToken(synTree, tree->attr.op, "\0");
          break;
        case ConstK:
          fprintf(synTree,"Const: %d\n",tree->attr.val);
          break;
        case IdK:
          fprintf(synTree,"Id: %s\n",tree->attr.name);
          break;
        case typeK: break;
        case vectIdK:
          fprintf(synTree,"Id vetor \n");
          break;
        case callK:
          fprintf(synTree, "Chamada Função: %s\n", tree->attr.name);
          break;
        case calcK:
          fprintf(synTree, "Operador: ");
          printToken(synTree, tree->child[1]->attr.op, "\0");
          break;
        default:
          fprintf(synTree,"Unknown Node kind\n");
          break;
      }
    }
    else if (tree->nodekind==declK) {
      printSpaces();
      switch (tree->kind.decl) {
        case varK :
          fprintf(synTree, "Declaração Variável: ");
          printTypes(tree);
          fprintf(synTree, " %s;\n", tree->attr.name);
          break;
        case vectvarK :
          fprintf(synTree, "Declaração Vetor: ");
          printTypes(tree);
          fprintf(synTree," %s[%d];\n", tree->attr.arr.name, tree->attr.arr.size);
          break;
        case funcK :
          fprintf(synTree, "Declaração Função: ");
          printTypes(tree);
          fprintf(synTree, " %s()\n", tree->attr.name);
          break;
        case paramK :
          fprintf(synTree, "Parametro: ");
          printTypes(tree);
          if (tree->attr.name != NULL) {
            fprintf(synTree, " %s\n", tree->attr.name);
          } else {
            fprintf(synTree, " void\n");
          }
          break;
        case vectparamK :
          fprintf(synTree, "Vetor Parametro: %s\n", tree->attr.name);
          break;
        default:
          fprintf(synTree, "Unknown Declaration\n");
          break;
        }
      }
    else fprintf(synTree,"Unknown node kind\n");
    for (i=0;i<MAXCHILDREN;i++) if (tree->child[i] != NULL) printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}
