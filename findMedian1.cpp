/*
Merge two sorted array and find the median in O(n)

*/
#include<iostream>
#include<algorithm>
int median(int array1[], int array2[], int size);
using namespace std;
int
main() {
    int arraySize;
    cout<<"Enter the size of array";
    cin>>arraySize;
    int array1[arraySize],
    array2[arraySize];
    cout<<"Enter the elements in first array";
    for(int i=0;i<arraySize;i++) {
        cin>>array1[i];
    }
    cout<<"Enter the elements in first array";
    for(int i=0;i<arraySize;i++) {
        cin>>array2[i];
    }
    sort(array1,array1+arraySize);
    sort(array2,array2+arraySize);
    cout<<median(array1,array2,arraySize);
    return 0;
}


int median(int array1[], int array2[], int size) {
    int count=0,
    median1=-1,
    median2=-1,
    i=0,
    j=0;
    for( ; count<=size;count++) {
            if(i==size){
                median1=median2;
                median2=array2[0];
                break;
            }
            else if(j==size) {
                median1=median2;
                median2=array1[0];
            }
            if(array1[i]<array2[j]) {
                median1=median2;
                median2=array1[i];
                i++;
            }
            else {
                median1=median2;
                median2=array2[j];
                j++;
            }
    }
    return (median1+median2)/2;
}
