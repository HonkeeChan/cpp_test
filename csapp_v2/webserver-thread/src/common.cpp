#include "../include/common.h"
#include "../utils/TimeTools.h"
extern "C"{
    #include "../utils/csapp.h"
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