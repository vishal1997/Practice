#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef enum{
	start, divide, punctuator, assign, decDigit, digit, letter, literal, identifier, relation,comment, longComment, number, longCommentLoop
}states;

states transition(char inChar, states curState)
{
	switch(curState)
	{
		//case 1
		case start:
			if( inChar==' ' || inChar=='\t' || inChar=='\n')
				return start;
			else if( inChar=='/')
				return divide;
			else if( inChar=='(' || inChar==')' || inChar=='{' || inChar=='}' )
				return punctuator;
			else if( inChar=='=')
				return assign;
			else if( inChar=='.')
				return decDigit; 
			else if( isdigit(inChar) )
				return digit;
			else if( isalpha(inChar) || inChar=='_')
				return letter;
			else if( inChar=='\"')
				return literal;
		break;
		
		//case 2
		case divide:
			if(inChar=='/')
				return comment;
			else if(inChar=='*')
				return longComment;
		break;

		//case 3:
		case comment:
			if(inChar!='\n')
				return comment;
			else
				return start;
		break;

		//case 4
		case longComment:
			if(inChar!='*')
				return longComment;
			else 
				return longCommentLoop;
		break;

		//case 5
		case longCommentLoop:
			if(inChar=='*')
				return longCommentLoop;
			else if(inChar=='/')
				return start;
			else
				return longComment;
		break;
		
		//case 6
		case assign:
			if(inChar=='=')
				return relation;
			else
				return assign;
		case decDigit:
			if(isdigit(inChar))
				return number;

		case digit:
			if(inChar=='.')
				return decDigit;
	}
}

int main()
{
	FILE *fptr;
	
	states current_state = start;
	char transition_char, *filename;

	fptr=fopen("input.txt","r");
	do {
	    if (current_state == identifier) {
		printf(" - Identifier\n");
		current_state = start;
	    } else if (current_state == number) {
		printf(" - Number\n");
		current_state = start;
	    }
	    if(transition_char != '\n')
	    	fscanf(fptr,"%c", &transition_char);

	    if (transition_char != ' ' && transition_char != '\n')
		printf("%c", transition_char);

	    current_state = transition(current_state, transition_char);
	} while (transition_char!=EOF);
}
