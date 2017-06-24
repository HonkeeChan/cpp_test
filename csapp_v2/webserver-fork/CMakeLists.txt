cmake_minimum_required (VERSION 2.6)
add_compile_options(-std=c++11)
cmake_policy(SET CMP0015 NEW)
project (webserver)

include_directories(

)

link_directories(
    /usr/local/lib
    ./lib
)

set(SRC_LIST 
    src/main.cpp
    src/handle.cpp
    src/get_method.cpp
    src/post_method.cpp
    src/cookie_handle.cpp
    src/hash_control.cpp
    src/common.cpp
    utils/TimeTools.cpp
    utils/FileTools.cpp
    utils/UUIDTools.cpp
    
)

add_executable(webserver ${SRC_LIST})

target_link_libraries(
    webserver 
    pthread
    memcached
    uuid
    csapp
)
