%{
#include<stdio.h>
extern int lineno;
%}

%token NUM NL
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
S:S E NL {printf("value:%d\n",$2);}
  | E NL {printf("value:%d\n",$1);}
  ;

E:E '+' E {$$=$1+$3;}
  | E '-' E {$$=$1-$3;}
  | E '*' E {$$=$1*$3;}
  | E '/' E {$$=$1/$3;}
  | '(' E ')' {$$=$2;}
  | '-' E    {$$=-$2;}
  | NUM       {$$=$1;};
%%

yywrap() {return 1;}

main(){
	yyparse();
}

int yyerror(char *msg){
	printf("INVALID EXPRESSION AT LINE NUMBER %d\n",lineno);
	exit(0);
}

