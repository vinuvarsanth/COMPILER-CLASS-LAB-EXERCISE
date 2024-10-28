%{
#include <stdio.h>
#include <stdlib.h>
int flag = 0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

ArithmeticExpression:
    E { printf("\nResult = %d\n", $$); return 0; }
;

E:
    E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E { $$ = $1 / $3; }
  | E '%' E { $$ = $1 % $3; }
  | '(' E ')' { $$ = $2; }
  | NUMBER { $$ = $1; }
;

%%

int main() {
    printf("Enter an expression: ");
    yyparse();
    if (flag == 0) {
        printf("\nEntered arithmetic expression is valid.\n");
    }
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Entered arithmetic expression is not valid: %s\n", s);
}
