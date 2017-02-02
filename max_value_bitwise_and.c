#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    int a0;
    int* greater=malloc(t*sizeof(int));
    int a,b;
    for(a0 = 0; a0 < t; a0++){
        int n; 
        int k;
        scanf("%d %d",&n,&k);
        for(a=1;a<n;a++)
            {
            for(b=a+1;b<=n;b++)
                {
                if(greater[a0]<(a&b) && (a&b)<k)
                    greater[a0]=a&b;
            }
        }      
        }
    for(a0=0;a0<t;a0++)
        printf("%d\n",greater[a0]);
    return 0;
}