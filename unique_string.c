#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter a string:\n");
    scanf("%[^\n]s",str);
    int i,j;
    int temp=0;
    int len=strlen(str);
    for(i=0; i<=len-1; i++)
    {
        for(j=i+1; j<=len; j++)
        {
            if(str[i]==str[j])
                temp=1;
        }
    }
    if(temp==0)
        printf("True");
    else
        printf("False");
    return;
}
