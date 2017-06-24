#include <iostream>
#include <string>
#include "../include/common.h"
#include "../include/handle.h"
#include "../include/hash_control.h"
#include "../utils/UUIDTools.h"

extern "C"{
    #include "../utils/csapp.h"
    #include <sys/resource.h>
}

using namespace std;

HashControl gHashContorl;
struct mt_struct{
    int connfd;
    struct sockaddr_in clientaddr;
    int clientlen;
};
void test();
void init_limit();
void* mt_doit(void* arg);
int main(int argc, char** argv){
    int listenfd, connfd, port, clientlen;
    struct sockaddr_in clientaddr;

    if(argc != 2){
        fprintf(stderr, "usage: %s <port\n>", argv[0]);
    }
    init_limit();
    test();
    
    port = atoi(argv[1]);
    listenfd = Open_listenfd(port);
    //习题11.13 忽略SIGPIPE信号
    signal(SIGPIPE, SIG_IGN);
    while(1){
        clientlen = sizeof(clientaddr);
        printf("waiting for client\n");
        connfd = Accept(listenfd, (SA *)&clientaddr, 
            (socklen_t*)&clientlen);
        mt_struct* parg = new mt_struct;
        parg->connfd = connfd;
        parg->clientaddr = clientaddr;
        parg->clientlen = clientlen;
        pthread_t tid;
        pthread_create(&tid, NULL, mt_doit, (void*)parg);
        pthread_detach(tid);
        
    }
}

void* mt_doit(void* arg){
    mt_struct* parg = (mt_struct*)arg;
    int connfd = ((mt_struct*)arg)->connfd;
    printf("accept client (%s, %d)\n", 
            inet_ntoa(((mt_struct*)arg)->clientaddr.sin_addr), 
            ntohs(((mt_struct*)arg)->clientaddr.sin_port));
    int rc = doit(connfd);
    Close(connfd);
    //delete parg;
    return NULL;
}

void init_limit(){
    struct rlimit limit;
    limit.rlim_cur = 65536;
    limit.rlim_max = 65536;
    if(setrlimit(RLIMIT_NOFILE, &limit) < 0){
        return;
    }    
    printf("set openfile max success\n");
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
