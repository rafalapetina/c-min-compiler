#include "globals.h"
#include "util.h"
#include "parse.h"
#include "scan.h"
#include "symtab.h"
#include "analyze.h"

/* set NO_PARSE to TRUE to get a scanner-only compiler */
#define NO_PARSE FALSE
/* set NO_ANALYZE to TRUE to get a parser-only compiler */
#define NO_ANALYZE FALSE

/* set NO_CODE to TRUE to get a compiler that does not
 * generate code
 */
#define NO_CODE FALSE

/* allocate global variables */
int lineno = 0;
FILE *source;
FILE *listing;
FILE *tokenList;
FILE *symTab;
FILE *synTree;

/* allocate and set tracing flags */
int EchoSource = FALSE;
int TraceScan = TRUE;
int TraceParse = TRUE;
int TraceAnalyze = FALSE;
int TraceCode = FALSE;

int Error = FALSE;

int main( int argc, char * argv[]) { 
  TreeNode * syntaxTree;
  char pgm[120]; /* source code file name */
  if (argc != 2) {
      fprintf(stderr,"usage: %s <filename>\n",argv[0]);
      exit(1);
    }
  strcpy(pgm,argv[1]);

  source = fopen(pgm,"r");

  if (source==NULL) {
    fprintf(stderr,"File %s not found\n",pgm);
    exit(1);
  }
  listing = stdout; /* send listing to screen */
  tokenList = fopen("./outputs/tokenList.txt","w");
  symTab = fopen("./outputs/symbolTable.txt","w");
  synTree = fopen("./outputs/syntaxTree.txt","w"); 

  fprintf(listing,"C- COMPILATION: %s\n",pgm);

#if NO_PARSE
  while (getToken()!=ENDFILE);
#else
  syntaxTree = parse(); //scanner.y
  if (TraceParse) {
    printf("entrou PRINT");
    fprintf(listing,"\nSyntax tree:\n");
    printTree(syntaxTree);  //util.c
  }
// #if !NO_ANALYZE
//   if (! Error) {
//     if (TraceAnalyze) {
//       fprintf(listing,"\nBuilding Symbol Table...\n");
//     }
//     buildSymtab(syntaxTree);  //analyze.c
//     if (TraceAnalyze) {
//       fprintf(listing,"\nChecking Types...\n");
//     }
//     typeCheck(syntaxTree);  //analyze.c
//     if (TraceAnalyze) {
//       fprintf(listing,"\nType Checking Finished\n");
//     }
//   }
// #if !NO_CODE
//   if (! Error)
//   { char * codefile;
//     int fnlen = strcspn(pgm,".");
//     codefile = (char *) calloc(fnlen+4, sizeof(char));
//     strncpy(codefile,pgm,fnlen);
//     strcat(codefile,".tm");
//     code = fopen(codefile,"w");
//     if (code == NULL)
//     { printf("Unable to open %s\n",codefile);
//       exit(1);
//     }
//     // codeGen(syntaxTree,codefile);
//     fclose(code);
//   }
// #endif
// #endif
#endif
  fclose(source);
  fclose(tokenList);
  fclose(symTab);
  fclose(synTree);
  return 0;
}
