%{
    #include<stdio.h>
    #include<stdlib.h>
   int sym[26]={0};
   int flag[26]={0};
%}
%token wh NL begin  ed ob cb  sc tt vb nu op ass
%left '+' '-'
%left '*' '/'
%%
S: wh  cond  begin stats ed  {printf("correct\n");}
stats: stat
     | stats stat
     ;
stat: vb ass e sc  { flag[$1]=1; sym[$1]=$3; printf("value of variable %c is : %d \n",(char)($1+'a'),$3);}
    |S
    ;
cond: ob vb op e cb
    | ob cond tt cond cb
    ;
e: e '+' e {$$ = $1+$3;}
  | e '-' e { $$=$1-$3;}
  | e '*' e {$$=$1*$3;}
  | e '/' e { if($3==0) {  printf("denominator is 0\n"); yyerror();} $$=$1/$3; }
  | ob e cb { $$=$2;}
  | vb { if(flag[$1]==0) printf("value of variable %c is unassigned so default value : 0\n",(char)($1+'a'));$$=sym[$1];}
  | nu {$$=$1;}
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
        printf("error %d",linenum);
        exit(0);
}
