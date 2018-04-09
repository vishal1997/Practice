%{
	int char_count=0;
	int word_count=0;
	int line_count=0;
%}
letter [a-zA-Z]
%%
{letter}+ {word_count++; char_count+=yyleng;}
. char_count++;
\n {line_count++; char_count++;}
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
	printf("The number of characters are %d.\n", char_count);
	printf("The number of words are %d.\n", word_count);
	printf("The number of lines are %d.\n", line_count);
	
	return 0;
}
