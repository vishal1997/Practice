
%{ 
#include<stdio.h>
#include<string.h>
int k=0;
char *str;
%}
letter [a-zA-Z]
%%
{letter}+ {
	if(yyleng>k)
	{ k=yyleng; 
	  str=yytext;
	}
}
. |
\n ;
%%
int main(int argc[],char *argv[])
{
	 yyin=fopen(argv[1],"r");
	 yylex();
	 printf("Largest string: %s\n The string length is:%d",str,k);
	 printf("\n");
	 return 0;
}
int yywrap()
{
	return 1;
}

