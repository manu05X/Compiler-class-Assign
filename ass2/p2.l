%{

#include "y.tab.h"

%}

%%

"a"|"A" {return A;}

"b"|"B" {return B;}

.|\n return yytext[0];

%%
yywrap();
