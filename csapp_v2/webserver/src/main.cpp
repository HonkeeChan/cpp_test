#include <iostream>
#include <string>
#include "../include/common.h"
#include "../include/handle.h"

extern "C"{
    #include "../utils/csapp.h"
    #include <sys/epoll.h>
}

using namespace std;



int main(int argc, char** argv){
    int listenfd, connfd, port, clientlen;
    struct sockaddr_in clientaddr;

    if(argc != 2){
        fprintf(stderr, "usage: %s <port\n>", argv[0]);
    }

    port = atoi(argv[1]);
    listenfd = Open_listenfd(port);

    while(1){
        clientlen = sizeof(clientaddr);
        printf("waiting for client\n");
        connfd = Accept(listenfd, (SA *)&clientaddr, 
            (socklen_t*)&clientlen);
        printf("accept client (%s, %d)\n", 
            inet_ntoa(clientaddr.sin_addr), 
            ntohs(clientaddr.sin_port));
        doit(connfd);
        Close(connfd);
    }
}