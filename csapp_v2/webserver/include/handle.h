#ifndef _HANDLE_H_
#define _HANDLE_H_

extern "C"{
	#include "../utils/csapp.h"
}


void doit(int fd);
void decodeHeader(rio_t* rp);
void clienterror(int fd, const char *cause, const char *errnum, 
		 const char *shortmsg, const char *longmsg);
int parse_uri(char* uri, char* filename, char* cgiargs);
char* index(char* str, char c);
void serve_static(int fd, char* filename, int filesize);
void serve_dynamic(int fd, char* filename, char* cgiargs);
void get_filetype(char* filename, char* filetype);
#endif