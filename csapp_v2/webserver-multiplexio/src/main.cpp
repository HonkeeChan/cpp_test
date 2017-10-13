#include <iostream>
#include <string>
#include "../include/common.h"
#include "../include/handle.h"
#include "../include/hash_control.h"
#include "../utils/UUIDTools.h"
#include "../utils/SafeQueue.h"

extern "C"{
    #include<event.h>  
    #include<event2/util.h>
    #include "../utils/csapp.h"
    #include <sys/resource.h>
}

using namespace std;

#define N_THREAD 4

HashControl gHashContorl;
struct mt_struct{
    int connfd;
    struct sockaddr_in clientaddr;
    int clientlen;
};
void test();
void init_limit();
void OnAccept(int iListenfd, short iEvent, void*arg);
void OnDoit(int iConnfd, short iEvent, void* arg);
void OnDoItDispatch(int iListenfd, short iEvent, void* arg);
void* create_worker(void* arg);
void work_thread_factory();

struct thread_struct{
    pthread_t thread_id;
    struct event_base* work_process_base;
    int notify_send_fd;
    int notify_receive_fd;
    struct event notify_event;
    int tid;
};

struct event_base* listen_process_base;
utils::SafeQueue<mt_struct> clientInfoQue[N_THREAD - 1];
thread_struct threads[N_THREAD - 1];

int main(int argc, char** argv){
    int listenfd, port;

    if(argc != 2){
        fprintf(stderr, "usage: %s <port\n>", argv[0]);
    }
    init_limit();
    test();
    
    port = atoi(argv[1]);
    listenfd = Open_listenfd(port);
    //习题11.13 忽略SIGPIPE信号
    signal(SIGPIPE, SIG_IGN);
    
    listen_process_base = event_base_new(); 
    struct event evListen; 
    event_set(&evListen, listenfd, EV_READ|EV_PERSIST, OnAccept, NULL);  
    // 设置为base事件  
    event_base_set(listen_process_base, &evListen);  
    // 添加事件  
    event_add(&evListen, NULL);  

    work_thread_factory();
        
    // 事件循环  
    event_base_dispatch(listen_process_base);  
    
    return 0;  

}

void work_thread_factory(){
    for(int i = 0; i < N_THREAD - 1; ++i){
        threads[i].work_process_base = event_base_new();
        threads[i].tid = i;
        int fds[2];
        if(pipe(fds)){
            printf("Can't create pipe\n");   
        }
        threads[i].notify_receive_fd = fds[0];
        threads[i].notify_send_fd = fds[1];
        event_set(&threads[i].notify_event, threads[i].notify_receive_fd,
                EV_READ|EV_PERSIST, OnDoItDispatch, &threads[i]);  
        event_base_set(threads[i].work_process_base, &threads[i].notify_event);  
        event_add(&threads[i].notify_event, NULL);  

        pthread_create(&threads[i].thread_id, NULL, create_worker, &threads[i]);
    }
}

void* create_worker(void* arg){
    thread_struct* me = (thread_struct*)arg;
    printf("create worker\n");
    event_base_dispatch(me->work_process_base);
    printf("never come here\n");
    return NULL;
}


void OnDoItDispatch(int notifyRecvFd, short iEvent, void* arg){
    int tid = ((thread_struct*)arg)->tid;
    mt_struct clientInfo = clientInfoQue[tid].dequeue();
    char buf[5];
    // if(read(threads[tid].notify_receive_fd, buf, 5) < 0 ){
    //     printf("read pipe fail");
    // }
    
    printf("accept client (%s, %d), client connection fd: %d\n", 
            inet_ntoa(clientInfo.clientaddr.sin_addr), 
            ntohs(clientInfo.clientaddr.sin_port),
            clientInfo.connfd);
    printf("dispatch task to thread %d\n", tid);

    
    int retCode = 0;
    struct event *pEvRead = new event;  
    event_set(pEvRead, clientInfo.connfd, EV_READ|EV_PERSIST, OnDoit, pEvRead);  
    event_base_set(threads[tid].work_process_base, pEvRead);  
    retCode = event_add(pEvRead, NULL);
    printf("event_add return code: %d\n", retCode);
}

void OnAccept(int iListenfd, short iEvent, void*arg){
    struct sockaddr_in clientaddr;
    int clientlen = sizeof(clientaddr);
    int connfd = Accept(iListenfd, (SA *)&clientaddr, 
            (socklen_t*)&clientlen);
    printf("accept client (%s, %d), client connection fd: %d\n", 
            inet_ntoa(clientaddr.sin_addr), 
            ntohs(clientaddr.sin_port),
            connfd);

    static long cnt = 0;
    int work_thread_id = ++cnt % (N_THREAD - 1);
    mt_struct data = {connfd, clientaddr, clientlen};
    clientInfoQue[work_thread_id].enqueue(data);
    printf("thread %d: work for you\n", work_thread_id);

    if( write(threads[work_thread_id].notify_send_fd, " ", 1)  != 1){
        printf("notify work process error\n");
    }
    
}

void OnDoit(int iConnfd, short iEvent, void* arg){
    printf("on do it function\n");

    doit(iConnfd);

    struct event *pEvRead = (struct event*)arg;  
    event_del(pEvRead);  
    delete pEvRead;  
    close(iConnfd);  
    return;  
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
