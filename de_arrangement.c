#include <stdio.h>
int dearranged(int depth, int len, int *d);
int main()
{
    int i,n;
	printf(" Enter the number of terms ");
	scanf("%d",&n);
    printf("Possible arrangements\n");
    int a[1024]; /* 1024 ought to be big enough for anybody */
    for (i = 0; i < n; i++)
        a[i] = i;//initialize array with index number
    int count = dearranged(0, n, a);
    printf("Total =%d",count);//total possible arrangement
    return 0;
}
/*
swap the elements of the array till the elements at the index is not equal to the index
*/
int dearranged(int depth, int len, int *d)
{
    int i;
    int tmp;
    int count = 0;//total count
    if (depth == len) {
        for (i = 0; i < len; i++)
            if(i!=d[i])//print only if the index is not equal to he array elements
                printf("%d",d[i]+1);
        printf("\n");//change line
        return 1; //return 1 to count the total possible of arrangement
    }
    for (i = len - 1; i >= depth; i--) {
        if (i == d[depth])//if the current index position is equal to the element
            continue;     //of the array at depth than we can't swap the elements

        tmp = d[i];//swap the elements of depth with the index value
        d[i] = d[depth];
        d[depth] = tmp;
        count += dearranged(depth + 1, len, d); //count the total possible arrangement and cal the same function with 1 increment in depth
        tmp = d[i];// again swap the elements
        d[i] = d[depth];
        d[depth] = tmp;
    }
    return count;// returns the number of possible arrangements.
}


