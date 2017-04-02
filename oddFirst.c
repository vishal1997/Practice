/*
Given an array of integers, sort it in such a way that the odd numbers appear
first and the even numbers appear later. The odd numbers should be sorted in
descending order and the even numbers should be sorted in ascending order.
*/
#include<stdio.h>
#include<stdlib.h>
int comparator(const void *p, const void *q);
void printArr(int arr[], int n);
int
main() {
    int size;
    printf("\nEnter the length of array");
    scanf("%d",&size);
    int arr[size];
    int i;
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    qsort((void *)arr,size,sizeof(arr[0]),comparator);
    printArr(arr, size);
}
void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}

int comparator(const void *p, const void *q) {
    int l=*(const int*)p;
    int r=*(const int*)q;
    //if l and r both are odd then put greater first
    if((l&1) && (r&1))
        return r-l;
    //if l and r both are even the put smaller first
    if(!(l & 1) && !(r & 1))
        return l-r;
    //if l is even then put r first
    if(!(l & 1))
        return 1;
    //if l is odd put l first
    return -1;
}
