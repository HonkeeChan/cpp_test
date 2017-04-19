#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#define MSG_TRY "try again\n"

int main(void)
{
    char buf[10];
    int fd, n;
    fd = open("/dev/tty", O_RDONLY|O_NONBLOCK); 
    int fd2 = open("/dev/tty", O_RDONLY); 
    if(fd<0) {
        perror("open /dev/tty");
        exit(1);
    } 
    if(fd2<0) {
        perror("open /dev/tty");
        exit(1);
    } 
tryagain:    
    n = read(fd, buf, 10); 

    if (n < 0) {
        if (errno == EAGAIN) {
            sleep(1);
            write(STDOUT_FILENO, MSG_TRY,strlen(MSG_TRY)); 
            goto tryagain;
        } 
        perror("read /dev/tty"); 
        exit(1);
    } 
    n = read(fd2, buf, 10); 
    printf("read from stdin %d", n);
    write(STDOUT_FILENO, buf, n); 
    n = read(STDIN_FILENO, buf, 10); 
    printf("read from stdin %d", n);
    write(STDOUT_FILENO, buf, n); 
    close(fd);
    return 0;
}