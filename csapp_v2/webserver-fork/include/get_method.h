#ifndef _GET_METHOD_H_
#define _GET_METHOD_H_

#include "../include/common.h"
extern "C"{
	#include "../utils/csapp.h"
}
#include <string>

// in get_method.cpp

void decode_get_header(rio_t* rp, RequestHeadInfo& reqInfo);
void serve_static(int fd, char* filename, int filesize, RequestHeadInfo& reqInfo);
void serve_dynamic(int fd, char* filename, char* cgiargs, RequestHeadInfo& reqInfo);
void get_filetype(char* filename, char* filetype);
int parse_get_uri(char* uri, char* filename, char* cgiargs);

#endif