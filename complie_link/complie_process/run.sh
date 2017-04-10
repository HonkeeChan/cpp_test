gcc -E hello.c -o hello.i
gcc -S hello.i -o hello.s
gcc –c hello.s –o hello.o
