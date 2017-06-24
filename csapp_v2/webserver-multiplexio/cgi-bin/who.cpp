extern "C"{
    #include "../utils/csapp.h"
}
#include "../include/handle.h"
#include "../utils/UUIDTools.h"
#include "../include/hash_control.h"
#include <string>

int main(void) {
    char *buf, *p;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
   
    std::string sessionid = utils::UUIDTools::GenUUID();
    bool hasSessionId = false;
    HashControl hs;
    
    strcpy(content, "<html>");
    if ((buf = getenv("COOKIE")) != NULL) {
        std::string cookie = std::string(buf);
        size_t idBegIdx = cookie.find("SESSIONID=");
        if(idBegIdx != std::string::npos){
            hasSessionId =  true;
            size_t idEndIdx = cookie.find_first_of(";", idBegIdx + 10);
            sessionid = cookie.substr(idBegIdx + 10, idEndIdx - idBegIdx - 10);
            std::string v = hs.get(sessionid);
            strcat(content, "username: ");
            strcat(content, v.c_str());
        }
        
    }
    strcat(content, "<a href=\"/view/home.html\">back</a>");
    strcat(content, "</html>");
    if(!hasSessionId)
        printf("Set-Cookie: SESSIONID=%s; Max-Age=60; Path=/\r\n", sessionid.c_str());
    printf("Content-type: text/html\r\n");
    
    printf("Content-length: %d\r\n\r\n", (int)strlen(content));
    
    //printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);
    exit(0);
}