#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <error.h>
#define BUFSIZE 512

int main(){

	int fd;
	char buf[BUFSIZE];

	if((fd = open("./test.txt", O_RDWR))==-1)
		perror("open");

	if(lseek(fd, 10, SEEK_SET)==-1)
		perror("leek10");

	if(read(fd, buf, BUFSIZE)==-1)
		perror("read10");

	printf("1차: %s\n",buf);

	memset(buf, '\0', BUFSIZE);
	if(lseek(fd, -6, SEEK_END)==-1)
		perror("lseek-5");

	if(read(fd, buf, BUFSIZE)==-1)
		perror("read-5");

	printf("2차: %s\n", buf);
	close(fd);
	return 0;
}
