#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    char arr[]="Hello Akash! How are you!! How are you doing? Do you want to have some tea??";
    strrev(arr);
    int start = 0;
    for(int i=0;arr[i]!='\0';i++){
        if(arr[i]==' '){
            reverse(arr+start,arr+i);
            start=i+1;
        }
    }
    reverse(arr+start,arr+strlen(arr));
    cout<<arr;
}

