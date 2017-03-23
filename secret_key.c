#include<stdio.h>
#include<string.h>
void print_pattern(char pattern[]);
int
main()
{
    char pattern[100];
    scanf(" %[^\n]s",pattern);
    print_pattern(pattern);
    return 0;
}

void print_pattern(char pattern[])
{
    int max_digit=0,
    prev_digit=0,
    j,i;
    for(i=0;i<strlen(pattern);i++)
    {
        int count_y=0;
        if(pattern[i]=='X')
        {
            j=i+1;
            while(pattern[j]=='Y' && j<strlen(pattern))
            {
                count_y++;
                j++;
            }
            if(i==0)
            {
                max_digit=count_y+2;
                prev_digit++;
                printf("%d",prev_digit);
                printf("%d",max_digit);
                prev_digit=max_digit;
            }
            else
            {
                max_digit+=count_y+1;
                prev_digit=max_digit;
                printf("%d",prev_digit);
            }
            int k;
            for(k=0;k<count_y;k++)
            {
                prev_digit--;
                printf("%d",prev_digit);
                i++;
            }
        }
        else if(pattern[i]=='Y')
        {
            if(i==0)
            {
                j=i+1;
                while(pattern[j]=='Y' && j<strlen(pattern))
                {
                    count_y++;
                    j++;
                }
                max_digit=count_y+2;
                printf("%d",max_digit);
                printf("%d",max_digit-1);
                prev_digit=max_digit-1;
            }
            else
            {
                prev_digit--;
                printf("%d",prev_digit);
            }
        }
    }
    printf("\n");
}
