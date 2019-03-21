%{
typedef long * yy;
#define yyu (-2147483647L)
static yy yynull;
extern yy yyh;
extern yy yyhx;
static yyErr(n,l)
{
yyAbort(n,"calc", l);
}
/* start */
/* end */
typedef struct {long attr[2];} yyATTRIBUTES;
#define YYSTYPE yyATTRIBUTES
extern YYSTYPE yylval;

%}
%start ROOT_
%token Number 257
%token yytk_RPAREN 258
%token yytk_LPAREN 259
%token yytk_SLASH 260
%token yytk_ASTERISK 261
%token yytk_MINUS 262
%token yytk_PLUS 263
%%
ROOT_:
   expression

{
yy yyb;
yy yyv_X;
yy yy_1_1;
yy yy_2_1;
yy_1_1 = (yy)($1.attr[1]);
yyv_X = yy_1_1;
yy_2_1 = yyv_X;
yyPrint_INT(yy_2_1);
yyEndPrint();
$$.attr[0] = $1.attr[0];
}
;
expression:
   expr2

{
yy yyb;
yy yy_0_1;
yy yyv_X;
yy yy_1_1;
yy_1_1 = (yy)($1.attr[1]);
yyv_X = yy_1_1;
yy_0_1 = yyv_X;
$$.attr[1] = ((long)yy_0_1);
$$.attr[0] = $1.attr[0];
}
;
expression:
   expression
   yytk_PLUS
   expr2

{
yy yyb;
yy yy_0_1;
yy yy_0_1_1;
yy yy_0_1_2;
yy yyv_X;
yy yy_1_1;
yy yyv_Y;
yy yy_3_1;
yy_1_1 = (yy)($1.attr[1]);
yy_3_1 = (yy)($3.attr[1]);
yyv_X = yy_1_1;
yyv_Y = yy_3_1;
yy_0_1_1 = yyv_X;
yy_0_1_2 = yyv_Y;
yy_0_1 = (yy)(((long)yy_0_1_1)+((long)yy_0_1_2));
$$.attr[1] = ((long)yy_0_1);
$$.attr[0] = $2.attr[0];
}
;
expression:
   expression
   yytk_MINUS
   expr2

{
yy yyb;
yy yy_0_1;
yy yy_0_1_1;
yy yy_0_1_2;
yy yyv_X;
yy yy_1_1;
yy yyv_Y;
yy yy_3_1;
yy_1_1 = (yy)($1.attr[1]);
yy_3_1 = (yy)($3.attr[1]);
yyv_X = yy_1_1;
yyv_Y = yy_3_1;
yy_0_1_1 = yyv_X;
yy_0_1_2 = yyv_Y;
yy_0_1 = (yy)(((long)yy_0_1_1)-((long)yy_0_1_2));
$$.attr[1] = ((long)yy_0_1);
$$.attr[0] = $2.attr[0];
}
;
expr2:
   expr3

{
yy yyb;
yy yy_0_1;
yy yyv_X;
yy yy_1_1;
yy_1_1 = (yy)($1.attr[1]);
yyv_X = yy_1_1;
yy_0_1 = yyv_X;
$$.attr[1] = ((long)yy_0_1);
$$.attr[0] = $1.attr[0];
}
;
expr2:
   expr2
   yytk_ASTERISK
   expr3

{
yy yyb;
yy yy_0_1;
yy yy_0_1_1;
yy yy_0_1_2;
yy yyv_X;
yy yy_1_1;
yy yyv_Y;
yy yy_3_1;
yy_1_1 = (yy)($1.attr[1]);
yy_3_1 = (yy)($3.attr[1]);
yyv_X = yy_1_1;
yyv_Y = yy_3_1;
yy_0_1_1 = yyv_X;
yy_0_1_2 = yyv_Y;
yy_0_1 = (yy)(((long)yy_0_1_1)*((long)yy_0_1_2));
$$.attr[1] = ((long)yy_0_1);
$$.attr[0] = $2.attr[0];
}
;
expr2:
   expr2
   yytk_SLASH
   expr3

{
yy yyb;
yy yy_0_1;
yy yy_0_1_1;
yy yy_0_1_2;
yy yyv_X;
yy yy_1_1;
yy yyv_Y;
yy yy_3_1;
yy_1_1 = (yy)($1.attr[1]);
yy_3_1 = (yy)($3.attr[1]);
yyv_X = yy_1_1;
yyv_Y = yy_3_1;
yy_0_1_1 = yyv_X;
yy_0_1_2 = yyv_Y;
yy_0_1 = (yy)(((long)yy_0_1_1)/((long)yy_0_1_2));
$$.attr[1] = ((long)yy_0_1);
$$.attr[0] = $2.attr[0];
}
;
expr3:
   Number

{
yy yyb;
yy yy_0_1;
yy yyv_X;
yy yy_1_1;
yy_1_1 = (yy)($1.attr[1]);
yyv_X = yy_1_1;
yy_0_1 = yyv_X;
$$.attr[1] = ((long)yy_0_1);
$$.attr[0] = $1.attr[0];
}
;
expr3:
   yytk_MINUS
   expr3

{
yy yyb;
yy yy_0_1;
yy yy_0_1_1;
yy yyv_X;
yy yy_2_1;
yy_2_1 = (yy)($2.attr[1]);
yyv_X = yy_2_1;
yy_0_1_1 = yyv_X;
yy_0_1 = (yy)(-((long)yy_0_1_1));
$$.attr[1] = ((long)yy_0_1);
$$.attr[0] = $1.attr[0];
}
;
expr3:
   yytk_PLUS
   expr3

{
yy yyb;
yy yy_0_1;
yy yy_0_1_1;
yy yyv_X;
yy yy_2_1;
yy_2_1 = (yy)($2.attr[1]);
yyv_X = yy_2_1;
yy_0_1_1 = yyv_X;
yy_0_1 = (yy)(((long)yy_0_1_1));
$$.attr[1] = ((long)yy_0_1);
$$.attr[0] = $1.attr[0];
}
;
expr3:
   yytk_LPAREN
   expression
   yytk_RPAREN

{
yy yyb;
yy yy_0_1;
yy yyv_X;
yy yy_2_1;
yy_2_1 = (yy)($2.attr[1]);
yyv_X = yy_2_1;
yy_0_1 = yyv_X;
$$.attr[1] = ((long)yy_0_1);
$$.attr[0] = $1.attr[0];
}
;
