


#include "csapp.h"

void handler2(int sig){
    printf("in parent process handler function");
    pid_t pid;
    while((pid = waitpid(-1, NULL, 0)) > 0)
        printf("Handler reaped child %d\n", (int)pid);

    if(errno != ECHILD)
        unix_error("wait pid error");
    Sleep(2);
    return;
}
void handler1(int sig) 
{
    printf("in parent process handler function");
    pid_t pid;

    if ((pid = waitpid(-1, NULL, 0)) < 0)
    unix_error("waitpid error");
    printf("Handler reaped child %d\n", (int)pid);
    Sleep(2);
    return;
}

int main() 
{
    int i, n;
    char buf[MAXBUF];

    struct sigaction action, old_action;

    action.sa_handler = handler1;  
    sigemptyset(&action.sa_mask); /* block sigs of type being handled */
    action.sa_flags = SA_RESTART | SA_NODEFER; /* restart syscalls if possible */

    if (sigaction(SIGCHLD, &action, &old_action) < 0)
    unix_error("Signal error");


    /* Parent creates children */
    for (i = 0; i < 3; i++) {
        if (Fork() == 0) { 
            printf("Hello from child %d\n", (int)getpid());
            Sleep(i + 1);
            exit(0);
        }
    }

    /* Parent waits for terminal input and then processes it */
    if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
    unix_error("read");

    printf("Parent processing input\n");
    while (1)
    ; 

    exit(0);
}