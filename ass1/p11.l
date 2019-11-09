%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[]={0,0,0,0,0,0,0};
char* str[]={"int","float","double","char","void","long int","long long int"};
%}


%%
"int" { if(arr[0]==0){ arr[0]++; printf("%s -> Integer data type\n",yytext); } else { printf("ERROR: %s Already present\n",yytext); } }
"float" { if(arr[1]==0){ arr[1]++; printf("%s -> Floating point data type\n",yytext); } else { printf("ERROR: %s Already present\n",yytext); } } 
"double" { if(arr[2]==0){ arr[2]++; printf("%s -> Double data type\n",yytext); } else { printf("ERROR: %s Already present\n",yytext); } } 
"char" { if(arr[3]==0){ arr[3]++; printf("%s -> Character data type\n",yytext); } else { printf("ERROR: %s Already present\n",yytext); } } 
"void" { if(arr[4]==0){ arr[4]++; printf("%s -> Void data type\n",yytext); } else { printf("ERROR: %s Already present\n",yytext); } }
"long"[[:space:]]+"int" { if(arr[5]==0){ arr[5]++; printf("%s -> Long Integer data type\n",yytext); } else { printf("ERROR: %s Already present\n",yytext); } }
"long"[[:space:]]+"long"[[:space:]]+"int" { if(arr[6]==0){ arr[6]++; printf("%s -> Long Long Integer data type\n",yytext); } else { printf("ERROR: %s Already present\n",yytext); } }
.
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
	int i;
	printf("\nList of data types present\n");
	for(i=0;i<7;i++)
	{
		if(arr[i]==1)
		printf("%s\n",str[i]);
	}
	return 0;
}
