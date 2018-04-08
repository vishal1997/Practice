#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc,char *argv[]) {

	int fd1,fd2,r;
	char buf[100];
	
	fd1=open(argv[1],O_RDONLY);
	fd2=open(argv[2],O_CREAT|O_WRONLY,S_IRWXU);
	
	r=read(fd1,buf,100);
	write(fd2,buf,r);
	
	return 0;
}
