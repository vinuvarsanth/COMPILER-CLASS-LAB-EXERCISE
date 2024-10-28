%{
#include "pgm_name.tab.h"
%}

%%
[0-9]+    { yylval = atoi(yytext); return NUMBER; }
[\t]      ; // ignore whitespace
\n        { return 0; } // end of input 
.         { return yytext[0]; } // catch all for unrecognized characters
%%

int yywrap() {
    return 1;
}
