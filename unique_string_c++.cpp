#include <iostream>
#include <stdlib.h>
#include <string.h>

bool check_string(char s[]);

int main()
{
    using namespace std;
    char str[100];
    cout<<"Enter a String:\n";
    cin>>str;
    if(check_string(str))
        cout<<"Unique";
    else
        cout<<"Not Unique";
    return 0;
}

bool check_string(char s[])
{
    int len=strlen(s);
    int array[256]={0};
    int i,index=0;
    for(i=0;i<len;i++)
    {
        index=(int)s[i]-'\0';
        if(array[index]==0)
            ++array[index];
        else
            return false;
    }
    return true;
}
