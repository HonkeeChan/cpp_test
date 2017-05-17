#include "../include/handle.h"
#include "../include/common.h"
/*
    11.12
*/
void serve_post(int fd, char* filename, char* cgiargs, RequestHeadInfo& reqInfo){
    printf("serve_post, filename: %s\n", filename);

    char buf[MAXLINE], *emptylist[] = {NULL};
    sprintf(buf, "HTTP/1.0 200 OK\r\n"); 
    sprintf(buf, "%sServer: Tiny Web Server\r\n", buf);
    sprintf(buf, "%sContent-type: text/html\r\n", buf);
    Rio_writen(fd, buf, strlen(buf));

    if(Fork() == 0){
        setenv("QUERY_STRING", cgiargs, 1);
        Dup2(fd, STDOUT_FILENO);
        Execve(filename, emptylist, environ);
    }
    //Wait(NULL);
}

void decode_post_header(rio_t* rp, char* cgiargs, RequestHeadInfo& reqInfo){
    char buf[MAXLINE];
    int bodyLength = -1;

    printf("***************header*****************\n");
    decode_req_header(rp, reqInfo);
    sscanf(reqInfo.reqData[RequestHeaderName::Content_Length].c_str(), "Content-Length: %d", &bodyLength);

    printf("***************body*****************\n");
    size_t n = 0;
    char* pPostBody = cgiargs;
    int left = bodyLength;
    printf("left: %d\n", left);
    while(left != 0 && (n = Rio_readnb(rp, pPostBody, left))){
        pPostBody += n;
        left -= n;
        *pPostBody = '\0';
        printf("receive body: %s\n", cgiargs);
    }
    //pPostBody += n;
    //*pPostBody = '\0';
    
    printf("%s\n", cgiargs);
    return;
}

int parse_post_uri(char* uri, char* filename){
    printf("in parse_post_uri method, uri: %s\n", uri);
    if(strstr(uri, "/cgi-bin")){
        strcpy(filename, ".");
        strcat(filename, uri);
        return 0;
    }
    return -1;
}