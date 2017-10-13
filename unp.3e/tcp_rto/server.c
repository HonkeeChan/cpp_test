#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>


typedef struct sockaddr SA;

int main(){
	int listenfd, connfd;
	socklen_t addr_len;
	int ret;
	struct sockaddr_in servaddr, cliaddr;
	char buf[512];
	time_t ticks;
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(1234);
	ret = bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
	if(ret < 0){
		printf("bind error, error code: %d\n", ret);
	}
	ret = listen(listenfd, 2);
	if(ret < 0){
		printf("listen error, error code: %d\n", ret);
	}
	int len;
	for(;;){
ACCEPT:
		addr_len = sizeof(cliaddr);
		connfd = accept(listenfd, (SA*)&cliaddr, &len);
		printf("accept success\n");

		//len = read(connfd, buf, sizeof(buf));
		//buf[10] = '\0';
		//printf("recv %d bytes, %s\n", len, buf);
		//len = read(connfd, buf, sizeof(buf));
		while((len = recv(connfd, buf, sizeof(buf), 0)) > 0){
			printf("recv %d bytes, %s\n", len, buf);
			buf[len - 1] = '\0';
			//send(connfd, buf, strlen(buf), 0);
			//shutdown(connfd, SHUT_RDWR);
			//close(connfd);
			//printf("close fd\n");
			//goto ACCEPT;
		}
		printf("recv %d bytes\n", len);
		close(connfd);
		

	}
	return 0;
}