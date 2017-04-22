cmake_minimum_required (VERSION 2.6)
add_compile_options(-std=c++11)
cmake_policy(SET CMP0015 NEW)
project (webserver)

include_directories(

)

link_directories(
)

set(SRC_LIST 
    src/main.cpp
    src/handle.cpp
    utils/csapp.c
)

add_executable(webserver ${SRC_LIST})

target_link_libraries(
    webserver 
    pthread
)
