#include<stdio.h>
#include<stdlib.h>
struct queue* insert(struct queue* front, struct queue* rear);
struct queue* delete(struct queue* front, struct queue* rear);
void display(struct queue* front, struct queue* rear);
struct queue
{
    int info;
    struct queue* next;
};

int main()
{
    struct queue *front, *rear, *temp;
    int choice;
    char ch;
    front=NULL;
    rear=NULL;
    do
    {
        printf("\n0: Quit");
        printf("\n1: Insert");
        printf("\n2: Delete");
        printf("\n3: Display");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: return 0;
            case 1: front=insert(front,rear);
                temp=front;
                while(temp->next!=NULL)
                    temp=temp->next;
                rear=temp;
                break;
            case 2: front=delete(front,rear);
                if(front==NULL)
                    rear==NULL;
                break;
            case 3: display(front,rear);
                break;
            default:printf("\nInvalid choice");
        }
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c",&ch);
    }while(ch=='Y' || ch=='y');
}

void display(struct queue* front, struct queue* rear)
{
    struct queue* temp=front;
    if(rear==NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    while(temp!=NULL)
    {
        printf(" %d ",temp->info);
        temp=temp->next;
    }
    return;
}
struct queue* delete(struct queue* front, struct queue* rear)
{
    if(front==NULL)
    {
        printf("Queue is empty");
        return front;
    }
    printf("\nDeleted number is:%d ",front->info);
    if(front==rear)
    {
        front=rear=NULL;
        return front;
    }
    struct queue* temp=front;
    front=front->next;
    free(temp);
    return front;
}

struct queue* insert(struct queue* front, struct queue* rear)
{
    struct queue* newNode=(struct queue*)malloc(sizeof(struct queue));
    if(newNode==NULL)
    {
        printf("\nInsufficient Space.\n");
        return front;
    }
    printf("\nEnter the data(numbers):");
    int number;
    scanf("%d",&number);
    newNode->next=NULL;
    newNode->info=number;
    if(front==NULL)
    {
        front=rear=newNode;
        return front;
    }
    rear->next=newNode;
    rear=rear->next;
    return front;
}
