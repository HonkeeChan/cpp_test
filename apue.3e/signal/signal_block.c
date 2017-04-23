
/*
此文件的作用是测试 调用信号处理函数时，会阻塞 调用sigaction的act结构体的sa_mask信号集和自己的信号，信号处理函数返回之后恢复。	
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

typedef void Sigfunc(int);
Sigfunc* signal(int signo, Sigfunc* func){
    struct sigaction act, oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_flags = 0;

    if(sigaction(signo, &act, &oact) < 0)
        return (SIG_ERR);
    return (oact.sa_handler);
}


void sig_quit(int signo);
void sig_inter(int signo);
int main(){
	sigset_t newmask, oldmask;
	if(signal(SIGQUIT, sig_quit) == SIG_ERR)
		printf("register signal error");
	if(signal(SIGINT, sig_inter	) == SIG_ERR)
		printf("register signal error");

	sleep(20);

	return 0;
}

void sig_quit(int signo){
	printf("in sig_quit handle function\n");
	if(signo == SIGQUIT){

		printf("caught SIGQUIT\n");
		printf("sleep 5 second in sigquit\n");
		sleep(5);
		printf("wakeup in sigquit\n");
	}
}

void sig_inter(int signo){
	printf("in sig_inter handle function\n");
	if(signo == SIGINT){
		printf("caught SIGINT\n");
		printf("sleep 5 second in sigint\n");
		sleep(5);
		printf("wakeup in sigint\n");
	}
}
