# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/honkee/study/cpp/csapp_v2/webserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/honkee/study/cpp/csapp_v2/webserver/build

# Include any dependencies generated for this target.
include CMakeFiles/webserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/webserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/webserver.dir/flags.make

CMakeFiles/webserver.dir/src/main.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/webserver.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/main.cpp.o -c /home/honkee/study/cpp/csapp_v2/webserver/src/main.cpp

CMakeFiles/webserver.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honkee/study/cpp/csapp_v2/webserver/src/main.cpp > CMakeFiles/webserver.dir/src/main.cpp.i

CMakeFiles/webserver.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honkee/study/cpp/csapp_v2/webserver/src/main.cpp -o CMakeFiles/webserver.dir/src/main.cpp.s

CMakeFiles/webserver.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/webserver.dir/src/main.cpp.o.requires

CMakeFiles/webserver.dir/src/main.cpp.o.provides: CMakeFiles/webserver.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver.dir/build.make CMakeFiles/webserver.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/webserver.dir/src/main.cpp.o.provides

CMakeFiles/webserver.dir/src/main.cpp.o.provides.build: CMakeFiles/webserver.dir/src/main.cpp.o


CMakeFiles/webserver.dir/src/handle.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/handle.cpp.o: ../src/handle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/webserver.dir/src/handle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/handle.cpp.o -c /home/honkee/study/cpp/csapp_v2/webserver/src/handle.cpp

CMakeFiles/webserver.dir/src/handle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/handle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honkee/study/cpp/csapp_v2/webserver/src/handle.cpp > CMakeFiles/webserver.dir/src/handle.cpp.i

CMakeFiles/webserver.dir/src/handle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/handle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honkee/study/cpp/csapp_v2/webserver/src/handle.cpp -o CMakeFiles/webserver.dir/src/handle.cpp.s

CMakeFiles/webserver.dir/src/handle.cpp.o.requires:

.PHONY : CMakeFiles/webserver.dir/src/handle.cpp.o.requires

CMakeFiles/webserver.dir/src/handle.cpp.o.provides: CMakeFiles/webserver.dir/src/handle.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver.dir/build.make CMakeFiles/webserver.dir/src/handle.cpp.o.provides.build
.PHONY : CMakeFiles/webserver.dir/src/handle.cpp.o.provides

CMakeFiles/webserver.dir/src/handle.cpp.o.provides.build: CMakeFiles/webserver.dir/src/handle.cpp.o


CMakeFiles/webserver.dir/src/get_method.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/get_method.cpp.o: ../src/get_method.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/webserver.dir/src/get_method.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/get_method.cpp.o -c /home/honkee/study/cpp/csapp_v2/webserver/src/get_method.cpp

CMakeFiles/webserver.dir/src/get_method.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/get_method.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honkee/study/cpp/csapp_v2/webserver/src/get_method.cpp > CMakeFiles/webserver.dir/src/get_method.cpp.i

CMakeFiles/webserver.dir/src/get_method.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/get_method.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honkee/study/cpp/csapp_v2/webserver/src/get_method.cpp -o CMakeFiles/webserver.dir/src/get_method.cpp.s

CMakeFiles/webserver.dir/src/get_method.cpp.o.requires:

.PHONY : CMakeFiles/webserver.dir/src/get_method.cpp.o.requires

CMakeFiles/webserver.dir/src/get_method.cpp.o.provides: CMakeFiles/webserver.dir/src/get_method.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver.dir/build.make CMakeFiles/webserver.dir/src/get_method.cpp.o.provides.build
.PHONY : CMakeFiles/webserver.dir/src/get_method.cpp.o.provides

CMakeFiles/webserver.dir/src/get_method.cpp.o.provides.build: CMakeFiles/webserver.dir/src/get_method.cpp.o


CMakeFiles/webserver.dir/src/post_method.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/post_method.cpp.o: ../src/post_method.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/webserver.dir/src/post_method.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/post_method.cpp.o -c /home/honkee/study/cpp/csapp_v2/webserver/src/post_method.cpp

CMakeFiles/webserver.dir/src/post_method.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/post_method.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honkee/study/cpp/csapp_v2/webserver/src/post_method.cpp > CMakeFiles/webserver.dir/src/post_method.cpp.i

CMakeFiles/webserver.dir/src/post_method.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/post_method.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honkee/study/cpp/csapp_v2/webserver/src/post_method.cpp -o CMakeFiles/webserver.dir/src/post_method.cpp.s

CMakeFiles/webserver.dir/src/post_method.cpp.o.requires:

