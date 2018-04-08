#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main () {

	pid_t childpid = 0;
	int i, n=5;
	
	for (i = 1; i < n; i++)
		if (childpid = fork()) {
			wait(NULL);
			break;
		}
	
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld\n", i, (long)getpid(), (long)getppid());
	
	return 0;
}
