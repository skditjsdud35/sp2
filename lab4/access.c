#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 512
#define MAXREAD 20
int main(int argc, char *argv[]){
	char fd;
	ssize_t wr;
	char buffer[BUFSIZE];
	char *message = "hello world\n";
	ssize_t nread;

	if(argc !=2)
		printf("usage : a.out <pathname>");

    	if(access(argv[1], F_OK)<0){
		if((fd=open(argv[1],O_RDWR|O_CREAT,0644))==-1){
			perror("open");
			exit(1);
		}
		if(write(fd, message, strlen(message))==-1){
			perror("write");
			exit(1);
		}				            }
		close(fd);
	}else{
		if((fd = open(argv[1],O_RDONLY))==-1){
			perror("open Error");
			exit(1);
		}else{
			if(read(fd, buffer, MAXREAD)==-1){
				perror("read Error");
				exit(1);
			 }else
				 printf("%s\n",buffer);	
		}
	}
}
