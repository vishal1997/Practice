#include<bits/stdc++.h>
using namespace std;
struct pairMinMax{
    int min;
    int max;
};

struct pairMinMax findMinMax(int arr[] , int low, int high ) {
    pairMinMax minMax;
    //if only one element is in array
    if(low==high) {
        minMax.min=arr[low];
        minMax.max=arr[low];
        return minMax;
    }
    //if two elements are present in array
    if(low+1 == high) {
        if(arr[low]<arr[high]) {
            minMax.min=arr[low];
            minMax.max=arr[high];
        }
        else{
            minMax.min=arr[high];
            minMax.max=arr[low];
        }
        return minMax;
    }
    int mid=low+ (high-low)/2;
    pairMinMax leftMinMax=findMinMax(arr, low, mid);
    pairMinMax rightMinMax=findMinMax(arr, mid+1, high);
    if(leftMinMax.min < rightMinMax.min)
        minMax.min=leftMinMax.min;
    else
        minMax.min=rightMinMax.min;
    if(leftMinMax.max < rightMinMax.max)
        minMax.max=rightMinMax.max;
    else
        minMax.max=leftMinMax.max;
    return minMax;
}


int main() {
    int len;
    cout<<"\nEnter the length of array";
    cin>>len;
    int array[len];
    for(int i=0;i<len;i++)
        cin>>array[i];
    pairMinMax minMax=findMinMax(array,0,len-1);
    cout<<"Min="<<minMax.min;
    cout<<"Max="<<minMax.max;
    return 0;
}
