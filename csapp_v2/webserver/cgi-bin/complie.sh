#!/bin/bash

g++ --std=c++11 -o login login.cpp ../utils/UUIDTools.cpp \
../utils/TimeTools.cpp  \
../src/common.cpp ../utils/FileTools.cpp \
-L. -lcsapp -lpthread -luuid

g++ --std=c++11 -o who who.cpp ../utils/UUIDTools.cpp \
../utils/TimeTools.cpp  \
../src/common.cpp ../utils/FileTools.cpp ../src/hash_control.cpp \
-L. -lcsapp -lpthread -luuid -lmemcached
