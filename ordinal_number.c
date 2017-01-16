
#include <string.h>
#include <stdio.h>

int main(void)
{
    char str[2000];
    scanf("%[^\n]%*c", str);
    int i;
    char cat[20]="cat";
    int length=strlen(str);
    int length_cat=strlen(cat);
    if(length<=0)
        {
        printf("There is no box\n");
        return 0;
    }
    int position=0;
    for(i=0;str[i]!='\0';i++)
    {
        int k=0;
        if(str[i]==' ' || i==0)
        {
            position++;
            //printf("%d\n",position);
            if(i==0)
            while(str[i]==cat[k] && k<length_cat && i<length)
            {
                i++;
                k++;
                //printf("(%d,%d)\n",i,k);
            }
            else if(str[i]==' ')
            {
                i=i+1;
                while(str[i]==cat[k] && k<length_cat && i<length)
                {
                    i++;
                    k++;
                    //printf("(%d,%d)\n",i,k);
                }
            }
            if(k==length_cat && (i==length || str[i]==' '))
            {
                //printf("display");
                int num=position;
                int digit[10];
                int index=0;
                while(num>0)
                    {
                    int rem=num%10;
                    digit[index]=rem;
                    num=num/10;
                    index++;
                }
                if(digit[1]!=1)
                    {
                if((position)%10==1)
                    printf("The cat is the %dst item in the box",position);
                else if(position%10==2)
                    printf("The cat is the %dnd item in the box",position);
                else if(position%10==3)
                    printf("The cat is the %drd item in the box",position);
                    }
                else if(digit[1]==1)
                    printf("The cat is the %dth item in the box",position);
                return 0;
            }
        }
        if(i==length-1)
            printf("No cat yet");
    }
}

