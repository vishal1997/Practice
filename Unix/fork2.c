#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main (int argc, char *argv[]) {

	pid_t childpid = 0;
	int i, n;
	int status;
	n = 5;
	for (i = 1; i < n; i++)
		if ((childpid = fork()) <= 0) {
			break;
		}
	fprintf(stderr, "i:%d= I am process %ld, my parent is %ld\n",(int)i,(long)getpid(), (long)getppid());
	return 0;
}
