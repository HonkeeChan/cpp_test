#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(){
	char c = getchar();
	printf("read a small file\n");
	int fd = open("unique_ptr.cpp", O_RDONLY);
	char buf[4096];
	int len = read(fd, buf, 4096);
	printf("read unique_ptr.cpp, read %d bytes\n", len);

	printf("press any key to read a big file\n");
	c = getchar();
	fd = open("/home/honkee/Downloads/google-chrome-stable_current_amd64.deb", O_RDONLY);
	len = read(fd, buf, 4096);
	printf("read a big file, read %d bytes\n", len);

	printf("press any key to exit\n");
	c = getchar();
	return 0;
}