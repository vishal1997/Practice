#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

bool fullMatch(string str1, string str2) {
    if(!str1[0]&& !str2[0])
        return false;
    if(!str2[0])
        return true;
    if(str1[0]==str2[0])
        return fullMatch(&str1[1], &str2[1]);
    return false;
}

bool findString(string str1, string str2) {
    if(!str1[0])
        return false;
    if(!str2[0])
        return true;
    if(str1[0]==str2[0])
        return fullMatch(str1,str2);
    return findString(&str1[1] , str2);
}

int main() {
    string str1, str2;
    printf("\nEnter the string");
    getline(cin,str1);
    cout<<"\nString is :"<<str1;
    printf("\nEnter the string");
    getline(cin,str2);
    cout<<"\nString is : "<<str2;
    bool result=findString(str1, str2);
    if(result)
        cout<<"\nFOUND";
    else
        cout<<"\nNOT FOUND";
    return 0;
}
