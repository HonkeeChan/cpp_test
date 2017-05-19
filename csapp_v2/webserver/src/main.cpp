#include <iostream>
#include <string>
#include "../include/common.h"
#include "../include/handle.h"
#include "../include/hash_control.h"
#include "../utils/UUIDTools.h"

extern "C"{
    #include "../utils/csapp.h"
    #include <sys/epoll.h>
}

using namespace std;

/*
    习题11.8， 使用信号来回收子进程的资源
*/
void wait_child(int signo){
    //printf("handle child exit\n");
    if(signo == SIGCHLD){
        pid_t pid = -1;
        int status = -1;
        pid = Wait(&status);
        printf("child process: %d, exit status: %d\n", pid, status);
    }
}

HashControl gHashContorl;
void test();
int main(int argc, char** argv){
    int listenfd, connfd, port, clientlen;
    struct sockaddr_in clientaddr;

    if(argc != 2){
        fprintf(stderr, "usage: %s <port\n>", argv[0]);
    }

    test();
    
    port = atoi(argv[1]);
    listenfd = Open_listenfd(port);
    signal(SIGCHLD, wait_child);
    //习题11.13 忽略SIGPIPE信号
    signal(SIGPIPE, SIG_IGN);
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

void test(){
    int waiting;
    //gHashContorl.set("hello", "world");
    //printf("key hello, value: %s", gHashContorl.find("hello").c_str());
    //gHashContorl.set("241f70332cfc4067b696509d7fc46efe", "241f70332cfc4067b696509d7fc46efe");
    //cout << gHashContorl.find("241f70332cfc4067b696509d7fc46efe") << endl;;
    //cout << "uuid: " << utils::UUIDTools::GenUUID() << endl;
    //cin >> waiting;
}