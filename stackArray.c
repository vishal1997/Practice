#include<stdio.h>
#include<stdlib.h>

#define MAX 5
struct stack
{
    int arr[MAX];
    int top;
};


struct stack pop(struct stack Stack);
struct stack push(struct stack Stack, int data);
void display(struct stack Stack);

int main()
{
    struct stack Stack;
    Stack.top=-1;
    int choice;
    char ch;
    do
    {
        printf("\n\tMENU\n\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit");
		printf("\n\tEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter data:\n");
                    int n;
                    scanf("%d",&n);
                    Stack=push(Stack,n);
                    break;
            case 2: Stack=pop(Stack);
                    break;
            case 3: display(Stack);
                    break;
			case 4: exit(0);
                    break;
			default: printf("Invalid choice.\n");
        }
        printf("\n--------------------------------------------------\n");
		printf("\n\tDo u want to continue (press.. y/n) : ");
		scanf(" %c",&ch);
    }while(ch=='Y' || ch=='y');
}


struct stack pop(struct stack Stack)
{
    if(Stack.top==-1)
    {
        printf("Stack is empty:\n");
        return Stack;
    }
    int item=Stack.arr[Stack.top];
    Stack.top=Stack.top -1;
    return Stack;
}


void display(struct stack Stack)
{
    while(Stack.top!=-1)
    {
        printf("%d",Stack.arr[Stack.top]);
        Stack.top--;
    }
    return;
}


struct stack push(struct stack Stack, int data)
{
    if(Stack.top==MAX-1)
    {
        printf("\nOverflow\n");
        return Stack;
    }
    Stack.top=Stack.top + 1;
    Stack.arr[Stack.top]=data;
    return Stack;
}
