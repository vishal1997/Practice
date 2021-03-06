#include<stdio.h>
#include "helper.c"
void heapify(int arr[], int len, int i);
void heapSort(int arr[], int len);
int
main() {
    int len;
    printf("\nEnter the size of array:");
    scanf("%d",&len);
    int arr[len],i;
    inputArray(arr,len);
    heapSort(arr,len);
    displayArray(arr,len);
}

void heapSort(int arr[], int len) {
    int i;
    for(i=len/2 -1;i>=0;i--)
        heapify(arr,len,i);

    for(i=len-1;i>=0;i--) {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

void heapify(int arr[], int len, int i) {
    if(len<=1)
        return ;
    int largest=i,
    left=2*i + 1,
    right=2*i +2;
    if((left<len) && arr[largest]<arr[left])
        largest=left;
    if(right<len && arr[largest]<arr[right])
        largest=right;
    if(largest!=i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr,len,largest);
    }
}
