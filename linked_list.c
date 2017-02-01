#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *insert_at_beg(struct Node *head, int data);
struct Node *insert_at_end(struct Node *head, int data);
struct Node *insert_at_position(struct Node *head, int position, int data);
struct Node *del_at_beg(struct Node *head);
struct Node *del_at_end(struct Node *head);
void traverse_forward(struct Node *head);
struct Node *traverse_backward(struct Node *head);
void search(struct Node *head, int data);
struct Node *del_at_position(struct Node *head, int position);
int input();


int
main()
{
	int ch,
	ch2,
	data,
	n;
	char repeat;
	struct Node *head=NULL;
	do {
	printf("\n1. Insert \n2. Delete \n3. Traverse \n4. Search\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			ch2=input();
			if(ch2==1) {
				printf("Enter the data\n");
				scanf("%d", &data);
				head=insert_at_beg(head,data);
			}
			else if(ch2==2) {
				printf("\nEnter the data\n");
				scanf("%d", &data);
				head=insert_at_end(head,data);
			}
			else if(ch2==3) {
				printf("\nEnter a position\n");
				scanf("%d", &n);
				printf("\nEnter data\n");
				scanf("%d",&data);
				head=insert_at_position(head, n, data);
			}
			break;
		case 2:
			ch2=input();
			if(ch2==1)
				head=del_at_beg(head);
			else if(ch2==2)
				head=del_at_end(head);
			else if(ch2==3) {
				printf("\nEnter a position\n");
				scanf("%d", &n);
				head=del_at_position(head,n);
			}
			break;
		case 3:
			do {
			printf("\n1. Traverse forward\n2. Traverse backward\n");
			scanf("%d", &ch2);
			} while(ch2>2 || ch2<1);
			if(ch2==1)
				traverse_forward(head);
			else if(ch2==2)
				head=traverse_backward(head);
			break;
		case 4:
			printf("\nEnter the data to search\n");
			scanf("%d",&ch2);
			search(head, ch2);
			break;
        default:
            printf("Invalid Input");
	}
	printf("Press 'Y' or 'y' for the menu\n");
	scanf(" %c", &repeat);
	} while (repeat=='Y' || repeat=='y');
}

int input()
{
	int ch2;
	do {
		printf("1. At beginning\n2. At end \n3. At any specified position");
		scanf("%d",&ch2);
	} while(ch2<=0 || ch2 >3);
	return ch2;
}


struct Node *insert_at_beg(struct Node *head, int data)
{
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	struct Node *ptr=head;
	new_node->data=data;
	new_node->next=ptr;
	head=new_node;
	return head;
}

struct Node *insert_at_end(struct Node *head, int data)
{
	struct Node *ptr=head;
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->data=data;
	new_node->next=NULL;
	while(ptr->next!=NULL) {
		ptr=ptr->next;
	}
	ptr->next=new_node;
	return head;
}

struct Node *insert_at_position(struct Node *head, int position, int data)
{
	struct Node *ptr=head, *prev=NULL;
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->data=data;
	new_node->next=NULL;
	int count=0;
	if(position==1)
	{
		new_node->next=ptr;
		head=new_node;
		return head;
	}
	while(ptr!=NULL && count<position) {
		prev=ptr;
		ptr=ptr->next;
		count++;
	}
	if(ptr==NULL)
	{
		printf("\nPosition Not found");
		return head;
	}
	prev->next=new_node;
	new_node->next=ptr;
	return head;
}

struct Node *del_at_beg(struct Node *head)
{
	struct Node *ptr=head;
	head=ptr->next;
	free(ptr);
	return head;
}

struct Node *del_at_end(struct Node *head)
{
	struct Node *ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	free(ptr);
	return head;
}

struct Node *del_at_position(struct Node *head, int position)
{
	int count=0;
	struct Node *ptr=head, *prev=NULL;
	if(position==1)
	{
		head=ptr->next;
		free(ptr);
		return head;
	}
	while(ptr!=NULL && count<position)
	{
		prev=ptr;
		ptr=ptr->next;
		count++;
 	}
	if(ptr==NULL)
	{
		printf("\nPosition Not found");
		return head;
	}
	prev->next=ptr->next;
	free(ptr);
	return head;
}

void traverse_forward(struct Node *head)
{
	struct Node *ptr=head;
	while(ptr!=NULL)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}
}

struct Node *traverse_backward(struct Node *head)
{
	struct Node *ptr=head,*cur=NULL;
	if(head==NULL)
        return head;
	cur=traverse_backward(ptr->next);
	printf("%d",cur->data);
	return head;
}

void search(struct Node *head, int data)
{
	struct Node *ptr=head;
	int position=0;
	while(ptr!=NULL && ptr->data!=data)
	{
		position++;
		ptr=ptr->next;
	}
	if(ptr->data==data)
	{
		printf("\nData found at %d",position);
	}
	else if(ptr==NULL)
		printf("\nData Not found");
    return;
}
