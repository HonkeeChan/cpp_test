#ifndef __HASH_CONTROL_H
#define __HASH_CONTROL_H
#include <unordered_map>
#include <string>
//#include <libmemcached/memcached.h>
#include <libmemcached/memcached.hpp>
#include <cstdio>

class HashControl{
public:
    HashControl(): _m("127.0.0.1", 11211){
       
    }
    // HashControl(){
    //    memc_= memcached(NULL, 0);
    //     if (memc_)
    //     {
    //         memcached_server_add(memc_, "127.0.0.1", 11211);
    //     }
    // }
    ~ HashControl(){
    }
    std::string find(std::string key);
    std::string get(std::string key);
    void set(std::string key, std::string val);
private:
    //std::unordered_map<std::string, std::string> _hashMap;

    memcache::Memcache _m;
    //memcached_st *memc_;
};
#endif