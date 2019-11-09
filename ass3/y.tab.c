#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 1 "q1.y"
 
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
    

    
#line 187 "y.tab.c"
#define INT 257
#define CHAR 258
#define FLOAT 259
#define ID 260
#define FNUM 261
#define INUM 262
#define STRUCT 263
#define OB 264
#define CB 265
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    5,    1,    1,    1,    4,    4,    2,    2,    2,
    2,    9,    3,    8,    8,    8,    6,   11,    7,   13,
   13,   15,   12,   12,   14,   14,   10,   10,   16,   16,
   17,   17,   18,   18,   19,   19,   19,   19,
};
short yylen[] = {                                         2,
    1,    0,    4,    2,    2,    2,    0,    1,    1,    1,
    1,    0,    3,    2,    4,    1,    4,    0,    9,    3,
    0,    0,    3,    0,    2,    1,    3,    1,    3,    1,
    3,    1,    3,    1,    3,    1,    1,    1,
};
short yydefred[] = {                                      0,
    8,    9,   10,    0,    0,    0,    1,    0,    0,    0,
    0,   18,   12,    2,    0,    4,    5,   36,   38,   37,
    0,    0,    0,    0,    0,   34,    0,    0,    0,    6,
    0,    0,   17,    0,    0,    0,    0,    0,    0,   16,
   13,    3,   35,    0,    0,    0,   33,   11,    0,    0,
   14,   22,    0,    0,    0,    0,    0,   15,    0,   26,
   23,    0,    0,   25,   20,   19,
};
short yydgoto[] = {                                       6,
   15,    8,   14,   16,   29,    9,   10,   41,   28,   22,
   27,   53,   57,   61,   55,   23,   24,   25,   26,
};
short yysindex[] = {                                   -215,
    0,    0,    0,  -55, -244,    0,    0, -234, -215, -215,
  -40,    0,    0,    0, -215,    0,    0,    0,    0,    0,
  -40,  -18,    4,    3,    2,    0,  -72,  -41, -215,    0,
   -4,  -40,    0,  -40,  -40,  -40, -203, -204, -234,    0,
    0,    0,    0,    4,    3,    2,    0,    0, -201, -205,
    0,    0, -203,    5,   -6, -201,  -64,    0, -201,    0,
    0, -203,    6,    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0, -198,    0,    0,    0,    0,   63,   63,
    0,    0,    0,    0,   63,    0,    0,    0,    0,    0,
    0,    0,  -24,  -29,  -32,    0,    0,    0,   63,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   -7,  -10,  -19,    0,    0, -124,    0,
    0,    0,  -59,    0,    0, -124,    0,    0, -124,    0,
    0,  -59,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   67,  -33,   29,   -8,    0,    0,    0,    0,    0,   48,
    0,  -51,    8,    0,    0,   39,   38,   40,   37,
};
#define YYTABLESIZE 223
short yytable[] = {                                      21,
   24,   17,   39,   49,   62,   11,   30,   64,   32,   32,
   32,   30,   30,   30,   32,   12,   28,   40,   28,   56,
   42,   31,   31,   31,   32,   13,   32,   31,   56,   30,
   29,   29,   29,   27,   28,   27,   43,   59,   32,   31,
   33,    1,    2,    3,    4,   34,   36,    5,   29,   35,
   37,   27,   60,    1,    2,    3,   48,   50,   52,   54,
   63,   11,    7,   58,   66,   21,    7,   51,   31,   65,
   44,   45,   47,    0,   46,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   24,   24,   24,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   18,
   19,   20,   38,
};
short yycheck[] = {                                      40,
  125,   10,   44,   37,   56,   61,   15,   59,   41,   42,
   43,   41,   42,   43,   47,  260,   41,   59,   43,   53,
   29,   41,   42,   43,   43,  260,   59,   47,   62,   59,
   41,   42,   43,   41,   59,   43,   41,   44,   43,   59,
   59,  257,  258,  259,  260,   42,   45,  263,   59,   47,
  123,   59,   59,  257,  258,  259,  260,  262,  260,  265,
  125,  260,    0,   59,   59,  125,    0,   39,   21,   62,
   32,   34,   36,   -1,   35,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,
  261,  262,  264,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 265
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"INT","CHAR","FLOAT","ID","FNUM","INUM","STRUCT","OB","CB",
};
char *yyrule[] = {
"$accept : START",
"START : S",
"$$1 :",
"S : T V $$1 ST",
"S : STMT ST",
"S : STR ST",
"ST : S ST",
"ST :",
"T : INT",
"T : CHAR",
"T : FLOAT",
"T : ID",
"$$2 :",
"V : ID $$2 EN",
"EN : ',' V",
"EN : OB INUM CB ';'",
"EN : ';'",
"STMT : ID '=' E ';'",
"$$3 :",
"STR : STRUCT ID $$3 '{' T VI DCL '}' ';'",
"DCL : T VI DCL",
"DCL :",
"$$4 :",
"VI : ID $$4 ENI",
"VI :",
"ENI : ',' VI",
"ENI : ';'",
"E : E '+' F",
"E : F",
"F : F '*' G",
"F : G",
"G : G '/' H",
"G : H",
"H : H '-' I",
"H : I",
"I : '(' E ')'",
"I : ID",
"I : INUM",
"I : FNUM",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 231 "q1.y"
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
#line 463 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 169 "q1.y"
{ return 0; }
break;
case 2:
#line 170 "q1.y"
{ 
    while(stk->top>=0)
    {
        put(pop(stk), type->mat[type->top]);
    }
    pop(type);
 }
break;
case 8:
#line 184 "q1.y"
{ push(type,"int"); }
break;
case 9:
#line 185 "q1.y"
{  push(type,"char");}
break;
case 10:
#line 186 "q1.y"
{ push(type,"float"); }
break;
case 11:
#line 187 "q1.y"
{ if(search((yyvsp[0]))==1) { push(type, (yyvsp[0]));} else { printf("ERROR: No such type available: %s\n",yyvsp[0]); exit(0); } }
break;
case 12:
#line 189 "q1.y"
{ push(stk, yyvsp[0]); }
break;
case 15:
#line 192 "q1.y"
{  put(pop(stk), "array"); strcpy(types[pos++],"array"); pop(type); }
break;
case 17:
#line 195 "q1.y"
{ add("=", yyvsp[-1], yyvsp[-3] ); }
break;
case 18:
#line 198 "q1.y"
{ strcpy(types[pos++],yytext); strcpy(struct_name,yytext); }
break;
case 22:
#line 204 "q1.y"
{ strcpy(temp, struct_name); strcat(temp,"."); strcat(temp,yytext); push(stk, temp);}
break;
case 27:
#line 213 "q1.y"
{ strcpy(yyval,add("+",yyvsp[-2],yyvsp[0])); }
break;
case 28:
#line 214 "q1.y"
{ strcpy(yyval, yyvsp[0]); }
break;
case 29:
#line 216 "q1.y"
{ strcpy(yyval,add("*",yyvsp[-2],yyvsp[0]));   }
break;
case 30:
#line 217 "q1.y"
{ strcpy(yyval, yyvsp[0]); }
break;
case 31:
#line 219 "q1.y"
{ strcpy(yyval,add("/",yyvsp[-2],yyvsp[0])); }
break;
case 32:
#line 220 "q1.y"
{ strcpy(yyval, yyvsp[0]); }
break;
case 33:
#line 222 "q1.y"
{strcpy(yyval,add("-",yyvsp[-2],yyvsp[0]));}
break;
case 34:
#line 223 "q1.y"
{ strcpy(yyval, yyvsp[0]); }
break;
case 35:
#line 225 "q1.y"
{ strcpy(yyval, yyvsp[-1]); }
break;
case 36:
#line 226 "q1.y"
{ strcpy(yyval, yyvsp[0]); }
break;
#line 734 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
