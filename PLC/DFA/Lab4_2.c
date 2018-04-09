#include<stdio.h>
#include<stdlib.h>

typedef enum{
	q_1, q_2,q_3,q_4
}states;


states delta(states q, char change)
{
	switch(q)
	{
		case 0:					//q_1
			if(change=='1')
				return q_4;
			else if(change=='0')
				return q_2;
			else
			{
				printf("Invalid input\n");
				exit(1);
			}	
					
		case 1:					//q_2
			if(change=='1')
				return q_3;
			else if(change=='0')
			{
				return q_1;
			}
			else
			{
				printf("Invalid input\n");
				exit(1);
			}	
			
		case 2:					//q_3
			if(change=='1')
				return q_2;
			else if(change=='0')
			{
				return q_4;
			}
			else
			{
				printf("Invalid input\n");
				exit(1);
			}	
			
		case 3:					//q_4
			if(change=='1')
				return q_1;
			else if(change=='0')
			{
				return q_3;
			}
			else
			{
				printf("Invalid input\n");
				exit(1);
			}	
		
		default:
			printf("Invalid\n");
	}		
}

int main()
{
	states current_state;
	char transition_char;
	current_state=q_1;
	scanf("%c",&transition_char);
	
	if(transition_char=='\n')
	{
		printf("Accepted.\n");
		exit(1);
	}

	do
	{	current_state=delta(current_state, transition_char);
		scanf("%c", &transition_char);
	}while(transition_char!='\n');

	if(current_state==q_4)
	{
		printf("Accepted\n");
	}
	
	else
	{
		printf("Not Accepted\n");
	}	
}
