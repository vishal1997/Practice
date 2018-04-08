#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main () {

	pid_t childpid = 0;
	int i, n=5;
	int status = 0;
	for (i = 1; i < n; i++) {
		if ((i != 3) || (i != 4) ) {
			if(childpid = fork()) {
				break;
			}
		}
	}
	if( i!=3 && i != 4)
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld\n", i, (long)getpid(), (long)getppid());
	wait(NULL);
	if(i == 3) {
		for(i = 3; i <= 4; i++) {
			if(childpid = fork())
				break;
			
		}
		if(i != 5)
		fprintf(stderr, "i:%d process ID:%ld parent ID:%ld\n", i, (long)getpid(), (long)getppid());
	}
	return 0;
}

