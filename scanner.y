%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */

static int yylex(void);
int yyerror(char *message);
%}
// Define all tokens that can be accepted as terminals in the lexical analysis

%token IF ELSE INT RETURN VOID WHILE
%token ID NUM
%token SOM SUB MUL DIV MENOR MENORIGUAL MAIOR MAIORIGUAL IGUALIGUAL
%token DIFERENTE VIRGULA LCHAVE RCHAVE LCOLCHETE RCOLCHETE IGUAL SEMICOL LPAREN RPAREN FIM
%token ERROR

%%

programa            : decl_lista
                        { savedTree = $1; }
                    ;
decl_lista          : decl_lista decl
                        {
                          YYSTYPE t = $1;
            						  if(t != NULL){
            							   while(t -> sibling != NULL){
            							      t = t->sibling;
            							   }
            							   t->sibling = $2;
            							   $$ = $1;
            						  } else {
            							$$ = $2;
            						  }
                      }
                    | decl
                        { $$ = $1; }
                    ;
decl                : var_decl
                        { $$ = $1; }
                    | fun_decl
                        { $$ = $1; }
                    ;
id                  : ID
                        {
                          $$ = newExpNode(idK);
                          $$->attr.name = copyString(tokenString);
                        }
                    ;
var_decl            : tipo id SEMICOL
                        {
                          $$ = $1;
                          $$->child[0] = $2;
                        }
                    | tipo id LCOLCHETE num RCOLCHETE SEMICOL
                        {
                          $$ = $1;
                          $$->child[1] = $2;
              						$2->nodekind = stmtK;
              						$2->kind.stmt = varK;
              						$2->type = voidt;
              						$2->attr.len = $4->attr.val;
                        }
                    ;
tipo                : INT
                        {
                           $$ = newExpNode(typeK);
                           $$->type = integert;
                           $$->attr.name = "integer";
                        }
                    | VOID
                        {
                          $$ = newExpNode(typeK);
                          $$->type = voidt;
                          $$->attr.name = "void";
                        }
                    ;
num                 : NUM
                        {
                          $$ = newExpNode(constK);
                          $$->attr.val = atoi(tokenString);
              						$$->type = integert;
                        }
                    ;
fun_decl            : tipo ID LPAREN params RPAREN composto_decl
                        {
                          $$ = $1;
                          YYSTYPE t = newStmtNode(funcK);
                          t->child[0] = $4;
                          t->child[1] = $6;
                          $$->child[0] = t;
                        }
                    ;
params              : param_lista
                        { $$ = $1; }
                    | VOID
                        {
                          $$ = newExpNode(typeK);
                         	$$->attr.name = "void";
                        }
                    ;
param_lista         : param_lista VIRGULA param
                        {
                          YYSTYPE t = $1;
                          if(t != NULL){
                              while(t->sibling != NULL)
                                  t = t->sibling;
                              t->sibling = $3;
                              $$ = $1;
                          }
                          else $$ = $3;
                        }
                    | param
                        { $$ = $1; }
                    ;
param               : tipo id
                        {
                          $$ = $1;
                          $2->nodekind = stmtK;
                          $2->kind.stmt = paramK;
                          $$->child[0] = $2;
                        }
                    | tipo id LCOLCHETE RCOLCHETE
                        {
                          $$ = $1;
                          $2->nodekind = stmtK;
                          $2->kind.stmt = paramK;
                          $$->child[0] = $2;
                        }
                    ;
composto_decl       : LCHAVE local_decl stmt_lista RCHAVE
                        {
                          YYSTYPE t = $2;
                          if(t != NULL){
              							while(t->sibling != NULL)
                              t = t->sibling;
                            t->sibling = $3;
                            $$ = $2;
                          }
              						else $$ = $3;
                        }
                    | LCHAVE local_decl RCHAVE
                        { $$ = $2; }
                    | LCHAVE stmt_lista RCHAVE
                        { $$ = $2; }
                    | LCHAVE RCHAVE
                        {  }
                    ;
local_decl          : local_decl var_decl
                        {
                          YYSTYPE t = $1;
                          if(t != NULL){
              							while(t->sibling != NULL)
                              t = t->sibling;
                            t->sibling = $1;
                            $$ = $1;
                          }
              						else $$ = $2;
                        }
                    | var_decl
                        { $$ = $1; }
                    ;
stmt_lista          : stmt_lista stmt
                        {
                          YYSTYPE t = $1;
                          if(t != NULL){
              							while(t->sibling != NULL)
                              t = t->sibling;
                            t->sibling = $2;
                            $$ = $1;
                          }
              						else $$ = $2;
                        }
                    | stmt
                        { $$ = $1; }
                    ;
