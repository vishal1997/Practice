#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef enum {
    start, build_num, number, build_id, identifier, stop
}states;

states delta(states q, char input)
{
    switch(q)
    {
        case 0: //START
        if(input==' ')
            return q;
        else if(input=='.'||input=='\n')
            return stop;
        else if(isalpha(input))
            return build_id;
        else if(isdigit(input))
            return build_num;
        else{
            printf("Invalid input.\n");
            exit(1);
        }
        break;

        case 1: //BUILD_NUM
        if(input==' '||input=='\n')
            return number;
        else if(isdigit(input))
            return build_num;
        else{
            printf("Invalid input.\n");
            exit(1);
        }
        break;

        case 3: //BUILD_ID
         if(input==' ')
            return identifier;
        else if(isdigit(input) || input=='_')
            return build_id;
        else if(isalpha(input))
            return build_id;
        else{
            printf("Invalid input.\n");
            exit(1);
        }
        break;
        default:
        printf("Error");
    }
}

int main()
{
  
states current_state = start;
char transition_char;
printf("Enter the string:");

do {
    if (current_state == identifier) {
        printf(" - Identifier\n");
        current_state = start;
    } else if (current_state == number) {
        printf(" - Number\n");
        current_state = start;
    }
    if(transition_char != '\n')
    { scanf("%c", &transition_char); }

    if (transition_char != ' ' && transition_char != '\n')
        printf("%c", transition_char);

    current_state = delta(current_state, transition_char);
} while (current_state != stop);

}