%{
#include<stdio.h>
#include<stdlib.h>
void yyerror(char *msg);
%}
%token NUMBER 
%nonassoc UMINUS

%%

S : E {printf("Value = %d\t %d \n ", $$, $1); exit(0);}
	;
E : E '-' T {$$ = $1 - $3;}
	| E '+' T {$$ = $1 +$3;}
	| T {$$ = $1;}
	;
	
F: '(' E ')' {$$ =$2;}
	| '-'F {$$ = -1 * $2;}
	| NUMBER {$$ = $1;}
	
T : T '*' F {$$ = $1 * $3;}
	| T '/' F { if($3 == 0) {
			printf("Error\n");
			}
			$$ = $1 / $3;
		} 
	| F { $$ = $1;}
	;
	
%%
int main() {

	printf("Enter the string\n");
	yyparse();
	return 0;
}

void yyerror(char *msg) {
	printf("%s\n", msg);
}
