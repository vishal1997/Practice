#include <bits/stdc++.h>
using namespace std;

void quickSort(vector <int>&arr) {
    int len=arr.size();
    if(len<2)
        return;
    vector <int> leftArray;
    vector <int> rightArray;
    int p=arr[0];
    int i=1;
    while(i<len) {
        if(arr[i]<=p){
            leftArray.push_back(arr[i]);
        }
        else{
            rightArray.push_back(arr[i]);
        }
        i++;
    }
    quickSort(leftArray);
    quickSort(rightArray);
    i=0;
    for(int j=0;j<leftArray.size();j++){
        arr[i++]=leftArray[j];
        cout<<leftArray[j]<<" ";
        }
    arr[i++]=p;
    cout<<p<<" ";
    for(int j=0;j<rightArray.size();j++){
        arr[i++]=rightArray[j];
        cout<<rightArray[j]<<" ";
    }
    cout<<"\n";
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr);
    return 0;
}
