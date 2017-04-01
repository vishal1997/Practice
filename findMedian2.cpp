/*
Merge two sorted array and find the median in O(logn)

*/
#include<iostream>
#include<algorithm>
int getMedian(int array1[], int array2[], int len);
int median(int array[], int len);
using namespace std;
int
main() {
    int arraylen;
    cout<<"Enter the len of array";
    cin>>arraylen;
    int array1[arraylen],
    array2[arraylen];
    cout<<"Enter the elements in first array";
    for(int i=0;i<arraylen;i++) {
        cin>>array1[i];
    }
    cout<<"Enter the elements in first array";
    for(int i=0;i<arraylen;i++) {
        cin>>array2[i];
    }
    sort(array1,array1+arraylen);
    sort(array2,array2+arraylen);
    cout<<getMedian(array1,array2,arraylen-1);
    return 0;
}

int getMedian(int array1[], int array2[], int len) {
    if(len<=0)
        return -1;
    if(len==1)
        return (array1[0]+array2[0])/2;
    if(len==2)
        return max(array1[0],array2[0])+min(array1[1],array2[1])/2;
    int median1=median(array1,len);
    int median2=median(array2,len);
    if(median1==median2)
        return median1;
    if(median1<median2) {
        if(len%2==0)
            return getMedian(array1+(len/2)-1, array2,len- len/2 +1);
        return getMedian(array1+(len/2),array2,len-len/2);
    }
    else {
        if(len%2==0)
            return getMedian(array2+len/2 -1, array1,len- len/2 +1);
        return getMedian(array2+ len/2, array1,len- len/2);
    }

}

int median(int array[], int len) {
    if(len%2==0)
        return (array[len/2]+array[len/2 - 1])/2;
    return (array[len]/2);
}
