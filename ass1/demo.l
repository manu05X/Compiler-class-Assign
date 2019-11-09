%{
#include<stdio.h>
int count=0;
%}
line.*\n
%%
{line} { printf("%10d %s",count++,yytext);}
%%
int yywrap()
{
return 1;
}
main()
{
 extern FILE *yyin;
 yyin=fopen("smple.txt","r");
 yylex();

}

