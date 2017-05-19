#ifndef _HANDLE_H_
#define _HANDLE_H_

#include "../include/common.h"
extern "C"{
	#include "../utils/csapp.h"
}
#include <string>

void doit(int fd);
void decode_req_header(rio_t*rp, RequestHeadInfo& reqInfo);
char* index(char* str, char c);


//in cookie_handle.cpp


#endif