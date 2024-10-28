%{
%}
identifier[a-zA-Z][a-zA-Z0-9]*
%%
#.*      printf("\n%s is PREPROCESSOR DIRECTIVE\n",yytext);
int  |
float |
double |
char |
for |
if printf("%s is a keyword\n",yytext);
{identifier}\( printf("\n\n FUNCTION CALL\n %s",yytext);
\{
printf("BLOCK BEGINS\n");
\}
printf("BLOCK ENDS\n");
= printf("%s is a ASSIGNMENT OPERATOR\n",yytext);
[0-9]+  printf("%s is NUMBER\n",yytext);
\< |
\> |
\== |
\>= |
\<=  printf("%s is a RELATIONAL OPERATOR\n",yytext);
\( { ECHO;printf("\n");}
\) { ECHO; printf("\n");}
\+ |
\- |
\*  printf("%s is a ARITHMETIC OPERATOR \n");
\++  printf("%s is a INCREMENTAL OPERATOR\n");
\;  { ECHO; printf("\n");}
%%
main()
{
yylex();
}
int yywrap()
{
return 1;
}

