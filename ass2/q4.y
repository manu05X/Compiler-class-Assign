%{
     #include<stdio.h>
    #include<stdlib.h>
%}

%token IF ELS NL ob cb sc tt vb nu op ass
%left '+' '-'
%left '*' '/'

%%
S: IF cond S | IF cond S ELS S | stats
stats: stat
     | stats stat
     ;
stat: vb ass e sc | ;
cond: ob vb op e cb
    | ob cond tt cond cb
    ;

e: e '+' e
  | e '-' e
  | e '*' e
  | e '/' e { if($3==0) {  printf("Denominator is 0\n"); yyerror();} }
  | ob e cb
  | vb
  | nu
  ;
%%
extern int linenum;
int yywrap()
{
  return(1);
}
int main()
{
   printf("\n enter the arithematic expression:\n");
   yyparse();
   printf("\nvalid expression\n");
return 0;
}
int yyerror()
{
        printf("\n error %d",linenum);
        exit(0);
}


