#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <error.h>

int main()
{
	int fd;

	if((fd = creat("afile", S_IRUSR | S_IWUSR)) == -1)
		perror("afile");
	printf("This is displayed on the screen.\n");
	dup(fd);
	close(fd);
	printf("This is written into the redirected.\n");
	return 0;
}
