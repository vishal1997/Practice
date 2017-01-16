#include <string.h>
#include <stdio.h>

int main(void)
{
    int n;
    int m;
    scanf("%d %d",&n,&m);
    char rooms[n][m];
    int i,j,count,max_count=0;
    for(i=0;i<n;i++)
    {
        scanf("%s",rooms[i]);
    }
    int iber_room;
    scanf("%d",&iber_room);
    for(i=0;i<n;i++)
    {

        for(j=0;j<m;j++)
        {
            count=0;
            while(rooms[i][j]=='0')
            {
                //printf("Executed");
                j++;
                count++;
            }
            if(count>max_count)
                max_count=count;
            if(max_count>=iber_room)
            {
                printf("1");
                return (0);
            }
        }
    }
    //printf("%d",max_count);

    printf("0");
}
