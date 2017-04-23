#ifndef _COMMON_H_
#define _COMMON_H_

#include <signal.h>
const int fdMaxSize = 1000;
const int epollEventSize = 100;
typedef void Sigfunc(int);
Sigfunc* signal(int signo, Sigfunc* func){
    struct sigaction act, oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if(signo == SIGALRM){
#ifdef SA_INTERRUPT
       act.sa_flags |= SA_INTERRUPT;
#endif
    }else{
        act.sa_flags |= SA_RESTART;
    }
    if(sigaction(signo, &act, &oact) < 0)
        return (SIG_ERR);
    return (oact.sa_handler);
}

#endif