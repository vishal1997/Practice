%{
	#include<stdio.h>
	int id=0;
%}
%%
[a-zA-Z][a-zA-Z0-9_]* {id++ ; ECHO; printf("\n");}
\n {;}
.+ {;}
%%

int main (int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("Usage: <./a.out> <sourcefile>\n");
		exit(0);
	}
	yyin=fopen(argv[1],"r");
	printf("Valid identifiers are\n");
	yylex();
	printf("No of identifiers = %d\n",id);
	return 0;
}
