/*
Problem Statement: The program will take multiple inputs separated by semicolon and will check them for above
conditions. Your program should create a two dimensional array with all the passwords and the
final status as true and false and print each password in a separate line.

Input Variable : password-> Store the string containing passwords
Output Variable : store_password-> Contains password after extracting it from string
                    check_password-> -1 denotes False and 0 denotes True
Additional Variable : len-> No. of passwords in the list
                        i-> indexing row
                        j-> indexing column
                        start, end -> range of char for valid passwords
                        count -> count the no. of occurrence of char in range start and end of each password

Author : Vishal Gupta
Date : 22-03-2017
*/
#include<stdio.h>
#include<string.h>
#define MINSIZE 8  //Minimum size of password
#define MAXSIZE 14 //Max size of password
int break_password(char password[], char store_password[100][100]);                         //extract the password from string
void init_check_password(int check_password[], int len);                                    //initialize check_password array to 0, -1 denotes False
void check_valid_password(char store_password[100][100],int size, int check_password[], char start, char end); //check for conditions
void special_char_except(char store_password[100][100],int size, int check_password[]);     //check for + - , . =
void check_length(char store_password[100][100],int size, int check_password[]);            //check for minimum and maximum size
void remove_space_at_beg(char store_password[100][100],int size);                           //remove space from beg after extracting string
void display(char store_password[100][100],int size, int check_password[]);                 //display result
int
main()
{
    char password[500], store_password[100][100];
    int len,
    check_password[100];
    scanf("%[^\n]s",password);                                              //prompt user to enter a string
    len=break_password(password,store_password);                            //extract the passwords from string and get the no. of passwords
    init_check_password(check_password,len);                                //initialize the array with 0
    remove_space_at_beg(store_password,len);                                //remove the spaces from the beg of each passwords
    check_valid_password(store_password,len, check_password, 'A', 'Z');     //check that the password must contain at least one uppercase
    check_valid_password(store_password,len, check_password, 'a', 'z');     //check that the password must contain at least one lower case
    check_valid_password(store_password,len, check_password, '0', '9');     //check that the password must contain at least one digit
    check_valid_password(store_password,len, check_password, '$', '@');     //check that the password must contain at least one special char
    special_char_except(store_password,len, check_password);                //check that the password not contain "+ - , . ="
    check_length(store_password,len, check_password);                       //check that the password must be between 8 and 14
    display(store_password,len,check_password);                             //display the result
    return 0;
}

void special_char_except(char store_password[100][100],int size, int check_password[])
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<strlen(store_password[i]);j++)
        {
            //if password contains space, +, -, ",", ".", = then the password is invalid
            if(store_password[i][j]==' ' || store_password[i][j]=='+' || store_password[i][j]=='-' || store_password[i][j]==',' || store_password[i][j]=='.' || store_password[i][j]=='=')
            {
                check_password[i]=-1; //assign -1 if password is invalid
                break;
            }
        }
    }
}

void check_length(char store_password[100][100],int size, int check_password[])
{
    int i;
    for(i=0;i<size;i++)
    {
        if(strlen(store_password[i])<MINSIZE)               //if length of password is less than 8 then password is invalid
            check_password[i]=-1;                           //assign -1 if password is invalid
        else if(strlen(store_password[i])>MAXSIZE)          //if length of password is greater than 14 than password is invalid
            check_password[i]=-1;                           //assign -1 if password is invalid
    }
}

void check_valid_password(char store_password[100][100],int size, int check_password[], char start, char end)
{
    int i,j,count;
    for (i=0;i<size;i++)
    {
        count=0;
        for(j=0;j<strlen(store_password[i]);j++)
        {
            if(store_password[i][j]>=start && store_password[i][j]<=end)    //check if the password is valid
                count++;
        }
        if(count<1)
            check_password[i]=-1;
    }
}

int break_password(char password[], char store_password[100][100])
{
    int i=0;
    char *token = strtok(password, ";");                    //split the string when ';' is found
    while (token != NULL)
    {
        strcpy(store_password[i],token);                    //copy the token in array
        token = strtok(NULL, ";");
        i++;
    }
    return i;                                               //i is no. of passwords
}

void init_check_password(int check_password[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        check_password[i]=0;
    }
}

void remove_space_at_beg(char store_password[100][100],int size)
{
    int i,j;
    for(i=1;i<size;i++)
    {                                                       //shift each char to left
        for (j=0;j<strlen(store_password[i])-1;j++)
            store_password[i][j]=store_password[i][j+1];
        store_password[i][j]='\0';                          //store '\0' in last index to indicate end of string
    }
}

void display(char store_password[100][100],int size, int check_password[])
{
    int i=0;
    while(i<size)
    {
        printf("\n%s",store_password[i]);                   //print the password
        if(check_password[i]==0)
            printf(", True");                               //if check_password[i] is 0 then the password satisfies all the conditions. print true
        else
            printf(", False");                              //if check_password[i] is not 0 then the password doesn't satisfies all the conditions. print false
        i++;
    }
}
