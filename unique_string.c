#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_string(char s[]);
int main()
{
    char str[100];
    printf("Enter a String:\n");
    scanf("%[^\n]s",str);
    int result=check_string(str);
    if(result==-1)
        printf("Not unique");
    else
        printf("Unique");
    return;
}
int check_string(char s[])
{
    int len=strlen(s);
    int array[256]={0};
    int i,index=0;
    for(i=0;i<len;i++)
    {
        index=(int)s[i]-'\0';
        if(array[index]==0)
            ++array[index];
        else
            return -1;
    }
    return 1;
}
