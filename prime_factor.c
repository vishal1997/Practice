#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    int n;
    printf("\nEnter the number:"); //prompt user to enter the number
    scanf("%d",&n);
    printf("\nEnter the position"); //prompt user to enter the ith prime factor of the given number
    int position;
    scanf("%d",&position);
    int i=0;
    int arr[n];
    while(n%2==0)  //update the number till the given number becomes odd and add 2 as the factor of the number
    {
        arr[i]=2;
        i++;
        n=n/2;
    }
    int j;
    for(j=3;j<=sqrt(n);j=j+2) //after the termination of while loop the number must be odd, increment j by 2
    {
        while(n%j==0) //if the updated number is divisible by 'j' add 'j' as the prime factor of the number
        {
            arr[i]=j;
            i++;
            n=n/j;
        }
    }

    if(n>2) // n must be odd and if number is greater than 2 add n as the prime factor
        arr[i]=n;
    /*for(j=0;j<i;j++)
        printf(" %d ",arr[j]);*/  //all the prime factors of the number.
    if(i>position)
        printf("%d",arr[position-1]);
    else
        printf("%d",-1);
    return 0;
}
