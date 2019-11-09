%{
#include<stdio.h>
%}

%token A B

%%
str:S'\n'{ return 0; }
S:A S|A S B| A A B;
%%
yywrap(){ return 1; }

main(){
	printf("ENTER THE VALUE:\n");
	yyparse();
	printf("VALID STRING\n");
      }
yyerror(char *msg){
	printf("INVALID STRING");
	exit(0);
	return 0;
}

