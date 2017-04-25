#include "../include/handle.h"

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

void decode_get_header(rio_t* rp){
    char buf[MAXLINE];

    Rio_readlineb(rp, buf, MAXLINE);
    while(strcmp(buf, "\r\n")){
        Rio_readlineb(rp, buf, MAXLINE);
        printf("%s", buf);
    }
    return;
}

int parse_get_uri(char* uri, char* filename, char* cgiargs){
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