%{
int vow_count=0;
int const_count =0;
%}

consonant	[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]
vowel		[aeiouAEIOU]

%%

{vowel} {vow_count++;}
{consonant} {const_count++;}

%%

main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("Usage:<./a.out> <source_file>");
		exit(0);
	}
	
	yyin=fopen(argv[1],"r");
	
	yylex();
	printf("The number of vowels are:  %d\n",vow_count);
	printf("The number of consonants are:  %d\n",const_count);
	
} 
