#include "../include/hash_control.h"
#include <cstdio>
#include <vector>

std::string HashControl::find(std::string key){
    // memcached_return_t rc;
    // const char *keys[1];
    // keys[0] = key.c_str();
    // size_t key_length[1];
    // key_length[0] = key.length();
    // unsigned int x;
    // uint32_t flags;

    // char return_key[MEMCACHED_MAX_KEY];
    // size_t return_key_length;
    // char *return_value;
    // size_t return_value_length;

    // rc= memcached_mget(memc_, keys, key_length, 3);
    // if (rc != MEMCACHED_SUCCESS)
    // {
    //     const char * errMsg = memcached_last_error_message(memc_);
    //     printf("memcached get error: %s\n", errMsg);
    // }
    // x= 0;
    // while ((return_value= memcached_fetch(memc_, return_key, &return_key_length,
    //                                     &return_value_length, &flags, &rc)))
    // {
    //     //free(reget(return_value);
    //     return std::string(return_key);
    // }
    // return "";
    std::vector<char> vc;
    _m.get(key, vc);
    return std::string(vc.begin(), vc.end());
}

std::string HashControl::get(std::string key){
    return find(key);
}

void HashControl::set(std::string k, std::string v){
    
    // memcached_return_t rc= memcached_set(memc_, k.c_str(), k.length(), 
    //        v.c_str(), v.length(), (time_t)0, (uint32_t)0);
   

    // if (rc != MEMCACHED_SUCCESS)
    // {
    //     const char * errMsg = memcached_last_error_message(memc_);
    //     printf("memcached set error: %s\n", errMsg);
    // }
    time_t expiry= 0;
    uint32_t flags= 0;
    _m.set(k, v.c_str(), v.length(), expiry, flags);
}