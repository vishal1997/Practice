#include<stdio.h>
#include<stdlib.h>

int *prime(int *array,int n)
{
    int i;
    for(i=0;i<=n;i++) //initialize all the array with '1' to denote all are prime.
        array[i]=1;
    for(i=2;i*i<=n;i++) //initialize 'i' with the first prime number. Check if square of i is less than number
    {
        if(array[i]) //if the element at index 'i' is 1 than we have to change the elements to 0 at 'i*2' and at multiple of 'i'
        {
            int j;
            for(j=2*i;j<=n;j+=i)
            {
                array[j]=0;
            }
        }
    }
    return array;
}

int main()
{
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    int array[n+1];
    int i;
    int *prime_array=prime(array,n);
    for(i=2;i<=n;i++) //print all the number
    {
        if(*(prime_array+i))//if the element at index 'i' is 1 then print 'i'
            printf(" %d ",i);
    }
    return 0;
}
