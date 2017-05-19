#include "../include/handle.h"
#include "../utils/TimeTools.h"
#include "../utils/FileTools.h"
#include "../include/get_method.h"
#include <string>


void serve_static(int fd, char* filename, int filesize, RequestHeadInfo& reqInfo){
    int srcfd;
    char *srcp, filetype[MAXLINE], buf[MAXBUF];
    printf("serve_static filename: %s\n", filename);
    get_filetype(filename, filetype);
    
    std::string nowGMTStr = utils::TimeTools::getGMTimeNow();
    std::string fileModifiedTime = utils::FileTools::getFileModifyTimeLinux(filename);

    if(reqInfo.reqData[RequestHeaderName::If_Modify_Since].length() > 0 &&
        cmpGMTStr(parseIfModifiedSince(reqInfo.reqData[RequestHeaderName::If_Modify_Since]), 
                fileModifiedTime) >= 0){
        sprintf(buf, "HTTP/1.0 302 Not-Modified\r\n");
        sprintf(buf, "%sServer: Tiny Web Server\r\n", buf);
        sprintf(buf, "%sContent-type: %s\r\n", buf, filetype);
        sprintf(buf, "%sLast-Modified: %s\r\n\r\n", buf, fileModifiedTime.c_str());
        //sprintf(buf, "%sExpires: Thu, 27 Apr 2017 20:19:26 GMT\r\n", buf);
        Rio_writen(fd, buf, strlen(buf));
        return;
    }
    
    sprintf(buf, "HTTP/1.0 200 OK\r\n");
    sprintf(buf, "%sServer: Tiny Web Server\r\n", buf);
    sprintf(buf, "%sContent-type: %s\r\n", buf, filetype);
    sprintf(buf, "%sContent-length: %d\r\n", buf, filesize);
    //sprintf(buf, "%sCache-Control: max-age=30\r\n", buf);
    sprintf(buf, "%sLast-Modified: %s\r\n\r\n", buf, nowGMTStr.c_str());
    printf("response header:\r\n%s", buf);
    Rio_writen(fd, buf, strlen(buf));

    srcfd = Open(filename, O_RDONLY, 0);
    srcp = (char*)Mmap(0, filesize, PROT_READ, MAP_PRIVATE, srcfd, 0);
    Close(srcfd);
    Rio_writen(fd, srcp, filesize);
    Munmap(srcp, filesize);

}

void serve_dynamic(int fd, char* filename, char* cgiargs, RequestHeadInfo& reqInfo){
    printf("serve_dynamic, filename: %s\n", filename);

    char buf[MAXLINE], *emptylist[] = {NULL};
    sprintf(buf, "HTTP/1.0 200 OK\r\n"); 
    sprintf(buf, "%sServer: Tiny Web Server\r\n", buf);
    sprintf(buf, "%sContent-type: text/html\r\n", buf);
    Rio_writen(fd, buf, strlen(buf));

    if(Fork() == 0){
        setenv("QUERY_STRING", cgiargs, 1);
        if(reqInfo.reqData[RequestHeaderName::Cookie].length()> 0){
            setenv("COOKIE", reqInfo.reqData[RequestHeaderName::Cookie].c_str(), 1);
        }
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
    else if(strstr(filename, ".js"))
        strcpy(filetype, "application/javascript");
    else
        strcpy(filetype, "text/plain");
}

void decode_get_header(rio_t* rp, RequestHeadInfo& reqInfo){
    
    printf("***************header*****************\n");
    decode_req_header(rp, reqInfo);

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