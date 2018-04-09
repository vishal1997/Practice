%{
#include<stdio.h>
#include<string.h>
int c_count=0;
%}
%%
[A-Z] {c_count++;}
[a-z0-9] ;
\n {return 0;}
%%
int main()
{
	printf("Enter the string:");
	yylex();
	printf("\nThe capital letter count is %d\n",c_count);
	return 0;
}

