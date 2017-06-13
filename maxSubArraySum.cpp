
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

long int max(long int a, long int b) { return (a > b)? a : b; }

// A utility funtion to find maximum of three integers
long int max(long int a, long int b, long int c) { return max(max(a, b), c); }


long int midArray(long int *array, long int low, long int mid,long int high, long int m) {
    int sum=0;
    int leftSum=INT_MIN;
    for(int i=mid;i>=low;i--) {
        sum+=array[i];
        if(sum>leftSum)
            leftSum=sum;
    }
    sum=0;
    int rightSum=INT_MIN;
    for(int i=mid+1;i<=high;i++) {
        sum+=array[i];
            if(sum>rightSum)
                rightSum=sum;
    }
    //cout<<(rightSum+leftSum)%m<<"\n";
    return (rightSum+leftSum)%m;
}

long int maxSumArray(long int *array, long int low, long int high,long int m) {
    if(low==high){
        //cout<<array[low]%m<<"\n";
        return array[low]%m;
    }
    long int mid=(low+high)/2;
    return max(maxSumArray(array, low,mid,m), maxSumArray(array,mid+1,high,m),midArray(array,low, mid, high,m));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        long int len;
        cin>>len;
        long int m;
        cin>>m;
        long int array[len];
        for(long int j=0;j<len;j++)
            cin>>array[j];
        cout<<maxSumArray(array,0,len-1,m);
        cout<<"\n";
    }
    return 0;
}
