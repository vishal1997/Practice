#include <stdio.h>
#include <unistd.h>
int main() {

	int p1,p2;
	p1=fork();
	p2=fork();
	
	if(p1==0 && p2==0) 
		execl("/bin/ls","ls","-l",NULL);
	else if(p1>0 && p2==0)
		execl("/bin/dir","dir",NULL);
	else if(p1==0 && p2>0)
		execl("/q3","",NULL);
	else if(p1>0 && p2>0)
		printf("all done\n");
	
	return 0;
}