stmt                : expressao_decl
                        { $$ = $1; }
                    | composto_decl
                        { $$ = $1; }
                    | selecao_decl
                        { $$ = $1; }
                    | iteracao_decl
                        { $$ = $1; }
                    | retorno_decl
                        { $$ = $1; }
                    ;
expressao_decl      : expressao SEMICOL
                        { $$ = $1; }
                    | SEMICOL
                        {  }
                    ;
selecao_decl        : IF LPAREN expressao RPAREN stmt
                        {
                          $$ = newStmtNode(ifK);
                          $$->child[0] = $3;
                          $$->child[1] = $5;
                        }
                    | IF LPAREN expressao RPAREN stmt ELSE stmt
                        {
                          $$ = newStmtNode(ifK);
                          $$->child[0] = $3;
                          $$->child[1] = $5;
                          $$->child[2] = $7;
                        }
                    ;
iteracao_decl       : WHILE LPAREN expressao RPAREN stmt
                        {
                          $$ = newStmtNode(whileK);
                          $$->child[0] = $3;
                          $$->child[1] = $5;
                        }
                    ;
retorno_decl        : RETURN SEMICOL
                        {
                          $$ = newStmtNode(returnK);
              						$$->type = voidt;
                        }
                    | RETURN expressao SEMICOL
                        {
                          $$ = newStmtNode(returnK);
              						$$->child[0] = $2;
                        }
                    ;
expressao           : var IGUAL expressao
                        {
                          $$ = newStmtNode(assignK);
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                        }
                    | simples_expressao
                        { $$ = $1; }
                    ;
var                 : id
                        { $$ = $1; }
                    | id LCOLCHETE expressao RCOLCHETE
                        {
                          $$ = $1;
                          $$->child[1] = $3;
                          $$->kind.exp = vectK;
                        }
                    ;
simples_expressao   : soma_expressao relacional soma_expressao
                        {
                          $$ = $2;
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                        }
                    | soma_expressao
                        { $$ = $1; }
                    ;
relacional          : MENORIGUAL
                        {
                          $$ = newExpNode(opK);
                          $$->attr.op = MENORIGUAL;
              						$$->type = booleant;
                        }
                    | MENOR
                        {
                          $$ = newExpNode(opK);
                          $$->attr.op = MENOR;
                          $$->type = booleant;
                        }
                    | MAIOR
                        {
                          $$ = newExpNode(opK);
                          $$->attr.op = MAIOR;
                          $$->type = booleant;
                        }
                    | MAIORIGUAL
                        {
                          $$ = newExpNode(opK);
                          $$->attr.op = MAIORIGUAL;
                          $$->type = booleant;
                        }
                    | IGUALIGUAL
                        {
                          $$ = newExpNode(opK);
                          $$->attr.op = IGUALIGUAL;
                          $$->type = booleant;
                        }
                    | DIFERENTE
                        {
                          $$ = newExpNode(opK);
                          $$->attr.op = DIFERENTE;
                          $$->type = booleant;
                        }
                    ;
soma_expressao      : soma_expressao soma termo
                        {
                          $$ = $2;
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                        }
                    | termo
                        { $$ = $1; }
                    ;
soma                : SOM
                        {
                          $$ = newExpNode(opK);
                          $$->attr.op = SOM;
                        }
                    | SUB
                      {
                        $$ = newExpNode(opK);
                        $$->attr.op = SUB;
                      }
                    ;
termo               : termo mult fator
                      {
                        $$ = $2;
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                      }
                    | fator
                        { $$ = $1; }
                    ;
mult                : MUL
                      {
                        $$ = newExpNode(opK);
                        $$->attr.op = MUL;
                      }
                    | DIV
                        {
                          $$ = newExpNode(opK);
                          $$->attr.op = DIV;
                        }
                    ;
fator               : LPAREN expressao RPAREN
                        { $$ = $2; }
                    | var
                        { $$ = $1; }
                    | ativacao
                        { $$ = $1; }
                    | num
                        { $$ = $1; }
                    ;
ativacao            : id LPAREN arg_lista RPAREN
                        { 
                          $$ = $1;
                          $$->child[0] = $3;
                          $$->nodekind = stmtK;
                          $$->kind.stmt = callK;
                        }
                    | id LPAREN RPAREN
                        {
                          $$ = $1;
                          $$->nodekind = stmtK;
                          $$->kind.stmt = callK;
                        }
                    ;
arg_lista           : arg_lista VIRGULA expressao
                        {
                          YYSTYPE t = $1;
                          if(t != NULL){
              							while(t->sibling != NULL)
                              t = t->sibling;
                            t->sibling = $3;
                            $$ = $1;
                          }
              						else $$ = $3;
                        }
                    | expressao
                        { $$ = $1; }
                    ;
%%

int yyerror(char * message) {
  fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(listing, yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void) {
  return getToken();
}

TreeNode * parse(void) {
  yyparse();
  return savedTree;
}