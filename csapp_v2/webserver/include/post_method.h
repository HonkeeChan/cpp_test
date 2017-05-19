#ifndef _POST_METHOD_H_
#define _POST_METHOD_H_

#include "../include/common.h"
extern "C"{
	#include "../utils/csapp.h"
}
#include <string>

// in post_method.cpp
void serve_post(int fd, char* filename, char* cgiargs, RequestHeadInfo& reqInfo);
void decode_post_header(rio_t* rp, char* cgiargs, RequestHeadInfo& reqInfo);
int parse_post_uri(char* uri, char* filename);

#endif