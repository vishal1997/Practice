#include <string.h>
#include <stdio.h>

int main(void)
{
    int fish,days;
    scanf("%d",&fish);
    scanf("%d",&days);
    int each_day[days];
    int i,sum=0;
    for(i=0;i<days;i++)
    {
        scanf("%d",&each_day[i]);
    }
    for(i=0;i<days;i++)
    {
        if(sum<fish)
            sum=sum+each_day[i];
        else
        {
            printf("%d",i-1);
            return (0);
        }
    }
    printf("Happy Cat!");
}
