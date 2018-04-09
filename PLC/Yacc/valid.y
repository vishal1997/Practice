%{
#include<stdio.h>
int va=1;
%}
%token ID NUMBER
%left '+' '-'
%left '*' '/'

%%
stmt:expr
    ;
expr:expr '+' expr
    |expr '-' expr
    |expr '*' expr
    |expr '/' expr
    | '(' expr ')'
    | NUMBER
    | ID
    ;
%%

int yywrap() {

}

int yyerror(){
	va=0;
}
void main()
{
	yyparse();
	if(va)
		printf("valid expr");
	else
		printf("Invalid expr");
	exit(0);
}

