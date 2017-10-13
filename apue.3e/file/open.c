#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
	int fd = open("tmp.txt", O_WRONLY);
	if(fd < 0){
		perror("open");
	}
	write(fd, "12345\n", 6);
	printf("sleep 10 second\n");
	sleep(10);
	close(fd);
	return 0;
}