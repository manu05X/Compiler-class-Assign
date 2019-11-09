%{
    #include <stdio.h>
    #include "y.tab.h"    
%}

%%
a   { return A; }
b   { return B; }
c   { return C; }
.|\n    { return yytext[0]; }
%%

