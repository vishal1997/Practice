#include <iostream>
#include <cstring>
using namespace std;

bool check_string(char s[]);

int main()
{
    char str[100];
    cout<<"Enter a String:\n";
    cin.getline(str,100);  
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
