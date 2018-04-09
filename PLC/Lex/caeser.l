/*
*Write a LEX program to implement Caesar cipher.It replaces every letter with the one three letters apart in alphabetic order, wrapping *around at 'z' or 'Z'.
*/
%%
[a-z] {
	char ch = yytext[0];
	ch=ch+3;
	if (ch>'z') 
		ch=ch-('z'+1- 'a');
	printf ("%c",ch );
}
[A-Z] { 
	char ch = yytext[0] ;
	ch=ch+3;
	if (ch>'Z') ch=ch-('Z'+1- 'A');
		printf("%c",ch);
}

%%
int main()
{
	yylex();
	return 0;
}

int yywrap()
{
	return 1;
}
