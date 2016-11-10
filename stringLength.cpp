#include<iostream>
#include<cstring>

using namespace std;

bool stringSize(char* str);
int number(char* str, int len);
int digitSize(char* str, int len);
int main()
{
    cout<<"Enter a String";
    char s[100];
    cin>>s;
    bool result=stringSize(s);
    if(result)
        cout<<"True";
    else
        cout<<"False";
    return 0;
}

bool stringSize(char* str)
{
    int len=strlen(str);
    int i=digitSize(str,len);
    int charLen=len-i;
    int decNumber=number(str,charLen);
    if(decNumber==charLen+1)
        return true;
    return false;
}

int number(char* str, int len)
{
    int i=len+1;
    int num=0;
    int r=0;
    while(str[i]!='\0')
    {
        r=(int)str[i];
        r=r-48;
        num=num*10+r;
        i++;
    }
    return num;
}

int digitSize(char* str, int len)
{
    int i=len-1;
    while(isdigit(str[i]))
    {
        i--;
    }
    len=len-i;
    return len;
}

