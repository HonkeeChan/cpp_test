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
    if(strcasecmp(method, "GET")){
        clienterror(fd, method, "501", "Not Implemented", 
            "does not implement this method");
        return;
    }
    
    printf("receive method: %s, uri: %s, version: %s\n", 
                    method, uri, version);
    decodeHeader(&rio);

    char filename[512], cgiargs[512];
    isStatic = parse_uri(uri, filename, cgiargs);
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
}

void decodeHeader(rio_t* rp){
    char buf[MAXLINE];

    Rio_readlineb(rp, buf, MAXLINE);
    while(strcmp(buf, "\r\n")){
        Rio_readlineb(rp, buf, MAXLINE);
        printf("%s", buf);
    }
    return;
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

int parse_uri(char* uri, char* filename, char* cgiargs){
    if(!strstr(uri, "/cgi-bin")){
        strcpy(cgiargs, "");
        strcpy(filename, ".");
        strcat(filename, uri);
        if(filename[strlen(filename) - 1] == '/'){
            strcat(filename, "home.html");
        }
        return 1;
    }else{
        char* ptr = index(uri, '?');
        if(ptr){
            strcpy(cgiargs, ptr + 1);
            *ptr = '\0';
        }else{
            strcpy(cgiargs, "");
        }
        strcpy(filename, ".");
        strcat(filename, uri);
        return 0;
    }

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

void serve_static(int fd, char* filename, int filesize){
    int srcfd;
    char *srcp, filetype[MAXLINE], buf[MAXBUF];
    printf("serve_static filename: %s\n", filename);
    get_filetype(filename, filetype);
    sprintf(buf, "HTTP/1.0 200 OK\r\n");
    sprintf(buf, "%sServer: Tiny Web Server\r\n", buf);
    sprintf(buf, "%sContent-length: %d\r\n", buf, filesize);
    sprintf(buf, "%sContent-type: %s\r\n\r\n", buf, filetype);

    Rio_writen(fd, buf, strlen(buf));

    srcfd = Open(filename, O_RDONLY, 0);
    srcp = (char*)Mmap(0, filesize, PROT_READ, MAP_PRIVATE, srcfd, 0);
    Close(srcfd);
    Rio_writen(fd, srcp, filesize);
    Munmap(srcp, filesize);

}

void serve_dynamic(int fd, char* filename, char* cgiargs){
    printf("serve_dynamic, filename: %s\n", filename);

    char buf[MAXLINE], *emptylist[] = {NULL};
    sprintf(buf, "HTTP/1.0 200 OK\r\n"); 
    sprintf(buf, "%sServer: Tiny Web Server\r\n", buf);
    Rio_writen(fd, buf, strlen(buf));

    if(Fork() == 0){
        setenv("QUERY_STRING", cgiargs, 1);
        Dup2(fd, STDOUT_FILENO);
        Execve(filename, emptylist, environ);
    }
    //Wait(NULL);
}

/*
    习题11.7, Content-type 中添加video后，浏览器会打开播放器播放视频文件。
*/
void get_filetype(char* filename, char* filetype){
    if(strstr(filename, ".html"))
        strcpy(filetype, "text/html");
    else if(strstr(filename, ".gif"))
        strcpy(filename, "image/gif");
    else if(strstr(filename, ".jpg"))
        strcpy(filetype, "image/jpeg");
    else if(strstr(filename, ".avi"))
        strcpy(filetype, "video/avi");
    else if(strstr(filename, ".flv"))
        strcpy(filetype, "video/flv");
    else if(strstr(filename, ".mpg"))
        strcpy(filetype, "video/mpeg");
    else if(strstr(filename, ".mpeg"))
        strcpy(filetype, "video/mpeg");
    else if(strstr(filename, ".wmv"))
        strcpy(filetype, "video/wmv");
    else if(strstr(filename, ".mp4"))
        strcpy(filetype, "video/mp4");
    else
        strcpy(filetype, "text/plain");
}