%{
int p_count=0;
int n_count=0;
int pf_count=0;
int nf_count=0;
%}

digit [0-9]

%%

\+?{digit}+ {p_count++;}
-{digit}+ {n_count++;}
\+?{digit}*\.{digit}+ {pf_count++;}
-{digit}*\.{digit}+ {nf_count++;}

%%

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("Usage:<./a.out> <source_file>");
		exit(0);
	}
	
	yyin=fopen(argv[1],"r");
	
	yylex();
	printf("The number of positive numbers are:  %d\n",p_count);
	printf("The number of negative numbers are:  %d\n",n_count);
	printf("The number of positive fractional numbers are:  %d\n",pf_count);
	printf("The number of negative fractional numbers are:  %d\n",nf_count);

	//yywrap();
	return 0;
}
 
