#include "globals.h"
#include "util.h"

/* Procedure printToken prints a token
 * and its lexeme to the listing file
 */
 void printToken(FILE* file, TokenType token, const char* tokenString) {
   switch (token){
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
       fprintf(file,"Unknown token: %d\n",token);
   }
 }

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmtNode(StmtKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) {
      t->child[i] = NULL;
    }
    t->sibling = NULL;
    t->nodekind = stmtK;
    t->kind.stmt = kind;
    t->lineno = lineno;
    t->attr.scope = "global";
  }
  return t;
}

/* Function newExpNode creates a new expression
 * node for syntax tree construction
 */
TreeNode * newExpNode(ExpKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) {
      t->child[i] = NULL;
    }
    t->sibling = NULL;
    t->nodekind = expK;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = voidt;
    t->attr.scope = "global";
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
static indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{ int i;
  for (i=0;i<indentno;i++)
    fprintf(listing," ");
}

/* procedure printTree prints a syntax tree to the
 * listing file using indentation to indicate subtrees
 */
void printTree( TreeNode * tree ) {
  int i;
  INDENT;
  while (tree != NULL) {
    printSpaces();
    if (tree->nodekind==stmtK){
      switch (tree->kind.stmt) {
        case ifK:     fprintf(synTree,"If\n"); break;
        case whileK:  fprintf(synTree,"While\n"); break;
        case paramK:  fprintf(synTree,"Parametro: %s\n", tree->attr.name); break;
        case assignK: fprintf(synTree,"Atribuição\n"); break;
        case varK:    fprintf(synTree,"Variável: %s\n",tree->attr.name); break;
        case funcK:   fprintf(synTree,"Função %s\n", tree->attr.name); break;
        case callK:   fprintf(synTree,"Chamada de Função: %s \n", tree->attr.name); break;
        case returnK: fprintf(synTree,"Retorno"); break;
        case argK:    fprintf(synTree,"Argumento: %s\n", tree->attr.name); break;
        default:      fprintf(synTree,"Unknown ExpNode kind 1\n"); break;
      }
    }
    else if (tree->nodekind==expK) {
      switch (tree->kind.exp) {
        case opK:
          fprintf(synTree,"Op: ");
          printToken(synTree, tree->attr.op,"\0");
          break;
        case constK:
          fprintf(synTree,"Const: %d\n",tree->attr.val);
          break;
        case idK:
          fprintf(synTree,"Id: %s\n",tree->attr.name);
          break;
        case vectK:
          fprintf(synTree,"Vetor: %s\n",tree->attr.name);
          break;
        case typeK:
          fprintf(synTree,"Type %s\n",tree->attr.name);
          break;
        default:
          fprintf(synTree,"Unknown ExpNode kind 2\n");
          break;
      }
    }
    else fprintf(listing,"Unknown node kind\n");
    for (i=0;i<MAXCHILDREN;i++)
         printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}
