#ifndef _HANDLE_H_
#define _HANDLE_H_

extern "C"{
	#include "../utils/csapp.h"
}


void doit(int fd);

void clienterror(int fd, const char *cause, const char *errnum, 
		 const char *shortmsg, const char *longmsg);


char* index(char* str, char c);

// in get_method.cpp

void decode_get_header(rio_t* rp);
void serve_static(int fd, char* filename, int filesize);
void serve_dynamic(int fd, char* filename, char* cgiargs);
void get_filetype(char* filename, char* filetype);
int parse_get_uri(char* uri, char* filename, char* cgiargs);

// in post_method.cpp
void serve_post(int fd, char* filename, char* cgiargs);
void decode_post_header(rio_t* rp, char* cgiargs);
int parse_post_uri(char* uri, char* filename);
#endif