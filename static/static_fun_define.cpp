#include <iostream>

using namespace std;
class A{
public:
	static void f(){
		cout << "static fun()" << endl;
	}
	static void f1();
};

void A::f1(){
	cout << "static fun1()" << endl;
}
int main(){
	A::f();
	A::f1();
	return 0;
}