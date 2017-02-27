#include <stdio.h>
#include <stdlib.h>

main()
{
    int n,j,i;
    printf("enter the number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            printf(" ");
        }
        for(j=0;j<=n-i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<n-i;j++)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
