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

	cout << "sizeof A: " << sizeof (A) << endl;
	cout << "A.p offset: " << offsetof(A, p) << endl;
	cout << "A.a offset: " << offsetof(A, a) << endl;
	cout << "A.b offset: " << offsetof(A, b) << endl;

	cout << "sizeof B: " << sizeof (B) << endl;
	cout << "B.a offset: " << offsetof(B, a) << endl;
	cout << "B.p offset: " << offsetof(B, p) << endl;
	cout << "B.b offset: " << offsetof(B, b) << endl;

	cout << "sizeof C: " << sizeof (C) << endl;
	cout << "C.i1 offset: " << offsetof(C, i1) << endl;
	cout << "C.i2 offset: " << offsetof(C, i2) << endl;
	cout << "C.a offset: " << offsetof(C, a) << endl;
	cout << "C.b offset: " << offsetof(C, b) << endl;
	cout << "C.c offset: " << offsetof(C, c) << endl;

	cout << "sizeof D: " << sizeof (D) << endl;
	cout << "D.p offset: " << offsetof(D, p) << endl;
	cout << "D.a offset: " << offsetof(D, a) << endl;
	cout << "D.b offset: " << offsetof(D, b) << endl;
	cout << "D.c offset: " << offsetof(D, c) << endl;

}