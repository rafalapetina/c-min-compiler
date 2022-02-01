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
                          $$->child[0] = $1;
                          $$->child[1] = $2;
                          $2->nodekind = statementK;
              						$2->kind.stmt = varK;
              						$2->type = integert;
              						$2->attr.len = 1;
                        }
                    | tipo id LCOLCHETE num RCOLCHETE SEMICOL
                        {
                          $$->child[0] = $1;
                          $$->child[1] = $2;
              						$2->nodekind = statementK;
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
                          $$ = newExpNode(funcK);
                          $1->child[0] = $4;
                          $1->child[1] = $6;
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
                        {  }
                    | param
                        { $$ = $1; }
                    ;
param               : tipo id
                        {  }
                    | tipo id LCOLCHETE RCOLCHETE
                        {  }
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
                            t->sibling = $1;
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
espressao_decl      : expressao SEMICOL
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
                    | IF LPAREN expressao RPAREN statement ELSE stmt
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
                        {  }
                    | simples_expressao
                        {  }
                    ;
var                 : id
                        {  }
                    | id LCOLCHETE expressao RCOLCHETE
                        {  }
                    ;
simples_expressao   : soma_expressao relacional soma_expressao
                        {  }
                    | soma_expressao
                        {  }
                    ;
relacional          : MENORIGUAL
                        {  }
                    | MENOR
                        {  }
                    | MAIOR
                        {  }
                    | MAIORIGUAL
                        {  }
                    | IGUALIGUAL
                        {  }
                    | DIFERENTE
                        {  }
                    ;
soma_expressao      : soma_expressao soma termo
                        {  }
                    | termo
                        {  }
                    ;
soma                : SOM
                        {  }
                    | SUB
                        {  }
                    ;
termo               : termo mult fator
                        {  }
                    | fator
                        {  }
                    ;
mult                : MUL
                        {  }
                    | DIV
                        {  }
                    ;
fator               : LPAREN expressao RPAREN
                        {  }
                    | var
                        {  }
                    | ativacao
                        {  }
                    | num
                        {  }
                    ;
ativacao            : id LPAREN args RPAREN
                        {  }
                    ;
arg                 : arg_lista VIRGULA expressao
                        {  }
                    | expressao
                        {  }
                    ;

%%

int yyerror(char * message) {
  fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
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
