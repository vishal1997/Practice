/*
Problem Statement : John works in the cyber security cell. He wants to generate secret keys following a pattern.
The pattern consists of the characters 'X' and 'Y' where X means increasing and 'Y' means decreasing.
Help him devise an algorithm to generate the secret key which is the minimum number encoded following that pattern.
Digits from 1-9 and digits can’t repeat.

Input Variable : pattern-> store sequence of X and Y

Output Variable :
                max_digit->max digit to be printed
                prev_digit->previous digit that was printed

Additional Variable :
                count_y->no. of consecutive Y
                size->length of the input argument i.e length of the sequence of X and Y


Author : Vishal Gupta
Date : 23-03-2017
*/
#include<stdio.h>
#include<string.h>
void print_pattern(char pattern[]); //generate secret key using X and Y
int
main()
{
    char pattern[100];
    scanf(" %[^\n]s",pattern);      //prompt user to enter sequence of X and Y
    print_pattern(pattern);         //call print_pattern to generate secret key
    return 0;
}
/*
Generate secret key using sequence of X and Y
*/
void print_pattern(char pattern[])
{
    int max_digit=0,    //max digit to be printed
    prev_digit=0,       //previous digit that was printed
    j,i,
    size=strlen(pattern); //length of pattern
    for(i=0;i<strlen(pattern);i++)
    {
        int count_y=0;  //count the consecutive Y
        if(pattern[i]=='X')
        {
            j=i+1;
            while(pattern[j]=='Y' && j<size)        // if the char is X then find the no. of consecutive Y after X
            {
                count_y++;
                j++;
            }
            if(i==0)
            {
                max_digit=count_y+2;            //maximum digit to print. According to question for 1st char 2 digits are printed
                prev_digit++;
                printf("%d",prev_digit);        //print 1 if 1st char is X
                printf("%d",max_digit);         //print 2 if 1st char is X
                prev_digit=max_digit;           //update prev_digit
            }
            else
            {                                   //if 1st char is not X then only one digit is printed
                max_digit+=count_y+1;           //next digit to print
                printf("%d",max_digit);         //print next digit
                prev_digit=max_digit;           //update prev_digit
            }
            int k;
            for(k=0;k<count_y;k++)              //print digit for all the consecutive Y
            {
                prev_digit--;
                printf("%d",prev_digit);
                i++;
            }
        }
        else if(pattern[i]=='Y')                //if the char is Y
        {
            if(i==0)                            //if 1st char is Y
            {
                j=i+1;
                while(pattern[j]=='Y' && j<strlen(pattern)) //find the no. of consecutive Y
                {
                    count_y++;
                    j++;
                }
                max_digit=count_y+2;                //max digit to print
                printf("%d",max_digit);             //print max digit
                printf("%d",max_digit-1);           //print next digit
                prev_digit=max_digit-1;             //update prev_digit
            }
            else        //if Y is not the 1st char
            {
                prev_digit--;
                printf("%d",prev_digit);        //print the next digit in the pattern
            }
        }
    }
}
