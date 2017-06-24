#include "UUIDTools.h"
#include <iostream>
namespace utils{


std::string UUIDTools::GenUUID(){
    uuid_t out;
    uuid_generate_random(out);
    int len = sizeof(uuid_t);
    std::string outStr;
    std::cout << "len: " << len<< std::endl;
    for(int i = 0;i < len; ++i){
        unsigned char* p = (unsigned char*)out + i;
        outStr += byte2hex(p);
        //std::cout<< i << ": " << byte2hex(p) << " ";
    }
    //std::cout << std::endl;
    return outStr;
}

std::string UUIDTools::byte2hex(unsigned char*p){
    std::string s;
    s += hextb[(unsigned char)(*p) >> 4];
    s += hextb[(*p) & 0x0F];
    return s;
}

}