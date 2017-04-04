#include<stdio.h>
#define M 7
#define SIZE 7
struct student {
	int regNo,
	age;
	char name[50];
};
int hashFunction(int key);
int studentRegNo();
void displayData(struct student *s);
void inputStudent(struct student *s, int studentNo) ;
void display(struct student *s);
void searchRecord(struct student *s, int reg);
void initReg(struct student *s);
int
main() {
	struct student s[SIZE];
	int i,key,no,search,j;
	initReg(s);
	for(i=0;i<SIZE;i++) {
		no=studentRegNo();
		key=hashFunction(no);
		j=0;
		while(s[key].regNo!=0 && j<SIZE) {
			if(key==SIZE-1)
				key=0;
			else
				key++;
		j++;
		}

		//printf("\n-------%d  %s   %d\n",s[key].regNo,s[key].name,s[key].age);
		inputStudent(&s[key],no);
		//printf("\nReg=%d\n",s[key].regNo);
	}
	//display(s);
	printf("\nEnter reg. no to search for student data");
	scanf("%d",&search);
	searchRecord(s,search);
	return 0;
}

void initReg(struct student *s) {
	int i;
	for(i=0;i<SIZE;i++) {
		s[i].regNo=0;
	}
}

void searchRecord(struct student *s, int reg) {
	int key,i=0;
	key=hashFunction(reg);
	while(s[key].regNo!=reg && i<SIZE) {
		if(key==SIZE-1)
			key=0;
		else
			key++;
		i++;
	}
	displayData(&s[key]);
}

void displayData(struct student *s) {
	printf("\nStudent reg. No=%d",s->regNo);
	printf("\nStudent Name =%s",s->name);
	printf("\nStudent age=%d",s->age);
}

int studentRegNo() {
	int no;
	printf("\nEnter the reg no.");
	scanf("%d",&no);
	return no;
}

void inputStudent(struct student *s, int studentNo) {
	s->regNo=studentNo;
	printf("\nEnter Name:");
	scanf("%s",s->name);
	printf("\nEnter Age:");
	scanf("%d",&s->age);

}

int hashFunction(int key) {
	return key%M;
}

void display(struct student *s) {
	int i;
	for(i=0;i<SIZE;i++) {
		printf("\n%d %s %d ",s[i].regNo,s[i].name,s[i].age);
	}

}
