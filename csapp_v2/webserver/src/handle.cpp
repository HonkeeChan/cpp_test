#include <cstdlib>
#include "../include/handle.h"
extern "C"{
    #include "../utils/csapp.h"
}


void doit(int fd){
    int isStatic;
    struct stat fileStat;
    char buf[MAXLINE];
    char method[512], uri[1024], version[64];
    rio_t rio;
    Rio_readinitb(&rio, fd);
    Rio_readlineb(&rio, buf, MAXLINE);
    sscanf(buf, "%s %s %s", method, uri, version);
    printf("receive method: %s, uri: %s, version: %s\n", 
                    method, uri, version);

    if(strcasecmp(method, "GET") == 0){
        
        decode_get_header(&rio);

        char filename[512], cgiargs[512];
        isStatic = parse_get_uri(uri, filename, cgiargs);
        printf("parse_uri, filename: %s\n", filename);
        if(stat(filename, &fileStat) < 0){
            clienterror(fd, filename, "404", "Not found",
                "Tiny couldn't find this file");
            return;
        }

        if(isStatic){
            printf("S_ISREG: %d, S_IRUSR: %d\n", S_ISREG(fileStat.st_mode), S_IRUSR & fileStat.st_mode);
            if( !(S_ISREG(fileStat.st_mode) || !( S_IRUSR & fileStat.st_mode)) || (access(filename, R_OK) == -1) ){
                
                clienterror(fd, filename, "403", "Forbidden", 
                        "Tiny couldn't read the file");
                return;
            }
            serve_static(fd, filename, fileStat.st_size);
        }else{
            if( !(S_ISREG(fileStat.st_mode) || !( S_IRUSR & fileStat.st_mode)) || (access(filename, R_OK) == -1) ){
                clienterror(fd, filename, "403", "Forbidden", 
                        "Tiny couldn't read the file");
                return;
            }
            serve_dynamic(fd, filename, cgiargs);
        }
    }else if(strcasecmp(method, "HEAD") == 0){
        printf("handle head method\n");
        sprintf(buf, "HTTP/1.0 200 OK\r\n");
        sprintf(buf, "%sServer: Tiny Web Server\r\n\r\n", buf);

        Rio_writen(fd, buf, strlen(buf));

    }else if(strcasecmp(method, "POST") == 0){
        char filename[512], cgiargs[512];
        decode_post_header(&rio, cgiargs);

        if(parse_post_uri(uri, filename) < 0){
            clienterror(fd, filename, "403", "Forbidden", 
                        "Tiny couldn't read the file");
                return;
        } 
        printf("in post method, filename: %s\n", filename);
        if(stat(filename, &fileStat) < 0){
            clienterror(fd, filename, "404", "Not found",
                "Tiny couldn't find this file");
            return;
        }
        if( !(S_ISREG(fileStat.st_mode) || !( S_IRUSR & fileStat.st_mode)) || (access(filename, R_OK) == -1) ){
                clienterror(fd, filename, "403", "Forbidden", 
                        "Tiny couldn't read the file");
                return;
        }
        serve_post(fd, filename, cgiargs);

    }else{
        clienterror(fd, method, "501", "Not Implemented", 
            "does not implement this method");
        return;
    }
    
    
}



void clienterror(int fd, const char *cause, const char *errnum, 
		 const char *shortmsg, const char *longmsg) 
{
    char buf[MAXLINE], body[MAXBUF];

    /* Build the HTTP response body */
    sprintf(body, "<html><title>Tiny Error</title>");
    sprintf(body, "%s<body bgcolor=""ffffff"">\r\n", body);
    sprintf(body, "%s%s: %s\r\n", body, errnum, shortmsg);
    sprintf(body, "%s<p>%s: %s\r\n", body, longmsg, cause);
    sprintf(body, "%s<hr><em>The Tiny Web server</em>\r\n", body);

    /* Print the HTTP response */
    sprintf(buf, "HTTP/1.0 %s %s\r\n", errnum, shortmsg);
    Rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Content-type: text/html\r\n");
    Rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Content-length: %d\r\n\r\n", (int)strlen(body));
    Rio_writen(fd, buf, strlen(buf));
    Rio_writen(fd, body, strlen(body));
}


char* index(char* str, char c){
    while(*str != '\0'){
        if(*str == c){
            return str;
        }
        str++;
    }
    return NULL;
}