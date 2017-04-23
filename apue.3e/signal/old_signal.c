/*
系统自带的signal阻塞信号处理函数的信号，不阻塞其他信号，也不是调用信号处理函数之后就恢复默认处理。跟sigaction相比只是少了一些可控的设置而已。
	
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_int(int signo);

int main(){
	if(signal(SIGINT, sig_int) == SIG_ERR)
		printf("register sig int error");

	while(1){
		sleep(1);
	}
	
	return 0;
}

void sig_int(int signo){
	printf("in sig int handler function\n");
	sleep(5);
}
