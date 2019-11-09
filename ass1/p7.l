%{
#include <stdio.h>
%}

%%
[+-/=*%] {ECHO;printf(" -> Operator\n");}
.|\n;
%%

int yywrap()
{
	return 1;
}

int main()
{
	extern FILE *yyin;
	yyin=fopen("sample.c","r");
	yylex();
	return 0;
}
