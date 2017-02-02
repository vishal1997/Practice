#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include<ctype.h>
int main(){
    int n; 
    scanf("%d",&n);
    char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s);
    int k; 
    scanf("%d",&k);
    int position=0;
    char c[100];
    int i;
    for(i=0;i<n;i++)
        {
            if(islower(s[i]))
            {
                position=(int)s[i]-97;
                c[i]=(position+k)%26;
                c[i]=(int)c[i]+97;
                printf("%c",c[i]);
            }
            else if(isupper(s[i]))
            {
                position=(int)s[i]-65;
                c[i]=(position+k)%26;
                c[i]=(int)c[i]+65;
                printf("%c",c[i]);
            }
            else if(isdigit(s[i]))
            {
                s[i]=(int)s[i]-48;
                printf("%d",(int)s[i]);
            }
            else
            {
                printf("%c",s[i]);
            }
    }
    return 0;
}
