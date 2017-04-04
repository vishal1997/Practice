#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 7
#define SIZE 7

struct student {
    int regNo,
    age;
    char name[50];
    struct student *next;
};

struct pointHead {
    struct student *head;
};

struct student *createNode(int key, int regNo) {
    struct student *newNode=(struct student *)malloc(sizeof(struct student));
    if(!newNode) {
        printf("\nNo space in the disk:");
        return NULL;
    }
    inputStudent(newNode);
    newNode->regNo=regNo;
    newNode->next=NULL;
    return newNode;
}

int hashFunction(int key) {
	return key%M;
}

void insertHashData(struct pointHead *hashTable) {
    int regNo=studentRegNo();
    int key=hashFunction(regNo);
    struct student *newNode=createNode(key,regNo);

    if(!newNode)
        return;

    if(!hashTable[key].head) {
        hashTable[key].head=newNode;
        return ;
    }
    newNode->next=hashTable[key].head;
    hashTable[key].head=newNode;
    return ;
}


int studentRegNo() {
	int no;
	printf("\nEnter the reg no.");
	scanf("%d",&no);
	return no;
}
void searchRecord(struct pointHead *hashTable,int regNo) {
    int found=0;
    int key=hashFunction(regNo);
    if(!hashTable[key].head){
        printf("\nNo data Found");
        return ;
    }
    struct student *copyTable=hashTable[key].head;
    while(copyTable!=NULL) {
        if(copyTable->regNo==regNo){
            displayData(copyTable);
            found=1;
            break;
        }
        copyTable=copyTable->next;
    }
    if(!found)
        printf("\nRecord not found");
}

void displayData(struct student *s) {
	printf("\nStudent reg. No=%d",s->regNo);
	printf("\nStudent Name =%s",s->name);
	printf("\nStudent age=%d",s->age);
}


void inputStudent(struct student *s) {
    printf("\n-------------------------------------------\n");
	printf("\nEnter Name:");
	scanf("%s",s->name);
	printf("\nEnter Age:");
	scanf("%d",&s->age);
	printf("\n-------------------------------------------\n");
}

int main() {
    struct pointHead *head=(struct pointHead *)malloc(SIZE*sizeof(struct pointHead));
    int i,
    regNo,age;
    char name[50];
    for(i=0;i<SIZE;i++) {
        insertHashData(head);
    }
    printf("\nEnter reg no to search record:");
    scanf("%d",&regNo);
    searchRecord(head,regNo);
}
