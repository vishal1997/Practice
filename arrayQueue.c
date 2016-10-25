#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct queue insert(struct queue Queue);
struct queue delete(struct queue Queue);
void display(struct queue Queue);

struct queue
{
    int front;
    int rear;
    int arr[MAX];
};


int main()
{
    struct queue Queue;
    Queue.front=Queue.rear=-1;
    int choice;
	char ch;
	do
	{
		printf("\n\tMENU\n\n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Exit");
		printf("\n\tEnter ur choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				Queue=insert(Queue);
				break;
			case 2:
				Queue=delete(Queue);
				break;
			case 3:
				display(Queue);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid choice.\n");
		}
		printf("\n--------------------------------------------------\n");
		printf("\n\tDo u want to continue (press.. y/n) : ");
		scanf(" %c",&ch);
	}while(ch=='Y'||ch=='y');
}

void display(struct queue Queue)
{
    if(Queue.rear==-1)
    {
        printf("\nQueue is empty:\n");
        return;
    }
    int i;
    for(i=Queue.front;i<=Queue.rear;i++)
    {
        printf(" %d ",Queue.arr[i]);
    }
    return;
}

struct queue delete(struct queue Queue)
{
    if(Queue.rear==-1)
    {
        printf("Queue is empty");
        return Queue;
    }
    int item=Queue.arr[Queue.front];
    printf("Deleted Item is %d",item);
    if(Queue.rear==Queue.front)
    {
        Queue.rear=Queue.front=-1;
        return Queue;
    }
    Queue.rear--;
    return Queue;
}


struct queue insert(struct queue Queue)
{
    if(Queue.rear==MAX-1)
    {
        printf("Queue Overflow\n");
        return Queue;
    }
    printf("\n\tEnter the element for insertion : ");
    int data;
    scanf("%d",&data);
    if(Queue.rear==-1 && Queue.front==-1)
        Queue.front=Queue.rear=0;
    else
        Queue.rear=Queue.rear+1;
    Queue.arr[Queue.rear]=data;
    return Queue;
}
