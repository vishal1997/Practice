
#include<stdio.h>
#include<string.h>
int digitnum(char);
int main()
{
    char roman_num[1000];
    int i=0;
    long int number =0;
    printf("Enter any roman number (Valid digits are I, V, X, L, C, D, M):  \n");
    scanf("%s",roman_num);
    while(roman_num[i])
    {
        if(digitnum(roman_num[i]) < 0)
        {
             printf("Invalid roman digit : %c",roman_num[i]);
             return 0;
        }
        if((strlen(roman_num) -i) > 2)
        {
             if(digitnum(roman_num[i]) < digitnum(roman_num[i+2]))
             {
                 printf("Invalid roman number");
                 return 0;
             }
        }
        if(digitnum(roman_num[i]) >= digitnum(roman_num[i+1]))
             number = number + digitnum(roman_num[i]);
        else
        {
             number = number + (digitnum(roman_num[i+1]) - digitnum(roman_num[i]));
             i++;
        }
        i++;
    }
    printf("Its decimal num is : %ld",number);
    return 0;
}

int digitnum(char c)
{
    int num=0;
    switch(c)
    {
         case 'I': num = 1;
            break;
         case 'V': num = 5;
            break;
         case 'X': num = 10;
            break;
         case 'L': num = 50;
            break;
         case 'C': num = 100;
            break;
         case 'D': num = 500;
            break;
         case 'M': num = 1000;
            break;
         case '\0': num = 0;
            break;
         default: num = -1;
    }
    return num;
}
