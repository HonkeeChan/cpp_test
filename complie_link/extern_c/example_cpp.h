#ifndef C_EXAMPLE_H
#define C_EXAMPLE_H
//extern "C" int add(int x,int y);     //注:写成extern "C" int add(int , int ); 也可以
extern int add(int x,int y);     //注:写成extern "C" int add(int , int ); 也可以
extern int add(int x);
extern int add();

extern int sub(int x);
extern int sub();
#endif