#include <cstdlib>
#include <string>
#include <memory>
#include <ctime>
#include <cstdio>
#include "../include/handle.h"
#include "../include/common.h"
#include "../utils/TimeTools.h"
#include "../include/get_method.h"
#include "../include/post_method.h"
extern "C"{
    #include "../utils/csapp.h"
}


int doit(int fd){
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
        RequestHeadInfo reqInfo;
        decode_get_header(&rio, reqInfo);

        char filename[512], cgiargs[512];
        isStatic = parse_get_uri(uri, filename, cgiargs);
        printf("parse_uri, filename: %s\n", filename);
        if(stat(filename, &fileStat) < 0){
            clienterror(fd, filename, "404", "Not found",
                "Tiny couldn't find this file");
            return 0;
        }

        if(isStatic){
            //printf("S_ISREG: %d, S_IRUSR: %d\n", S_ISREG(fileStat.st_mode), S_IRUSR & fileStat.st_mode);
            if( !(S_ISREG(fileStat.st_mode) || !( S_IRUSR & fileStat.st_mode)) || (access(filename, R_OK) == -1) ){
                
                clienterror(fd, filename, "403", "Forbidden", 
                        "Tiny couldn't read the file");
                return 0;
            }
            serve_static(fd, filename, fileStat.st_size, reqInfo);
            if(reqInfo.reqData[RequestHeaderName::Connection].length() > 0 &&
                reqInfo.reqData[RequestHeaderName::Connection].find("keep-alive") != std::string::npos){
                return 1;
            }
        }else{
            if( !(S_ISREG(fileStat.st_mode) || !( S_IRUSR & fileStat.st_mode)) || (access(filename, R_OK) == -1) ){
                clienterror(fd, filename, "403", "Forbidden", 
                        "Tiny couldn't read the file");
                return 0 ;
            }
            serve_dynamic(fd, filename, cgiargs, reqInfo);
            if(reqInfo.reqData[RequestHeaderName::Connection].length() > 0 &&
                reqInfo.reqData[RequestHeaderName::Connection].find("keep-alive") != std::string::npos){
                return 1;
            }
        }
    }else if(strcasecmp(method, "HEAD") == 0){
        printf("handle head method\n");
        sprintf(buf, "HTTP/1.0 200 OK\r\n");
        sprintf(buf, "Last-Modified: Tue, 15 Nov 2010 12:45:26 GMT\r\n");
        sprintf(buf, "%sServer: Tiny Web Server\r\n\r\n", buf);
        
        Rio_writen(fd, buf, strlen(buf));
        return 0;

    }else if(strcasecmp(method, "POST") == 0){
        char filename[512], cgiargs[512];
        RequestHeadInfo reqInfo;
        decode_post_header(&rio, cgiargs, reqInfo);

        if(parse_post_uri(uri, filename) < 0){
            clienterror(fd, filename, "403", "Forbidden", 
                        "Tiny couldn't read the file");
                return 0;
        } 
        printf("in post method, filename: %s\n", filename);
        if(stat(filename, &fileStat) < 0){
            clienterror(fd, filename, "404", "Not found",
                "Tiny couldn't find this file");
            return 0;
        }
        if( !(S_ISREG(fileStat.st_mode) || !( S_IRUSR & fileStat.st_mode)) || (access(filename, R_OK) == -1) ){
                clienterror(fd, filename, "403", "Forbidden", 
                        "Tiny couldn't read the file");
                return 0;
        }
        serve_post(fd, filename, cgiargs, reqInfo);
        if(reqInfo.reqData[RequestHeaderName::Connection].length() > 0 &&
            reqInfo.reqData[RequestHeaderName::Connection].find("keep-alive") != std::string::npos){
            return 1;
        }

    }else{
        clienterror(fd, method, "501", "Not Implemented", 
            "does not implement this method");
        return 0;
    }
    
    //Close(fd);
    return 0;
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

void decode_req_header(rio_t*rp, RequestHeadInfo& reqInfo){
    char buf[MAXLINE];

    Rio_readlineb(rp, buf, MAXLINE);
    
    while(strcmp(buf, "\r\n")){
        printf("%s", buf);
        Rio_readlineb(rp, buf, MAXLINE);
        if(strstr(buf, "Content-Length:")){
            reqInfo.reqData[RequestHeaderName::Content_Length] = 
               std::string(buf);
        }else if(strstr(buf, "Cache-Control:")){
            reqInfo.reqData[RequestHeaderName::Cache_Control] = 
                std::string(buf);
        }else if(strstr(buf, "Cookie:")){
            reqInfo.reqData[RequestHeaderName::Cookie] = 
                std::string(buf);
        }else if(strstr(buf, "Connection:")){
            reqInfo.reqData[RequestHeaderName::Connection] = 
                std::string(buf);
        }else if(strstr(buf, "Content-Type:")){
            reqInfo.reqData[RequestHeaderName::Content_Type] = 
                std::string(buf);
        }else if(strstr(buf, "If-Modified-Since:")){
            reqInfo.reqData[RequestHeaderName::If_Modify_Since] = 
                std::string(buf);
        }

    }

    
}

