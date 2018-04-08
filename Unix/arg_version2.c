#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int  make(char *s, char ***argument) {

	char *token = strtok(s, " ");
	int i=0,j=0;
	*argument = (char **) malloc(sizeof(char *) * strlen(s));
	while (token != NULL) {
		*(*(argument)+j) = (char *)malloc(5* sizeof(char *));
		strcpy(*(*(argument)+j),token);
		printf("%s\n", *(*(argument)+j));
		token = strtok(NULL, " ");
		j++;
	}
	return j;
}


int  make1(char *s, char ***argument) {

	char *token;
	int j=0;
	*argument = (char **) malloc(sizeof(char *) * strlen(s));
	
	if(*argument == NULL)
		return -1;
		
	for(token = strtok(s, " "); token!=NULL;token = strtok(NULL, " ") )  {
	
		*(*(argument)+j) = (char *)malloc(5* sizeof(char *));
		strcpy(*(*(argument)+j),token);
		//printf("%s\n", *(*(argument)+j));
		j++;
	}
	return j;
}

int main() {

	char *str = (char *) malloc(20 * sizeof(char *));;
	strcpy(str,"arg1 arg2 arg3 arg4"); 
	int i = 0,
	tokens = 0;	
	char **ar; 
	if((tokens=make1(str,&ar))==-1)
		fprintf(stderr,"\nFailed to construct  an argument array\n");
	else
		for(i=0;i<tokens;i++)
			printf("%d:%s\n",i, ar[i]);	
	//printf("%d",make1(str,&ar));
	
	return 0;
}

