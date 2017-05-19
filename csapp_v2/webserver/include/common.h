#ifndef _COMMON_H_
#define _COMMON_H_

#include <signal.h>
#include <vector>
#include <string>
#include <unordered_map>
const int fdMaxSize = 1000;
const int epollEventSize = 100;
typedef void Sigfunc(int);
// Sigfunc* signal(int signo, Sigfunc* func){
//     struct sigaction act, oact;
//     act.sa_handler = func;
//     sigemptyset(&act.sa_mask);
//     act.sa_flags = 0;
//     if(signo == SIGALRM){
// #ifdef SA_INTERRUPT
//        act.sa_flags |= SA_INTERRUPT;
// #endif
//     }else{
//         act.sa_flags |= SA_RESTART;
//     }
//     if(sigaction(signo, &act, &oact) < 0)
//         return (SIG_ERR);
//     return (oact.sa_handler);
// }

enum RequestHeaderName{
    Cache_Control = 0,
    Cookie,
    Connection,
    If_Modify_Since,
    Content_Length,
    Content_Type
};

/*
    这里只存储一部分头部字段，因为我后面打算实现这部分头部字段的功能
*/
class RequestHeadInfo{
public:
    RequestHeadInfo(){
        
    }
    std::unordered_map<int, std::string> reqData;
    //char* buf[6];
    ~RequestHeadInfo(){
        
    }

};

int cmpGMTStr(const std::string& s1, const std::string& s2);
std::string parseIfModifiedSince(const std::string& s);
void clienterror(int fd, const char *cause, const char *errnum, 
		 const char *shortmsg, const char *longmsg);



#endif