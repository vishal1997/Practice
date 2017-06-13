#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;




void swap(int *a, int *b);  //Swap two numbers
void quickSort(int *array, int inPosition, int lastPosition);
int partition(int *array, int inPosition, int lastPosition);    //sort the last array in its position and divide the array i
void quickSort(int *array, int inPosition, int lastPosition)
{
    //if initial index is greater than size of array return from function
    if (inPosition>lastPosition)
        return ;
    int index,i;
    //call the function to assign the last element in its correct position and to get the index from where the array must be divided
    index=partition(array,inPosition,lastPosition);
    //sort the left part of the array
    quickSort(array,inPosition,index-1);
    //sort the right part of array
    quickSort(array,index+1,lastPosition);
    return;
}

int partition(int *array, int inPosition, int lastPosition)
{
    //x stores last element present in array
    int x, i,j;
    x=array[lastPosition];
    //i is the index of element to be swapped
    i=inPosition-1;

    for(j=inPosition;j<lastPosition;j++)
    {
        //if element at j is greater than last element of array than increase j by 1
        //if element at j is less than or equal to last element of array than increase i by  and swap the value at i and j
        if(array[j]<=x)
        {
            i++;
            swap(&array[i],&array[j]);
        }
    }
    //swap the last value of array with i+1
    swap(&array[i+1],&array[lastPosition]);
    return i+1;
}

void swap(int *a, int *b)
{
    //store value of a in temp
    int temp=*a;
    //overwrite the value of a by b
    *a=*b;
    //store the value of temp in b
    *b=temp;
    return ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int len;
    cin>>len;
    int array[len];

    for(int i=0;i<len ;i++) {
        cin>>array[i];
    }
    quickSort(array,0,len-1);
    int min=INT_MAX;
    int j=1;
    for(int i=0;i<len-1;i++) {
        if(min> array[j]-array[i])
            min=array[j]-array[i];
        j++;
    }
    j=1;
    for(int i=0;i<len-1;i++) {
        if(min==array[j]-array[i])
            cout<<array[i]<<" "<<array[j];
        j++;
    }
    return 0;
}
