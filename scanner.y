%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static int savedNumber;
static char * savedName; /* for use in assignments */
static int savedLineNo; 
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *message);
%}

%token IF ELSE INT RETURN VOID WHILE
%token ID NUM
%token SOM SUB MUL DIV MENOR MENORIGUAL MAIOR MAIORIGUAL IGUALIGUAL
%token DIFERENTE VIRGULA LCHAVE RCHAVE LCOLCHETE RCOLCHETE IGUAL SEMICOL LPAREN RPAREN FIM
%token ERROR

%%

programa          : decl_lista 
                    { savedTree = $1; }
                  ;
decl_lista        : decl_lista decl
                    { 
                      YYSTYPE t = $1;
                      if (t != NULL) {
                        while (t->sibling != NULL) { t = t->sibling; }
                        t->sibling = $2;
                        $$ = $1;
                      } else {
                        $$ = $2;
                      }
                    }
                  | decl 
                      { $$ = $1; }
                  ;
decl              : var_decl
                    { $$ = $1; }
                  | fun_decl 
                    { $$ = $1; }
                  ;
id                : ID
                    { savedName = copyString(tokenString);
                      savedLineNo = lineno;
                    }
                  ;
num               : NUM
                    { savedNumber = atoi(tokenString);
                      savedLineNo = lineno;
                    }
                  ;
var_decl          : tipo id SEMICOL
                    { $$ = newDeclNode(varK);
                      $$->child[0] = $1;
                      $$->lineno = lineno;
                      $$->attr.name = savedName;
                    }
                  | tipo id LCOLCHETE num RCOLCHETE SEMICOL
                    { $$ = newDeclNode(vectvarK);
                      $$->child[0] = $1;
                      $$->lineno = lineno;
                      $$->type = VectInt;
                      $$->attr.arr.name = savedName;
                      $$->attr.arr.size = savedNumber;
                    }
                  ;
tipo              : INT
                    { $$ = newExpNode(typeK);
                      $$->type = Integer;
                    }
                  | VOID
                    { $$ = newExpNode(typeK);
                      $$->type = Void;
                    }
                  ;
fun_decl          : tipo id {
                    $$ = newDeclNode(funcK);
                    $$->lineno = lineno;
                    $$->attr.name = savedName;
                  }
                  LPAREN params RPAREN composto_decl
                  { $$ = $3;
                    $$->child[0] = $1;
                    $$->child[1] = $5;
                    $$->child[2] = $7;
                  }
                  ;
params            : param_lista 
                      { $$ = $1; }
                  | VOID
                    { $$ = newDeclNode(paramK);
                      $$->type = Void;
                    }
                  ;
param_lista       : param_lista VIRGULA param
                    { YYSTYPE t = $1;
                      if (t != NULL) {
                        while (t->sibling != NULL) { t = t->sibling; }
                        t->sibling = $3;
                        $$ = $1;
                      } else {
                        $$ = $2;
                      }
                    }
                  | param { $$ = $1; }
                  ;
param             : tipo id
                    { $$ = newDeclNode(paramK);
                      $$->child[0] = $1;
                      $$->attr.name = savedName;
                    }
                  | tipo id LCOLCHETE RCOLCHETE
                    { $$ = newDeclNode(vectparamK);
                      $$->child[0] = $1;
                      $$->attr.name = copyString(savedName);
                    }
                  ;
composto_decl     : LCHAVE local_decl stmt_lista RCHAVE
                    { $$ = newStmtNode(compostoK);
                      $$->child[0] = $2;
                      $$->child[1] = $3;
                    }
                  ;
local_decl        : local_decl var_decl
                    { YYSTYPE t = $1;
                      if (t != NULL) {
                        while (t->sibling != NULL) { t = t->sibling; }
                        t->sibling = $2;
                        $$ = $1;
                      } else {
                        $$ = $2;
                      }
                    }
                  | { $$ = NULL; }
                  ;
stmt_lista        : stmt_lista stmt
                    { YYSTYPE t = $1;
                      if (t != NULL) {
                        while (t->sibling != NULL) { t = t->sibling; }
                      t->sibling = $2;
                      $$ = $1;
                      } else {
                        $$ = $2;
                      }
                    }
                  | { $$ = NULL; }
                  ;
stmt              : expressao_decl { $$ = $1; }
                  | composto_decl { $$ = $1; }
                  | selecao_decl { $$ = $1; }
                  | iteracao_decl { $$ = $1; }
                  | retorno_decl { $$ = $1; }
                  ;
expressao_decl    : expressao SEMICOL { $$ = $1; }
                  | SEMICOL { $$ = NULL; }
                  ;
