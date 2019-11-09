%{ 
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #define YYSTYPE char*
    int yylex(); 
    int yyerror();
     char *getType(char *); 
    extern char* yytext;
    char types[20][20];
    int pos=0;
    char temp[20], newTemp[20];
    char threeAdd[100][4][10], threeType[100][4][10];
    int idx=0;
    char op[16], op1[16], op2[16];
    char struct_name[20];

    /*Node for symbol table*/
    struct node
    {
        char var[20];
        char type[5];
        struct node* next;
    } ;
    
    typedef struct node Node;
    Node *start=NULL, *end=NULL;
    /*Add a variable to symbol table*/
    void put(char *str, char *t)
    {

        if(getType(str)!=NULL)
        {
            printf("Error: variable \'%s\' already declared\n",str);
            exit(0);
        }
        Node *newNode=(Node *)malloc(sizeof(Node));
        strcpy(newNode->var,str);
        strcpy(newNode->type, t);
        newNode->next=NULL;
        
        if(start==NULL)
        {
            start=newNode;
            end=start;
        }
        else 
        {
            end->next=newNode;
            end=newNode;
        }
        
    }
    
    char *getType(char *str)
    {
        Node *ptr=start;
        while(ptr!=NULL )
        {
            if(strcmp(ptr->var,str)==0)
            return ptr->type;

            ptr=ptr->next;
        }
        return NULL;

    }

    typedef struct 
    {
        char mat[20][20];
        int top;
    } stack;
    
    stack *stk;
    stack *type;
    void push(stack *s, char *str)
    {
        
        strcpy(s->mat[++s->top],str);

    }
    char* pop(stack *s)
    {
        return s->mat[s->top--];
    }
    void constr()
    {
        stk=(stack *)malloc(sizeof(stack));
        stk->top=-1;
        type=(stack *)malloc(sizeof(stack));
        type->top=-1;
    }
    
    int search(char *str)
    {
        int i;
        for(i=0;i<pos;i++)
        {
            if(strcmp(str,types[i])==0)
            return 1;
        }
        return -1;
    }

    char* add(char *op, char *str1, char *str2)
    {
        char *t=(char *)malloc(sizeof(char)*20);
        char  *result=(char *)malloc(sizeof(char)*20);
        strcpy(t,"t");
        
        sprintf(result,"%d",idx);
        strcat(t,result);
        strcpy(threeAdd[idx][0],op);
        
        strcpy(threeAdd[idx][1],str1);

        if(getType(str1)==NULL)
        {
            printf("Error: variable \'%s\' not declared\n",str1);
            exit(0);
        }
        strcpy(threeType[idx][1],getType(str1));
        if(strcmp(op,"=")==0)
        {
            strcpy(threeAdd[idx][3],str2);
            if(getType(str2)==NULL)
        {
            printf("Error: variable \'%s\' not declared\n",str2);
            exit(0);
        }
        strcpy(threeType[idx][3],getType(str2));
        }
        else
        {
        strcpy(threeAdd[idx][2],str2);
            if(getType(str2)==NULL)
        {
            printf("Error: variable \'%s\' not declared\n",str2);
            exit(0);
        }
        strcpy(threeType[idx][2],getType(str2));
        strcpy(threeAdd[idx][3],t);
       
        if((strcmp(threeType[idx][1],"float")==0 ) || (strcmp(threeType[idx][2],"float")==0 ) )
        {
            strcpy(threeType[idx][3],"float");
            put(t,"float");
           
        }
        else{
            strcpy(threeType[idx][3],"int");
            put(t,"int");
        }
        }
        idx++;
        
        
        return t;
    }
    

    
%}
%left '+' '-'
%left '*' '/'
%token INT CHAR FLOAT ID FNUM INUM STRUCT OB CB
%%
START: S { return 0; }
S: T V { 
    while(stk->top>=0)
    {
        put(pop(stk), type->mat[type->top]);
    }
    pop(type);
 } ST
 | STMT ST
 | STR ST
