#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
int main() {
	
	int x;
	char buf[10];
	int fd=open("fileread.txt",O_RDONLY);
	
	do {
		x=read(fd,buf,10);
		write(STDOUT_FILENO,buf,x);
	} while(x);
}
