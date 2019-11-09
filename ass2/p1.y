%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token A B C

%%

str:S'\n' { return 0; }

S: A T | T
;

T: B T C | B C 
;

%%

int yywrap() { return 1; }

int main() {
	printf("Enter the string: ");
	yyparse();
	printf("\nValid string!\n");
	return 0;
}

int yyerror(char *msg) {
	printf("Invalid string!\n");
	exit(0);
	return 0;
}


