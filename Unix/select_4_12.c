#include <errno.h>
#include <string.h>
#include <sys/select.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
int whichisready(int fd1,int fd2) {

	int maxfd;
	int nfds;
	fd_set readset;
	struct timeval tv;
	
	printf("%d\n", FD_SETSIZE);
	
	if((fd1 <0) || (fd1 >= FD_SETSIZE) ||(fd2 <0) ||(fd2 >= FD_SETSIZE)) {
		errno=EINVAL;
		return -1;
	}
	tv.tv_sec=5;
	tv.tv_sec=0;

	maxfd=(fd1 >fd2) ? fd1:fd2;
	FD_ZERO(&readset);
	FD_SET(fd1,&readset);
	FD_SET(fd2,&readset);
	//write(1,&readset,100);
	nfds= select(maxfd+1,&readset,NULL,NULL,&tv);
	
	if(nfds == -1)
		return -1;
	if(FD_ISSET(fd1,&readset))
		return fd1;
	if(FD_ISSET(fd2,&readset))
		return fd2;

	errno=EINVAL;
	return -1;
}

int main() {

	int fd1=open("myfile2",O_RDONLY);
	int x=whichisready(0,fd1);
	printf("%d\n",x);
	return 0;
}
