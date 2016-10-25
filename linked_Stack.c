
#include<stdio.h>
#include<stdlib.h>


struct node
{
	int info;
	struct node *next;
};

void display(struct node*);
struct node* push(struct node*);
struct node* pop(struct node*);

int main()
{
    struct node* head=NULL;
    int choice;
	char ch;
	do
	{
		printf("\n\tMENU\n\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit");
		printf("\n\tEnter ur choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				head=push(head);
				break;
			case 2:
				head=pop(head);
				break;
			case 3:
				display(head);
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

struct node* pop(struct node* head)
{
    if(head==NULL)
    {
        printf("\nNothing is to pop\n");
        return head;
    }
    struct node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

struct node* push(struct node* head)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("Insufficient Space:\n");
        return 0;
    }
    printf("Enter a element:\n");
    int data;
    scanf("%d",&data);
    new_node->info=data;
    new_node->next=head;
    head=new_node;
    return head;
}

void display(struct node *start)
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}
