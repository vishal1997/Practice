#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc,char *argv[]) {
	
	int fd1,r,wc=0,lc=0,cc=0;
	char buf[1];
	
	fd1=open(argv[1],O_RDONLY);
	r=read(fd1,buf,1);
	
	while(r) {
	
		if(buf[0] != ' ' && buf[0]!='\n') 
			cc++;
		if(buf[0] == ' ' || buf[0]=='\n') 
			wc++;
		if(buf[0] =='\n') 
			lc++;

		printf("%c  %d  %d  %d \n", buf[0], cc,wc,lc );
		r=read(fd1,buf,1);
	}
	printf("CC %d   WC  %d   LC %d", cc,wc,lc);
	return 0;
}
