#include<iostream>
using namespace std;
int main() {
    int num;
    cout<<"\nENter a num to multiply by 7:";
    cin>>num;
    cout<<"\n"<<num<<"*7="<<(num<<3) - num;
    return 0;
}