selecao_decl      : IF LPAREN expressao RPAREN stmt
                    { $$ = newStmtNode(ifK);
                      $$->child[0] = $3;
                      $$->child[1] = $5;
                    }
                  | IF LPAREN expressao RPAREN stmt ELSE stmt
                    { $$ = newStmtNode(ifK);
                      $$->child[0] = $3;
                      $$->child[1] = $5;
                      $$->child[2] = $7;
                    }
                  ;
iteracao_decl     : WHILE LPAREN expressao RPAREN stmt
                    { $$ = newStmtNode(whileK);
                      $$->child[0] = $3;
                      $$->child[1] = $5;
                    }
                  ;
retorno_decl      : RETURN SEMICOL
                    { $$ = newStmtNode(returnK);
                      $$->type = Void;
                    }
                  | RETURN expressao SEMICOL
                    { $$ = newStmtNode(returnK);
                      $$->child[0] = $2;
                    }
                  ;
expressao         : var IGUAL expressao
                    { $$ = newStmtNode(assignK);
                      $$->child[0] = $1;
                      $$->child[1] = $3;
                    }
                  | simples_expressao { $$ = $1; }
                  ;
var               : id
                    { $$ = newExpNode(IdK);
                      $$->attr.name = savedName;
                    }
                  | id {
                      $$ = newExpNode(vectIdK);
                      $$->attr.name = savedName;
                    } LCOLCHETE expressao RCOLCHETE
                    {
                      $$ = $2;
                      $$->child[0] = $4;
                    }
                  ;
simples_expressao : soma_expressao relacional soma_expressao
                    { $$ = newExpNode(calcK);
                      $$->child[0] = $1;
                      $$->child[1] = $2;
                      $$->child[2] = $3;
                    }
                  | soma_expressao { $$ = $1; }
                  ;
relacional        : MENOR
                    { $$ = newExpNode(opK);
                      $$->attr.op = MENOR;
                    }
                  | MENORIGUAL
                    { $$ = newExpNode(opK);
                      $$->attr.op = MENORIGUAL;
                    }
                  | MAIOR
                    { $$ = newExpNode(opK);
                      $$->attr.op = MAIOR;
                    }
                  | MAIORIGUAL
                    { $$ = newExpNode(opK);
                      $$->attr.op = MAIORIGUAL;
                    }
                  | IGUALIGUAL
                    { $$ = newExpNode(opK);
                      $$->attr.op = IGUALIGUAL;
                    }
                  | DIFERENTE
                    { $$ = newExpNode(opK);
                      $$->attr.op = DIFERENTE;
                    }
                  ;
soma_expressao    : soma_expressao soma termo
                    { $$ = newExpNode(calcK);
                      $$->child[0] = $1;
                      $$->child[1] = $2;
                      $$->child[2] = $3;
                    }
                  | termo { $$ = $1; }
                  ;
soma              : SOM
                    { $$ = newExpNode(opK);
                      $$->attr.op = SOM;
                    }
                  | SUB
                    { $$ = newExpNode(opK);
                      $$->attr.op = SUB;
                    }
                  ;
termo             : termo mult fator
                    { $$ = newExpNode(calcK);
                      $$->child[0] = $1;
                      $$->child[1] = $2;
                      $$->child[2] = $3;
                    }
                  | fator { $$ = $1; }
                  ;
mult              : MUL
                    { $$ = newExpNode(opK);
                      $$->attr.op = MUL;
                    }
                  | DIV
                    { $$ = newExpNode(opK);
                      $$->attr.op = DIV;
                    }
                  ;
fator             : LPAREN expressao RPAREN { $$ = $2; }
                  | var { $$ = $1; }
                  | ativacao { $$ = $1; }
                  | num
                    { $$ = newExpNode(ConstK);
                      $$->type = Integer;
                      $$->attr.val = atoi(tokenString);
                    };
                  ;
ativacao          : id {
                      $$ = newExpNode(callK);
                      $$->attr.name = savedName;
                      } LPAREN args RPAREN {
                        $$ = $2;
                        $$->child[0] = $4;
                    }
                  ;
args              : arg_lista { $$ = $1; }
                  | { $$ = NULL; }
                  ;
arg_lista         : arg_lista VIRGULA expressao
                    { YYSTYPE t = $1;
                      if (t != NULL) {
                        while (t->sibling != NULL) { t = t->sibling; }
                        t->sibling = $3;
                        $$ = $1;
                      } else {
                        $$ = $3;
                      }
                    }
                  | expressao { $$ = $1; }
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
