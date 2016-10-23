#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* Reverse_Word(char str[],char rev_String[]);
int main()
{
    char rev_String[100];
    char str[100];
    char* revStr;
    printf("Enter a String:\n");
    scanf("%[^\n]s",str);
    revStr=Reverse_Word(str,rev_String);
    printf("%s",revStr);
    return 0;
}

char* Reverse_Word(char str[],char rev_String[])
{

    int i=strlen(str);
    int j;
    int k=0;
    do
    {
    while(str[i]!=' ' && i>=0)
    {
        i--;
    }
    j=i+1;
    while(str[j]!=' ' && str[j]!='\0')
    {
        rev_String[k]=str[j];
        k++;
        j++;
    }
    rev_String[k]=' ';
    k++;
    i--;
    }while(i>0);
    rev_String[k]='\0';
    return rev_String;
}
