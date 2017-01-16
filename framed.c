#include <string.h>
#include <stdio.h>

int main(void)
{
    char s[100];
    scanf("%[^\n]%*c",s);
    int large=0,count=1;
    int i, j;
    for(i=0;i<strlen(s);i++)
    {
        int z=0;
        while(s[i]!=' ' && i<strlen(s))
        {
            i++;
            z++;
        }
        if(s[i]==' ')
        {
            count++;
        }
        if(large<z)
        {
            large=z;
        }
    }
    //printf("COunt=%d, Large=%d",count,large);
    char word[count][large+1];
    i=0;
    int k;
    for(j=0;j<count;j++)
    {
        k=0;
        while(s[i]!=' ' && i<strlen(s))
        {
            //printf(" Executed ");
            word[j][k]=s[i];
            i++;
            k++;
        }
        //k++;
        if(s[i]==' ')
        {
            //printf(" IFexceted ");
            while(k<large)
            {
                word[j][k]=' ';
                k++;
            }
            word[j][k]='\0';
            i++;
        }
        if(i==strlen(s))
        {
            break;
        }

    }
    word[j][k]='\0';
    /*for(j=0;j<count;j++)
    {
        printf("%s\n",word[j]);
    }*/

    for(i=0;i<large+4;i++)
    {
        printf("#");
    }
    for(i=0;i<count;i++)
    {
        printf("\n# %s #",word[i]);
    }
    printf("\n");
    for(i=0;i<large+4;i++)
    {
        printf("#");
    }
}
