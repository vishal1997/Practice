

#include <string.h>
#include <stdio.h>

int main(void)
{
    char str[1000];
    scanf("%[^\n]%*c", str);
    char* cat="cat";
    int length=strlen(str);
    int length_cat=strlen(cat);
    if(length<=0)
        {
        printf("There is no box\n");
        return 0;
    }
    char* d=strstr(str,cat);
    int position=d-str;
    int i=0;
    int k=0;
    while(i<position)
        {
        if(str[i]==' ')
            {
            k++;
        }
        i++;
    }
    if((k+1)%10==1)
    printf("The cat is the %dst item in the box",k+1);
    else if((k+1)%10==2)
         printf("The cat is the %dnd item in the box",k+1);
    else if((k+1)%10==3)
         printf("The cat is the %drd item in the box",k+1);
    else
         printf("The cat is the %dth item in the box",k+1);
}
