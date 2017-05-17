#include <cstdlib>
#include <string>
#include <memory>
#include <ctime>
#include <cstdio>
#include "../include/handle.h"
#include "../include/common.h"
#include "../utils/TimeTools.h"
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
        RequestHeadInfo reqInfo;
        decode_get_header(&rio, reqInfo);

        char filename[512], cgiargs[512];
        isStatic = parse_get_uri(uri, filename, cgiargs);
        printf("parse_uri, filename: %s\n", filename);
        if(stat(filename, &fileStat) < 0){
            clienterror(fd, filename, "404", "Not found",
                "Tiny couldn't find this file");
            return;
        }

        if(isStatic){
            //printf("S_ISREG: %d, S_IRUSR: %d\n", S_ISREG(fileStat.st_mode), S_IRUSR & fileStat.st_mode);
            if( !(S_ISREG(fileStat.st_mode) || !( S_IRUSR & fileStat.st_mode)) || (access(filename, R_OK) == -1) ){
                
                clienterror(fd, filename, "403", "Forbidden", 
                        "Tiny couldn't read the file");
                return;
            }
            serve_static(fd, filename, fileStat.st_size, reqInfo);
        }else{
            if( !(S_ISREG(fileStat.st_mode) || !( S_IRUSR & fileStat.st_mode)) || (access(filename, R_OK) == -1) ){
                clienterror(fd, filename, "403", "Forbidden", 
                        "Tiny couldn't read the file");
                return;
            }
            serve_dynamic(fd, filename, cgiargs, reqInfo);
        }
    }else if(strcasecmp(method, "HEAD") == 0){
        printf("handle head method\n");
        sprintf(buf, "HTTP/1.0 200 OK\r\n");
        sprintf(buf, "Last-Modified: Tue, 15 Nov 2010 12:45:26 GMT\r\n");
        sprintf(buf, "%sServer: Tiny Web Server\r\n\r\n", buf);
        
        Rio_writen(fd, buf, strlen(buf));

    }else if(strcasecmp(method, "POST") == 0){
        char filename[512], cgiargs[512];
        RequestHeadInfo reqInfo;
        decode_post_header(&rio, cgiargs, reqInfo);

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
        serve_post(fd, filename, cgiargs, reqInfo);

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

int cmpGMTStr(const std::string& s1, const std::string& s2){
    
    std::tm t1, t2;
    utils::TimeTools::parseGMTTime(s1, t1);
    utils::TimeTools::parseGMTTime(s2, t2);
    //utils::TimeTools::parseGMTTime("Wed, 17 May 2017 09:04:10 GMT", t1);
    //utils::TimeTools::parseGMTTime("Wed, 17 May 2017 10:04:10 GMT", t2);
    //char buffer[80];
    //strftime (buffer,80,"Now it's %c.",&t1);
    //printf("t1: %s\n", buffer);
    //strftime (buffer,80,"Now it's %c.",&t2);
    //printf("t2: %s\n", buffer);
    double d = difftime( mktime(&t1), mktime(&t2));
    //printf("s1: %s, s2: %s, d: %f",s1.c_str(), s2.c_str(),  d);
    if(d > 0 )
        return 1;
    else if(d < 0)
        return -1;
    return 0;
}

std::string parseIfModifiedSince(const std::string& s){
    char buf[MAXLINE];
    //printf("parse if modified since: %s", s.c_str());
    size_t idx = s.find("If-Modified-Since: ");
    if(idx != std::string::npos)
        return s.substr(idx + 19);
    return "";
}