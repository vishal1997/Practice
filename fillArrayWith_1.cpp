/*
Given an array of 0 and 1, in how many iterations the whole array be filled with 1's if in a single iteration immediate neighbours of 1's can be filled.

NOTE: If you cannot fill array with 1's then print "-1" .

Input:
The first line contains a single integer T i.e. the number of test cases. The first line consists of a single integer N(length of array) .
The next line consists of a N spaced integers(either 0 or 1).

Output:
In one line print the minimum number of iterations to fill the whole string with 1's.

Constraints:
1<=T<=100
1<=N<=1000
0<=A[i]<=1

Examples:
Input:
2
15
1 0 1 0 0 1 0 1 1 0 1 1 0 0 1
17
0 0 1 1 0 0 1 1 0 1 1 1 1 0 0 0 1

Output:
1
2

Explanation:
Test Case 1:
To convert the whole array into 1's, one iteration is required . Between index i=2 and i=5 ,
the zero at i=3 would be converted to '1' due to its neighbour at i=2 similarly the zero at
i=4 would be converted into '1' due to its neighbour at i=5 , all this can be done in a single iteration.     */

#include <iostream>
#include<algorithm>
using namespace std;

int noIteration(int *arr, int arraySize) {
    int result=0;
    int countZero=0;
    bool isOne=false;
    int i=0;
    while(i<arraySize) {
        if(arr[i]==1)
            isOne=true;
        while(i<arraySize && arr[i]==1)
            i++;
        while(i<arraySize && arr[i]==0) {
            i++;
            countZero++;
        }
        if(i==arraySize && isOne==false)
            return -1;
        int curCount=0;
        if(i<arraySize && isOne==true){
            if(countZero & 1 ==0)
                curCount=countZero/2;
            else
                curCount=(countZero+1)/2;
            countZero=0;
        }
        else {
            curCount=countZero;
            countZero=0;
        }
        result=max(result,curCount);
    }
    return result;
}

int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        int arraySize;
        cin>>arraySize;
        int arr[arraySize];
        //input array
        for(int j=0;j<arraySize;j++)
            cin>>arr[j];
        cout<<noIteration(arr,arraySize)<<"\n";
    }
	return 0;
}
