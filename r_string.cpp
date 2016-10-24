#include <iostream>
#include <cstring>
using namespace std;
char* reverse_String(char* str,int k,int len);
char* reverse_Word(char* str, int len);
int main()
{
    char* rev_String;
    char str[100];
    char* revStr;
    cout<<"Enter a String:\n";
    cin.getline(str,100);
    int len=strlen(str);
    revStr=reverse_String(str,0,len);
    rev_String=reverse_Word(revStr, len);
    cout<<revStr;
    return 0;
}

char* reverse_Word(char* str, int len)
{
    int i=0;
    int j=0;
    while(str[i]!='\0')
    {
        while(str[i]!=' ' && str[i]!='\0')
        {
            i++;
        }
        str=reverse_String(str,j,i);
        i++;
        j=i;
    }
    return str;
}


char* reverse_String(char* str,int k,int len)
{
    int i;
    int j=len-1;
    int temp=0;
    int l=(k+len)/2;
    for(i=k;i<l;i++)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        j--;
    }
    return str;
}
