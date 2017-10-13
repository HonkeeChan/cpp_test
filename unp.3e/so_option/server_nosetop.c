#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>


typedef struct sockaddr SA;

int main(int argc, void* argv[]){
	if(argc < 3){
		printf("./exe ip port\n");
		return -1;
	}
	char* addr = (char*)argv[1];
	int port = atoi((char*)argv[2]);

	printf("server bind addr %s:%d\n", addr, port);

	int listenfd, connfd;
	socklen_t addr_len;
	int ret;
	struct sockaddr_in servaddr, cliaddr;
	char buf[1024];
	time_t ticks;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(addr);
	servaddr.sin_port = htons(port);

	int flag = 0;
	if( setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int)) == -1)  
    {  
        perror("setsockopt error");  
        exit(1);  
    }  

	ret = bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
	if(ret < 0){
		perror("bind error");  
	}
	ret = listen(listenfd, 2);
	if(ret < 0){
		perror("listen error"); 
	}

	int len;
	for(;;){
		addr_len = sizeof(cliaddr);
		if((connfd = accept(listenfd, (SA*)&cliaddr, &addr_len)) < 0){
			perror("accept error");
			continue;
		}
		printf("accept success, file descriptor: %d\n", connfd);

		//len = read(connfd, buf, sizeof(buf));
		//buf[10] = '\0';
		//printf("recv %d bytes, %s\n", len, buf);
		//len = read(connfd, buf, sizeof(buf));
		while((len = recv(connfd, buf, sizeof(buf), 0)) > 0){
			printf("recv %d bytes, %s\n", len, buf);
			send(connfd, buf, strlen(buf), 0);
		}
		perror("recv end");
		close(connfd);
		

	}
	return 0;
}