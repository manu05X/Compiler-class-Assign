%{
#include <stdio.h>
#include <stdlib.h>
int ints=0;
int floats=0;
int strings=0;
%}

digit [0-9]
%%

\+?{digit}+ {printf("%s -> Integer\n",yytext);ints++;}
-{digit}+ {printf("%s -> Integer\n",yytext);ints++;}

\+?{digit}*\.{digit}+ {printf("%s -> Floating point\n",yytext);floats++;}
-{digit}*\.{digit}+ {printf("%s -> Floating point\n",yytext);floats++;}

\" {printf("%s -> String literal\n",yytext);strings++;}
.
%%

int yywrap()
{
    return 1;
}

int main()
{
    extern FILE *yyin;
        yyin=fopen("smple.txt","r");
        yylex();
    printf("\nNumber of integer values : %d\n",ints);
    printf("\nNumber of floating values : %d\n",floats);
    printf("Number of strings : %d\n",strings/2);
 return 0;

}