.PHONY : CMakeFiles/webserver.dir/src/post_method.cpp.o.requires

CMakeFiles/webserver.dir/src/post_method.cpp.o.provides: CMakeFiles/webserver.dir/src/post_method.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver.dir/build.make CMakeFiles/webserver.dir/src/post_method.cpp.o.provides.build
.PHONY : CMakeFiles/webserver.dir/src/post_method.cpp.o.provides

CMakeFiles/webserver.dir/src/post_method.cpp.o.provides.build: CMakeFiles/webserver.dir/src/post_method.cpp.o


CMakeFiles/webserver.dir/src/cookie_handle.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/cookie_handle.cpp.o: ../src/cookie_handle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/webserver.dir/src/cookie_handle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/cookie_handle.cpp.o -c /home/honkee/study/cpp/csapp_v2/webserver/src/cookie_handle.cpp

CMakeFiles/webserver.dir/src/cookie_handle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/cookie_handle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honkee/study/cpp/csapp_v2/webserver/src/cookie_handle.cpp > CMakeFiles/webserver.dir/src/cookie_handle.cpp.i

CMakeFiles/webserver.dir/src/cookie_handle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/cookie_handle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honkee/study/cpp/csapp_v2/webserver/src/cookie_handle.cpp -o CMakeFiles/webserver.dir/src/cookie_handle.cpp.s

CMakeFiles/webserver.dir/src/cookie_handle.cpp.o.requires:

.PHONY : CMakeFiles/webserver.dir/src/cookie_handle.cpp.o.requires

CMakeFiles/webserver.dir/src/cookie_handle.cpp.o.provides: CMakeFiles/webserver.dir/src/cookie_handle.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver.dir/build.make CMakeFiles/webserver.dir/src/cookie_handle.cpp.o.provides.build
.PHONY : CMakeFiles/webserver.dir/src/cookie_handle.cpp.o.provides

CMakeFiles/webserver.dir/src/cookie_handle.cpp.o.provides.build: CMakeFiles/webserver.dir/src/cookie_handle.cpp.o


CMakeFiles/webserver.dir/src/hash_control.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/hash_control.cpp.o: ../src/hash_control.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/webserver.dir/src/hash_control.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/hash_control.cpp.o -c /home/honkee/study/cpp/csapp_v2/webserver/src/hash_control.cpp

CMakeFiles/webserver.dir/src/hash_control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/hash_control.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honkee/study/cpp/csapp_v2/webserver/src/hash_control.cpp > CMakeFiles/webserver.dir/src/hash_control.cpp.i

CMakeFiles/webserver.dir/src/hash_control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/hash_control.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honkee/study/cpp/csapp_v2/webserver/src/hash_control.cpp -o CMakeFiles/webserver.dir/src/hash_control.cpp.s

CMakeFiles/webserver.dir/src/hash_control.cpp.o.requires:

.PHONY : CMakeFiles/webserver.dir/src/hash_control.cpp.o.requires

CMakeFiles/webserver.dir/src/hash_control.cpp.o.provides: CMakeFiles/webserver.dir/src/hash_control.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver.dir/build.make CMakeFiles/webserver.dir/src/hash_control.cpp.o.provides.build
.PHONY : CMakeFiles/webserver.dir/src/hash_control.cpp.o.provides

CMakeFiles/webserver.dir/src/hash_control.cpp.o.provides.build: CMakeFiles/webserver.dir/src/hash_control.cpp.o


CMakeFiles/webserver.dir/src/common.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/common.cpp.o: ../src/common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/webserver.dir/src/common.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/common.cpp.o -c /home/honkee/study/cpp/csapp_v2/webserver/src/common.cpp

CMakeFiles/webserver.dir/src/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/common.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honkee/study/cpp/csapp_v2/webserver/src/common.cpp > CMakeFiles/webserver.dir/src/common.cpp.i

CMakeFiles/webserver.dir/src/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/common.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honkee/study/cpp/csapp_v2/webserver/src/common.cpp -o CMakeFiles/webserver.dir/src/common.cpp.s

CMakeFiles/webserver.dir/src/common.cpp.o.requires:

.PHONY : CMakeFiles/webserver.dir/src/common.cpp.o.requires

CMakeFiles/webserver.dir/src/common.cpp.o.provides: CMakeFiles/webserver.dir/src/common.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver.dir/build.make CMakeFiles/webserver.dir/src/common.cpp.o.provides.build
.PHONY : CMakeFiles/webserver.dir/src/common.cpp.o.provides

CMakeFiles/webserver.dir/src/common.cpp.o.provides.build: CMakeFiles/webserver.dir/src/common.cpp.o


