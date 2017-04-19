#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main(void){
    struct winsize size;
    if(isatty(STDOUT_FILENO) == 0)
        exit(1);
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0){
        perror("ioctl TIOCGWINSZ error");
        exit(1);
    }
    printf("%d rows, %d cols\n", size.ws_row, size.ws_col);
    return 0;
}
