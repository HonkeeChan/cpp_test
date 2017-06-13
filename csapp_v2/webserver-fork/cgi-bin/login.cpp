extern "C"{
    #include "../utils/csapp.h"
}
#include "../include/handle.h"
#include "../utils/UUIDTools.h"
#include <string>

int main(void) {
    char *buf, *p;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
    int n1=0, n2=0;

    /* Extract the two arguments */
    if ((buf = getenv("QUERY_STRING")) != NULL) {
	//p = strchr(buf, '&');
	//*p = '\0';
    
    // /int i, j = 0;
    //printf("in adder, args: %s\n", buf);
        sscanf(buf, "add1=%d&add2=%d", &n1, &n2);

    }
    std::string sessionid;
    if ((buf = getenv("UUID")) != NULL) {
        sessionid = std::string(buf);
    }

    bool hasSessionId = false;
    if ((buf = getenv("COOKIE")) != NULL) {
        std::string cookie = std::string(buf);
        size_t idBegIdx = cookie.find("SESSIONID=");
        if(idBegIdx != std::string::npos){
            hasSessionId =  true;
            size_t idEndIdx = cookie.find_first_of(";", idBegIdx + 10);
            sessionid = cookie.substr(idBegIdx + 10, idEndIdx - idBegIdx - 10);
        }
        
    }
    
    int srcfd;
    char* srcp;

    if(n1 == 1){
        //login success

        //const char* filename = "/home/honkee/study/cpp/csapp_v2/webserver/view/home.html";
        const char* filename = "./view/home.html";
        struct stat fileStat;
        if(stat(filename, &fileStat) < 0){
            clienterror(STDOUT_FILENO, filename, "404", "Not found",
                "Tiny couldn't find this file");
            return 0;
        }
        if( !(S_ISREG(fileStat.st_mode) || !( S_IRUSR & fileStat.st_mode)) || (access(filename, R_OK) == -1) ){
                    
            clienterror(STDOUT_FILENO, filename, "403", "Forbidden", 
                    "Tiny couldn't read the file");
            return 0;
        }
        srcfd = Open(filename, O_RDONLY, 0);
        srcp = (char*)Mmap(0, fileStat.st_size, PROT_READ, MAP_PRIVATE, srcfd, 0);
        Close(srcfd);
        //Rio_writen(stdout, srcp, fileStat.st_size);
        memcpy(content, srcp, fileStat.st_size);
        content[fileStat.st_size] = '\0';
        Munmap(srcp, fileStat.st_size);

        
    }else{
        //login fails
        clienterror(STDOUT_FILENO, "login", "601", "Auth Fail", 
                    "Tiny Autharization fail");
        return 0;
    }
    /* Make the response body */
   
    /* Generate the HTTP response */
    //std::string sessionid = utils::UUIDTools::GenUUID();
    if(!hasSessionId)
        printf("Set-Cookie: SESSIONID=%s; Max-Age=60; Path=/\r\n", sessionid.c_str());
    printf("Content-type: text/html\r\n");
    
    printf("Content-length: %d\r\n\r\n", (int)strlen(content));
    
    //printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);
    exit(0);
}