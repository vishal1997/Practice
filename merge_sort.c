/*
Program sort an array using merge sort
O(n)=n*log(n).

Variable : array= array to sort
            inPosition : Initial index of array
            lastPosition : final position of array
            mid : mid position of  array, if the length of array is even than take floor or the mid
            length : length of array

*/
#include<stdio.h>
void mergeSort(int *array,  int inPosition, int lastPosition);
void merge(int *array,  int inPosition, int mid, int lastPosition); //Function to merge to half of the array
int
main()
{
    int length,i;
    //prompt user to enter the length
    printf("\nEnter the length of array");
    scanf("%d",&length);
    //declare array of size length
    int array[length];
    //prompt user to enter array elements
    for (i=0;i<length;i++)
        scanf("%d",&array[i]);
    //call the function to sort array
    //0 is the initial index of array
    mergeSort(array,0,length-1);
    printf("\n");
    //print the sorted array
    for(i=0;i<length;i++)
        printf(" %d ",array[i]);
    return 0;
}

void mergeSort(int *array,  int inPosition, int lastPosition)
{
    //if initial position of array is less than the size of array then return from the function
    if(inPosition>=lastPosition)
        return ;
    //printf("\nIn Position=%d",inPosition);
    //printf("\nLast Position=%d",lastPosition);
    //compute the mid index of array
    int mid=(inPosition+lastPosition)/2;
    //divide and sort the left part of array
    mergeSort(array, inPosition, mid);
    //divide and sort right part of array
    mergeSort(array, mid+1, lastPosition);
    //merge left and right array
    merge(array, inPosition,mid,lastPosition);
}

void merge(int *array,  int inPosition, int mid, int lastPosition)
{
    //k is the initial position of array
    //k denoted the index from where the elements in array to be changed
    int k=inPosition,
    i,
    //size of the left part of array
    leftArraySize=mid-inPosition+1,
    j,
    //size of right part of array
    rightArraySize=lastPosition-mid;
    //declare left array
    int leftArray[leftArraySize];
    //declare right array
    int rightArray[rightArraySize];
    //assign elements in the left part from original array
    for(i=0;i<leftArraySize;i++)
        leftArray[i]=array[inPosition+i];
    //assign elements in right part from original array
    for(j=0;j<rightArraySize;j++)
        rightArray[j]=array[mid+1+j];
    i=0;
    j=0;
    //i denotes the index of left array
    //j denotes the index of right array
    // if the value of i exceeds left array size or value of j exceeds right array size then terminate the loop
    while(i<leftArraySize && j<rightArraySize)
    {
        //if the element in left array is smaller than right array element, then assign that element in array at index k
        if(leftArray[i]<=rightArray[j])
        {
            array[k]=leftArray[i];
            //increase the value of i
            i++;
        }
        //if the element in left array is greater than right array element, then assign that element in array at index k
        else
        {
            array[k]=rightArray[j];
            //increase the value of j
            j++;
        }
        //increase the value of k
        k++;
    }

    int l;
    //Copy the remaining elements of left array, if there are any
    for (l=i;l<leftArraySize;l++)
    {
        array[k]=leftArray[l];
        k++;
    }
    //Copy the remaining elements of right array, if there are any
    for(l=j;l<rightArraySize;l++)
    {
        array[k]=rightArray[l];
        k++;
    }

}

