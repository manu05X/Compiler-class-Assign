%{
#include<stdio.h> 
%}

%% 
   
\/\/(.*) {}                     
 
\/\*(.*\n)*.*\*\/  {}     
          
%%
int yywrap(){return 1;} 
   
int main() 
{
yyin=fopen("sample.c","r");
yylex(); 

return 0; 
} 
