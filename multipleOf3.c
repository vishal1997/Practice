/*
Efficient Method to Check if a Number is Multiple of 3

There is a pattern in binary representation of the number that can be used to find if number is a multiple of 3. If difference between count of odd set bits (Bits set at odd positions) and even set bits is multiple of 3 then is the number.

Example: 23 (00..10111)
1) Get count of all set bits at odd positions (For 23 it’s 3).
2) Get count of all set bits at even positions (For 23 it’s 1).
3) If difference of above two counts is a multiple of 3 then number is also a multiple of 3.

(For 23 it’s 2 so 23 is not a multiple of 3)

*/
#include<stdio.h>
int isMultiple3(int num);
int
main() {
    int num;
    printf("\nEnter a no.");
    scanf("%d",&num);
    if(isMultiple3(num))
        printf("\n%d is multiple of 3",num);
    else
        printf("\n%d is not multiple of 3",num);
    return 0;
}

int isMultiple3(int num) {
    int odd=0,
    even=0;
    if(num<0)
        num=-num;
    if(num==0)
        return 1;
    if(num==1)
        return 0;
    while(num) {
        if(num & 1)
            odd++;
        num=num>>1;
        if(num & 1)
            even++;
        num=num>>1;
    }
    return isMultiple3(abs(odd-even));
}
