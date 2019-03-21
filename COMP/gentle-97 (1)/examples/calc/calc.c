typedef long * yy;
#define yyu (-2147483647L)
static yy yynull;
extern yy yyh;
extern yy yyhx;
static yyErr(n,l)
{
yyAbort(n,"calc", l);
}
int yyparse_rc = 0;
ROOT()
{
extern char *THIS_RUNTIME_SYSTEM;
char *GENTLE = "Gentle 3.0 01100401 (C) 1992, 1997";
if (strcmp(THIS_RUNTIME_SYSTEM, GENTLE))
{ printf("INCONSISTENT GENTLE RUNTIME SYSTEM\n"); exit(1); }
yyExtend();
yyparse_rc = yyparse();
}
