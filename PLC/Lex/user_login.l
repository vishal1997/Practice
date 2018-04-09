%{
#include <unistd.h>
%}

%%
username	printf("%s ", getlogin());
%%

main()
{
  yylex();
}

