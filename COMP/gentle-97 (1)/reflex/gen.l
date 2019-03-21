%{
#include "gen.h"
extern YYSTYPE yylval;
extern long yypos;
#define yysetpos() { yylval.attr[0] = yypos; yypos += yyleng; }
%}
%%
