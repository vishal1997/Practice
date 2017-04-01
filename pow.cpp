#include<iostream>
using namespace std;
float power(float x, int y);
int
main() {
    float x;
    int y;
    cout<<"Enter the number";
    cin>>x;
    cout<<"\nEnter the power";
    cin>>y;
    float result=power(x,y);
    cout<<"\nPower="<<result;
    return 0;
}

float power(float x, int y) {
    if(y==0)
        return 1;
    float temp=power(x,y/2);
    if(y%2==0)
        return temp*temp;
    if(y>0)
        return temp*temp*x;
    return temp*temp/x;
}


