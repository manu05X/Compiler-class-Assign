%{
#include <stdio.h>
#include "y.tab.h"
void yyerror();
int yylex();
extern int linenum,yylval;
int linenum=0;
%}

%%
"if"  {return IF;}
"else" {return ELS;}
"("     { return ob;}
")"     {return cb;}
";"     {return sc;}
"&&"|"||" { return tt;}
[a-z]   {yylval=yytext[0]-'a'; return vb;}
[0-9]+  {yylval= atoi(yytext); return nu;}
"+"|"-"|"*"|"/" {return yytext[0];}
">"|"<"|">="|"=<"|"=="|"!=" {  return op;}
"=" {return ass;}
[ \t] ;
[\n] {linenum++; return NL;}
. ;
%%