CMakeFiles/webserver.dir/utils/csapp.c.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/utils/csapp.c.o: ../utils/csapp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/webserver.dir/utils/csapp.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/webserver.dir/utils/csapp.c.o   -c /home/honkee/study/cpp/csapp_v2/webserver/utils/csapp.c

CMakeFiles/webserver.dir/utils/csapp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/webserver.dir/utils/csapp.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/honkee/study/cpp/csapp_v2/webserver/utils/csapp.c > CMakeFiles/webserver.dir/utils/csapp.c.i

CMakeFiles/webserver.dir/utils/csapp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/webserver.dir/utils/csapp.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/honkee/study/cpp/csapp_v2/webserver/utils/csapp.c -o CMakeFiles/webserver.dir/utils/csapp.c.s

CMakeFiles/webserver.dir/utils/csapp.c.o.requires:

.PHONY : CMakeFiles/webserver.dir/utils/csapp.c.o.requires

CMakeFiles/webserver.dir/utils/csapp.c.o.provides: CMakeFiles/webserver.dir/utils/csapp.c.o.requires
	$(MAKE) -f CMakeFiles/webserver.dir/build.make CMakeFiles/webserver.dir/utils/csapp.c.o.provides.build
.PHONY : CMakeFiles/webserver.dir/utils/csapp.c.o.provides

CMakeFiles/webserver.dir/utils/csapp.c.o.provides.build: CMakeFiles/webserver.dir/utils/csapp.c.o


CMakeFiles/webserver.dir/utils/TimeTools.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/utils/TimeTools.cpp.o: ../utils/TimeTools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/webserver.dir/utils/TimeTools.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/utils/TimeTools.cpp.o -c /home/honkee/study/cpp/csapp_v2/webserver/utils/TimeTools.cpp

CMakeFiles/webserver.dir/utils/TimeTools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/utils/TimeTools.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honkee/study/cpp/csapp_v2/webserver/utils/TimeTools.cpp > CMakeFiles/webserver.dir/utils/TimeTools.cpp.i

CMakeFiles/webserver.dir/utils/TimeTools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/utils/TimeTools.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honkee/study/cpp/csapp_v2/webserver/utils/TimeTools.cpp -o CMakeFiles/webserver.dir/utils/TimeTools.cpp.s

CMakeFiles/webserver.dir/utils/TimeTools.cpp.o.requires:

.PHONY : CMakeFiles/webserver.dir/utils/TimeTools.cpp.o.requires

CMakeFiles/webserver.dir/utils/TimeTools.cpp.o.provides: CMakeFiles/webserver.dir/utils/TimeTools.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver.dir/build.make CMakeFiles/webserver.dir/utils/TimeTools.cpp.o.provides.build
.PHONY : CMakeFiles/webserver.dir/utils/TimeTools.cpp.o.provides

CMakeFiles/webserver.dir/utils/TimeTools.cpp.o.provides.build: CMakeFiles/webserver.dir/utils/TimeTools.cpp.o


CMakeFiles/webserver.dir/utils/FileTools.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/utils/FileTools.cpp.o: ../utils/FileTools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/webserver.dir/utils/FileTools.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/utils/FileTools.cpp.o -c /home/honkee/study/cpp/csapp_v2/webserver/utils/FileTools.cpp

CMakeFiles/webserver.dir/utils/FileTools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/utils/FileTools.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honkee/study/cpp/csapp_v2/webserver/utils/FileTools.cpp > CMakeFiles/webserver.dir/utils/FileTools.cpp.i

CMakeFiles/webserver.dir/utils/FileTools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/utils/FileTools.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honkee/study/cpp/csapp_v2/webserver/utils/FileTools.cpp -o CMakeFiles/webserver.dir/utils/FileTools.cpp.s

CMakeFiles/webserver.dir/utils/FileTools.cpp.o.requires:

.PHONY : CMakeFiles/webserver.dir/utils/FileTools.cpp.o.requires

CMakeFiles/webserver.dir/utils/FileTools.cpp.o.provides: CMakeFiles/webserver.dir/utils/FileTools.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver.dir/build.make CMakeFiles/webserver.dir/utils/FileTools.cpp.o.provides.build
.PHONY : CMakeFiles/webserver.dir/utils/FileTools.cpp.o.provides

CMakeFiles/webserver.dir/utils/FileTools.cpp.o.provides.build: CMakeFiles/webserver.dir/utils/FileTools.cpp.o


CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o: ../utils/UUIDTools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o -c /home/honkee/study/cpp/csapp_v2/webserver/utils/UUIDTools.cpp

