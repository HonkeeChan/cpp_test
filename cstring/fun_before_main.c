#include <stdio.h>

int fun(){
	printf("before main\n");
	return 1;
}

/*
c语言不允许这样定义一个变量，但是c++允许，全局变量的构造函数也在main
函数之前运行。
 
 gcc fun_before_main.c -o fun_before_main
fun_before_main.c:8:15: error: initializer element is not constant
 const int b = fun();

g++ fun_before_main.c -o fun_before_main  OK!!!!
*/
int b = fun();

int main(){

	return 0;
}
