%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%%
"Which lab" { printf("%s? Welcome to Systems Programming Lab ",yytext);}
"Lab name?" { printf("%s Welcome to Systems Programming Lab ",yytext);}
.
%%

int yywrap()
{
	return 1;
}
int main()
{
	yylex();
	return 0;
}
