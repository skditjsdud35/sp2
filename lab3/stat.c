#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <error.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	struct stat buf;
	struct tm *t;

	if(stat(argv[1],&buf)==-1){
		perror("open");
		exit(1);
	}

	printf("inode의 번호 : %d\n",buf.st_ino);
	t = localtime(&buf.st_mtime);
	printf("마지막 수정 시간 : %d-%02d-%02d %02d:%02d:%02d\n",
		t->tm_year+1900, t->tm_mon+1, t->tm_mday,
		t->tm_hour, t->tm_min, t->tm_sec);
	t = localtime(&buf.st_atime);
	printf("마지막 읽은 시간 : %d-%02d-%02d %02d:%02d:%02d\n",
		t->tm_year+1900, t->tm_mon+1, t->tm_mday,:wq:wq::
		t->tm_hour, t->tm_min, t->tm_sec);
}