CMakeFiles/webserver.dir/utils/UUIDTools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/utils/UUIDTools.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honkee/study/cpp/csapp_v2/webserver/utils/UUIDTools.cpp > CMakeFiles/webserver.dir/utils/UUIDTools.cpp.i

CMakeFiles/webserver.dir/utils/UUIDTools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/utils/UUIDTools.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honkee/study/cpp/csapp_v2/webserver/utils/UUIDTools.cpp -o CMakeFiles/webserver.dir/utils/UUIDTools.cpp.s

CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o.requires:

.PHONY : CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o.requires

CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o.provides: CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver.dir/build.make CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o.provides.build
.PHONY : CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o.provides

CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o.provides.build: CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o


# Object files for target webserver
webserver_OBJECTS = \
"CMakeFiles/webserver.dir/src/main.cpp.o" \
"CMakeFiles/webserver.dir/src/handle.cpp.o" \
"CMakeFiles/webserver.dir/src/get_method.cpp.o" \
"CMakeFiles/webserver.dir/src/post_method.cpp.o" \
"CMakeFiles/webserver.dir/src/cookie_handle.cpp.o" \
"CMakeFiles/webserver.dir/src/hash_control.cpp.o" \
"CMakeFiles/webserver.dir/src/common.cpp.o" \
"CMakeFiles/webserver.dir/utils/csapp.c.o" \
"CMakeFiles/webserver.dir/utils/TimeTools.cpp.o" \
"CMakeFiles/webserver.dir/utils/FileTools.cpp.o" \
"CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o"

# External object files for target webserver
webserver_EXTERNAL_OBJECTS =

webserver: CMakeFiles/webserver.dir/src/main.cpp.o
webserver: CMakeFiles/webserver.dir/src/handle.cpp.o
webserver: CMakeFiles/webserver.dir/src/get_method.cpp.o
webserver: CMakeFiles/webserver.dir/src/post_method.cpp.o
webserver: CMakeFiles/webserver.dir/src/cookie_handle.cpp.o
webserver: CMakeFiles/webserver.dir/src/hash_control.cpp.o
webserver: CMakeFiles/webserver.dir/src/common.cpp.o
webserver: CMakeFiles/webserver.dir/utils/csapp.c.o
webserver: CMakeFiles/webserver.dir/utils/TimeTools.cpp.o
webserver: CMakeFiles/webserver.dir/utils/FileTools.cpp.o
webserver: CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o
webserver: CMakeFiles/webserver.dir/build.make
webserver: CMakeFiles/webserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable webserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/webserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/webserver.dir/build: webserver

.PHONY : CMakeFiles/webserver.dir/build

CMakeFiles/webserver.dir/requires: CMakeFiles/webserver.dir/src/main.cpp.o.requires
CMakeFiles/webserver.dir/requires: CMakeFiles/webserver.dir/src/handle.cpp.o.requires
CMakeFiles/webserver.dir/requires: CMakeFiles/webserver.dir/src/get_method.cpp.o.requires
CMakeFiles/webserver.dir/requires: CMakeFiles/webserver.dir/src/post_method.cpp.o.requires
CMakeFiles/webserver.dir/requires: CMakeFiles/webserver.dir/src/cookie_handle.cpp.o.requires
CMakeFiles/webserver.dir/requires: CMakeFiles/webserver.dir/src/hash_control.cpp.o.requires
CMakeFiles/webserver.dir/requires: CMakeFiles/webserver.dir/src/common.cpp.o.requires
CMakeFiles/webserver.dir/requires: CMakeFiles/webserver.dir/utils/csapp.c.o.requires
CMakeFiles/webserver.dir/requires: CMakeFiles/webserver.dir/utils/TimeTools.cpp.o.requires
CMakeFiles/webserver.dir/requires: CMakeFiles/webserver.dir/utils/FileTools.cpp.o.requires
CMakeFiles/webserver.dir/requires: CMakeFiles/webserver.dir/utils/UUIDTools.cpp.o.requires

.PHONY : CMakeFiles/webserver.dir/requires

CMakeFiles/webserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/webserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/webserver.dir/clean

CMakeFiles/webserver.dir/depend:
	cd /home/honkee/study/cpp/csapp_v2/webserver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/honkee/study/cpp/csapp_v2/webserver /home/honkee/study/cpp/csapp_v2/webserver /home/honkee/study/cpp/csapp_v2/webserver/build /home/honkee/study/cpp/csapp_v2/webserver/build /home/honkee/study/cpp/csapp_v2/webserver/build/CMakeFiles/webserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/webserver.dir/depend

