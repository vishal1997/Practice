#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void printList(struct node* start);
struct node* append(struct node* last, int data);
void insertAfter(struct node* start,int position, int data);
struct node* push(struct node* start, int data);



int main()
{
    struct node* head=NULL;
    int n,k, more=0;
    do{
    printf("Enter a number to insert at last:\n");
    scanf("%d",&n);
    head=append(head,n);
    printf("Enter 1 if you want to insert more elements at the last:");
    scanf("%d",&more);
    }while(more==1);
    do{
    printf("Enter a number to insert at the start:\n");
    scanf("%d",&k);
    head=push(head,k);
    printf("Enter 1 if you want to insert more elements at the start:");
    scanf("%d",&more);
    }while(more==1);
    int position, num;
    printf("Enter a position after which you want to insert a element:");
    scanf("%d",&position);
    printf("Enter the number to inserted:");
    scanf("%d",&num);
    insertAfter(head,position,num);

    printf("\nLinked list is:\n");
    printList(head);
    return 0;
}

void printList(struct node* head_ref)
{
    if(head_ref==NULL)
    {
        printf("\n No list found.\n");
        return ;
    }
    while(head_ref!=NULL)
    {
        printf("%d",head_ref->data);
        head_ref=head_ref->next;
    }
}

struct node* append(struct node* last, int data)
{
    struct node* head_ref=last;
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("\nInsufficient space:\n");
        return last;
    }
    new_node->data=data;
    new_node->next=NULL;
    if(head_ref==NULL)
    {
        head_ref=new_node;
        //printf("\nappend Success\n");
        return head_ref;
    }
    while(head_ref->next!=NULL)
    {
        head_ref=head_ref->next;
    }
    head_ref->next=new_node;
    //printf("\nappend Success\n");
    return last;
}

void insertAfter(struct node* start,int position, int data)
{
    struct node* pre_ref=NULL;
    struct node* head_ref=start;
    if(head_ref==NULL)
    {
        printf("\n The given location is invalid:\n");
        return;
    }
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("Insufficient Space:\n");
        return;
    }
    new_node->data=data;
    new_node->next=NULL;
    int count=0;
    while(head_ref!=NULL && count<position)
    {
        pre_ref=head_ref;
        head_ref=head_ref->next;
        count++;
    }
    if(head_ref==NULL)
    {
        printf("Invalid position");
        return;
    }
    pre_ref->next=new_node;
    new_node->next=head_ref;
    //printf("\n after success");
    return;
}

struct node* push(struct node* head_ref, int data)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("Insufficient Space\n");
        return head_ref;
    }
    new_node->data=data;
    new_node->next=head_ref;
    head_ref=new_node;
    //printf("\n push success\n");

    return head_ref;
}
