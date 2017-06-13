#ifndef __UUID_TOOLS_H__
#define __UUID_TOOLS_H__
#include <uuid/uuid.h>
#include <string>
namespace utils{

const unsigned char hextb[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

class UUIDTools{
public:
    static std::string GenUUID();
private:
    static std::string byte2hex(unsigned char*p);
};

}
#endif