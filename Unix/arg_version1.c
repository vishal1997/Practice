#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char ** make(char *s) {

	char *token = strtok(s, " ");
	char **argument = (char **) malloc(strlen(s)*sizeof(char *));;
	int i=0;

	while (token != NULL) {
		argument[i] = (char *)malloc(10 * sizeof(char *));
		strcpy(argument[i],token);
		//printf("%s\n", argument[i]);
		token = strtok(NULL, " ");
		i++;
	}
	return argument;
}
int main() {

	char *str = (char *) malloc(20 * sizeof(char *));;
	strcpy(str,"arg1 arg2 arg3 arg4"); 
	int j = 0;/*
	while(str[j]!='\0') 
		printf("%c\n", str[j++]);*/
	char **s = make(str);
	int i=0;
	while(s[i] != NULL)
		printf("%s\n",s[i++]);
	free(s);
	free(str);
	return 0;
}

