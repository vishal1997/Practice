#include <errno.h>
#include <stdio.h>
#include <unistd.h>
int readline(int fd, char *buf, int nbytes) {
	
	int numread = 0;
	int returnval;
	
	while (numread < nbytes ) {
		
		returnval = read(fd, buf + numread, 1);
		if ((returnval == -1) && (errno == EINTR))
			continue;
		if ( (returnval == 0) && (numread == 0) )
			return 0;
		if (returnval == 0)
			break;
		if (returnval == -1)
			return -1;
		
		numread++;
		if (buf[numread-1] == '\n') {
			buf[numread] = '\0';
			return numread;
		}
	}
	errno = EINVAL;
	return -1;
}
int main() {
	
	char buf[100];
	int x=readline(0,buf,100);
	printf("\nString %s\n",buf);
}
