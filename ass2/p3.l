%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
int lineno=0;
%}
digit [0-9]
%%
{digit}+ {yylval = atoi (yytext); return NUM; };
[\t];
[\n] {lineno++; return NL;};
. return yytext[0];
%%

