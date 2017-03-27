
##字节对齐的规则

字节对齐的细节和编译器实现相关，但一般而言，满足三个准则：
1) 结构体变量的首地址能够被其最宽基本类型成员的大小所整除；
2) 结构体每个成员相对于结构体首地址的偏移量（offset）都是成员大小的整数倍，
如有需要编译器会在成员之间加上填充字节（internal adding）；
3) 结构体的总大小为结构体最宽基本类型成员大小的整数倍，如有需要编译器会在最
末一个成员之后加上填充字节（trailing padding）。
填充的这些字节都会置0.

[这篇文章](http://blog.csdn.net/wzy198852/article/details/7246836)有更详细的解释

我这里想举几个例子来说明一下这三个准则。

对于第二点，我想以下面这个例子来说明。
```c++
class A{
public:
	void* p;
	char a;
	int b;
};
class B{
public:
	char a;
	void* p;
	int b;
};
```
他们的内存分布如下图

A中的b是四字节对齐的，而a只有1字节，所以a需要padding 3个字节。
B中的p是八字节对齐的，而a只有1字节，所以a需要padding 7个字节。

对于第三点，我可以用下面这个例子来证明。

```c++
class C{
public:
	int i1;
	int i2;
	char a;
	int b;
	char c;
};

class D{
public:
	void* p;
	char a;
	int b;
	char c;
};
```
他们的内存分布图如下

C,D的a,b,c这三个成员的地址偏移量都是相同的，可是C,D这两个类的大小却不相同，
是因为C中最宽的成员是int，4字节，所以整个类会以4字节做padding，
D中最宽的成员是void*， 8字节，整个类会以8字节做padding


附上完整的测试代码
```C++
#include <iostream>
#include <cstddef>
using namespace std;
class A{
public:
	void* p;
	char a;
	int b;
};

class B{
public:
	char a;
	void* p;
	int b;
};


class C{
public:
	int i1;
	int i2;
	char a;
	int b;
	char c;
};

class D{
public:
	void* p;
	char a;
	int b;
	char c;
};

int main(){

    //cout << endl;
	cout << "sizeof A: " << sizeof (A) << endl;
	cout << "A.p offset: " << offsetof(A, p) << endl;
	cout << "A.a offset: " << offsetof(A, a) << endl;
	cout << "A.b offset: " << offsetof(A, b) << endl;

    //cout << endl;
	cout << "sizeof B: " << sizeof (B) << endl;
	cout << "B.a offset: " << offsetof(B, a) << endl;
	cout << "B.p offset: " << offsetof(B, p) << endl;
	cout << "B.b offset: " << offsetof(B, b) << endl;

    //cout << endl;
	cout << "sizeof C: " << sizeof (C) << endl;
	cout << "C.i1 offset: " << offsetof(C, i1) << endl;
	cout << "C.i2 offset: " << offsetof(C, i2) << endl;
	cout << "C.a offset: " << offsetof(C, a) << endl;
	cout << "C.b offset: " << offsetof(C, b) << endl;
	cout << "C.c offset: " << offsetof(C, c) << endl;

    //cout << endl;
	cout << "sizeof D: " << sizeof (D) << endl;
	cout << "D.p offset: " << offsetof(D, p) << endl;
	cout << "D.a offset: " << offsetof(D, a) << endl;
	cout << "D.b offset: " << offsetof(D, b) << endl;
	cout << "D.c offset: " << offsetof(D, c) << endl ;
    return 0;
}
```

运行结果：
```bash
➜  cpp g++ padding.cpp -o padding
➜  cpp ./padding                 
sizeof A: 16
A.p offset: 0
A.a offset: 8
A.b offset: 12

sizeof B: 24
B.a offset: 0
B.p offset: 8
B.b offset: 16

sizeof C: 20
C.i1 offset: 0
C.i2 offset: 4
C.a offset: 8
C.b offset: 12
C.c offset: 16

sizeof D: 24
D.p offset: 0
D.a offset: 8
D.b offset: 12
D.c offset: 16
```