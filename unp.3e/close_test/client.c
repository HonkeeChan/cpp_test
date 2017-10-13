#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct sockaddr SA;

int main(){
	int sockfd;
	socklen_t sock_len;
	struct sockaddr_in servaddr;
	char buf[1024];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("125.216.241.118");
	servaddr.sin_port = htons(1234);
	


	int ret;
	int cnt = 0;


	connect(sockfd, (SA*)&servaddr, sizeof(servaddr));
	for(;;){
		for(int i =0; i < 1023; ++i){
			buf[i] = '1';
		}
		buf[1023] = '\0';
		//sprintf(buf, "hello");
		ret = write(sockfd, buf, strlen(buf));
		if(ret < 0){
			perror("send error");
		}else{
			printf("send success, ret code: %d\n", ret);
		}
		memset(buf, 0, sizeof(buf));
		int len = read(sockfd, buf, sizeof(buf));
		if(len < 0){
			perror("recv error");
		}else{
			printf("recv %d bytes, %s\n", len, buf);	
		}


		
		sleep(100);
		len = read(sockfd, buf, sizeof(buf));
		if(len < 0){
			perror("recv error");
		}else{
			printf("recv %d bytes, %s\n", len, buf);	
		}

	}
	return 0;
}