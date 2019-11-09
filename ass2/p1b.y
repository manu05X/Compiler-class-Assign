%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%token A B C

%%
str: S'\n'  { return 0; }

S: A S C | T
;

T: B T | B
;
%%

int yywrap() { return 1; }

int main() {
    printf("Enter input string: ");
    yyparse();
    printf("\nValid string!\n");
}

int yyerror(char *msg) {
    printf("\nInvalid string!\n");
    exit(0);
    return 0;
}
