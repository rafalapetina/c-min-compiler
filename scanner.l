%{
#include <stdlib.h>
#include <stdio.h>
#include "globals.h"
#include "util.h"
#include "scan.h"

char tokenString[MAXTOKENLEN+1];
int yywrap ();
%}

NUM [0-9]+
ID [a-zA-Z]+
ELSE else
IF if
INT int
RETURN return
VOID void
WHILE while

%%
"/*" {
	char c;
	while (1){
		c = input();
		if (c == EOF)
			break;
		if (c == '\n')
		lineno++;
		if (c == '*') {
			if(input() == '/')
				break;
		}
	}
}

{ELSE}					{return ELSE;}
{IF}						{return IF;}
{INT}						{return INT;}
{RETURN}				{return RETURN;}
{VOID}					{return VOID;}
{WHILE}					{return WHILE;}
{NUM}						{return NUM;}
{ID}						{return ID;}
"+"							{return SOM;}
"-"							{return SUB;}
"*"							{return MUL;}
"/"							{return DIV;}
"<"							{return MENOR;}
"<="						{return MENORIGUAL;}
">"							{return MAIOR;}
">="						{return MAIORIGUAL;}
"=="						{return IGUALIGUAL;}
"!="						{return DIFERENTE;}
","							{return VIRGULA;}
"{"							{return LCHAVE;}
"}"							{return RCHAVE;}
"["							{return LCOLCHETE;}
"]"							{return RCOLCHETE;}
"="							{return IGUAL;}
";"							{return SEMICOL;}
"("							{return LPAREN;}
")"							{return RPAREN;}
"\n"            lineno++;
[ \t]+					{}//skip whitespace
.								return ERROR;

%%

int yywrap () {  };

TokenType getToken(void) {
	static int firstTime = TRUE;
	TokenType currentToken;
	if (firstTime) {
			firstTime = FALSE;
		lineno++;
		yyin = source;
		yyout = listing;
	}
	currentToken = yylex();
	strncpy(tokenString,yytext,MAXTOKENLEN);
	if (TraceScan) {
		fprintf(listing,"\t%d: ",lineno);
			printToken(tokenList, currentToken,tokenString);
	}
		if (currentToken == ERROR) {
			printf("\nERRO LÉXICO. Linha: %d, ", lineno);
			printToken(listing, currentToken,tokenString);
			Error = TRUE;
		}
	return currentToken;
}