;

ST: S ST 
 |
 ;
T: INT  { push(type,"int"); }
 | CHAR {  push(type,"char");}
 | FLOAT { push(type,"float"); }
 |  ID { if(search(($1))==1) { push(type, ($1));} else { printf("ERROR: No such type available: %s\n",$1); exit(0); } }
;
V:   ID { push(stk, $1); } EN 
;
EN: ',' V
 | OB INUM CB ';' {  put(pop(stk), "array"); strcpy(types[pos++],"array"); pop(type); }
| ';'
;
STMT: ID '=' E ';' { add("=", $3, $1 ); }
 
;
STR: STRUCT ID { strcpy(types[pos++],yytext); strcpy(struct_name,yytext); }'{'  T VI DCL '}' ';'
;
DCL: T  VI DCL
 | 
;

VI:   ID { strcpy(temp, struct_name); strcat(temp,"."); strcat(temp,yytext); push(stk, temp);} ENI 
|
;
ENI: ',' VI
 | ';'
;



E: E '+' F { strcpy($$,add("+",$1,$3)); }
 | F { strcpy($$, $1); }
 ;
F:  F  '*'  G { strcpy($$,add("*",$1,$3));   }
 | G { strcpy($$, $1); }
;
G: G '/' H { strcpy($$,add("/",$1,$3)); }
 | H { strcpy($$, $1); }
;
H: H '-' I {strcpy($$,add("-",$1,$3));}
 | I { strcpy($$, $1); }
;
I: '(' E ')' { strcpy($$, $2); }
 | ID  { strcpy($$, $1); }
 | INUM
 | FNUM
 ;
%%
int main()
{
    char message[10][100];
    int init=0;
    int k=0;
    int flag=1;
    constr();
    yyparse();
   
    while(k<idx)
    {
        
       if( strcmp(threeAdd[k][0],"=")==0)
       {
           if( (strcmp(threeType[k][1],"int")==0) && (strcmp(threeType[k][3],"float")==0))
           sprintf(message[init++], "Type coercing (Implicit type conversion) from int to float is done in \' %s \' operator;", threeAdd[k][0]);
           else if((strcmp(threeType[k][3],"int")==0) && (strcmp(threeType[k][1],"float")==0)){
               flag=0;
                sprintf(message[init++],"Type casting (Explicit type conversion) in the assignment operator is required.");
           }
           else if ((strcmp(threeType[k][3],threeType[k][1])!=0)) 
           {
               flag=0;
               sprintf(message[init++],"Invalid Type conversion from %s to %s  not be done.", threeType[k][1],threeType[k][3]);
           }
       }
       else if( ( (strcmp(threeType[k][1],"int")==0) && (strcmp(threeType[k][2],"float")==0)) || ((strcmp(threeType[k][1],"float")==0) && ((strcmp(threeType[k][2],"int")==0)) ))
        {
            sprintf(message[init++],"Type coercing (Implicit type conversion) from int to float is done in \' %s \' operator;", threeAdd[k][0]);
        }
       
        k++;
    }
    if(flag)
    {
    k=0;
    
    while(k<idx)
    {
        if(strcmp(threeAdd[k][0],"=")==0)
        {
            printf("  %s := %s \n",threeAdd[k][3],threeAdd[k][1]);
        }
        else
        {
            printf("  %s := %s %s %s \n",threeAdd[k][3],threeAdd[k][1],threeAdd[k][0], threeAdd[k][2]);
        }
        
        //printf("%s\t%s\t%s\t%s\n", threeAdd[k][0],threeAdd[k][1],threeAdd[k][2],threeAdd[k][3]);
        k++;
    }
    printf("\n");
    }
    k=0;
    while(k<init)
    {
        printf("%s\n", message[k]);
        k++;
    }
    return 0;
}
int yywrap()
{
    return 1;
}
int yyerror(char *err)
{
    extern int line;
    printf("Error at line: %d\n", line);
    exit(0);
    
}
