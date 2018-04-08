#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int  make(char *s, const char * delimiters, char ***argument) {

	if(strlen(delimiters)>1)
		return -1; 

	int i=0,j=0;	
	char *token = strtok(s, delimiters);
	
	while (token != NULL) {
	
		*(*(argument)+j) = (char *)malloc(5* sizeof(char *));
		strcpy(*(*(argument)+j),token);
		//printf("%s\n", argument[i][j]);
		token = strtok(NULL, delimiters);
		j++;
	}
	return j;
}

int main() {

	char *str = (char *) malloc(20 * sizeof(char *));;
	strcpy(str,"arg1\targ2\targ3\targ4"); 
	char *s = "\t"; 
	int j = 0;	
	char **ar = (char **) malloc(sizeof(char *) * strlen(str));
	printf("%d",make(str,s, &ar));
	free(ar);
	return 0;
}

