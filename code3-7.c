#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFSIZE 512
#define FILESIZE (100 * 1024 * 1024)
#define COUNT FILESIZE / BUFFSIZE

void main() {
	int i,fd;
	char buf[BUFFSIZE];

	memset(buf, '.', BUFFSIZE);
	if ((fd=creat("file.write", S_IRUSR | S_IWUSR)) < 0)
		exit(1);

	for(i=0; i < COUNT; ++i)
		write(fd, buf, BUFFSIZE);

	close(fd);

	exit(0);
}
