#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {

	pid_t childpid;
	int i, n;
	pid_t waitreturn;

	n = 4;
	childpid = fork();
	
	if(childpid <= 0) {
		
		for (i = 1; i < n; i++)
			if (childpid = fork())
				break;		
		if( i == 2 ) {
	
			wait(NULL);
			int k=0;
			while(k<3) {
			
				childpid = fork();
				fprintf(stderr, "I am process %ld, my parent is %ld\n",(long)getpid(), (long)getppid());
				if(childpid == 0) 
					kill(getpid(),SIGKILL);	
				k++;	
			}
		} else {
			wait(NULL);
			fprintf(stderr, "I am process %ld, my parent is %ld\n",(long)getpid(), (long)getppid());
		}
	} else {
		sleep(2);
		wait(NULL);
		fprintf(stderr, "I am process %ld, my parent is %ld\n",(long)getpid(), (long)getppid());
	}
	return 0;
}
