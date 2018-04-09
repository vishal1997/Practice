#include<stdio.h>
#include<stdlib.h>

typedef enum{
	q_1, q_2
}states;


states delta(states q)
{
	switch(q)
	{
		case 0:				//current state is q_1
			return q_2;
			
		case 1:				//current state is q_2
			return q_1;
		
		default:
			printf("Invalid\n");
	}		
}

int main()
{
	states current_state;
	char transition_char;
	current_state=q_1;
	
	printf("Enter the string:");
	scanf("%c",&transition_char);
	
	if(transition_char=='\n')
	{
		printf("Accepted.\n");
		exit(1);
	}

	if(transition_char == '0') {
		printf("Not Accepted.\n");
		exit(1);
	}

	do
	{	
		current_state=delta(current_state);
		scanf("%c", &transition_char);

	}while(transition_char!='\n');

	if(current_state==q_1)
	{
		printf("Accepted\n");
	}
	
	else
	{
		printf("Not Accepted\n");
	}	
}
