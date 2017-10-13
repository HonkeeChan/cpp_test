#include <iostream>

using namespace std;
class Base{
public:
	void fun(){
		cout << "Base::fun()" << endl;
	}
	void fun(int i){
		cout << "Base::fun(int)" << endl;
	}
};
class Derive : public Base{
public:
	using Base::fun;
	void fun(double i){
		cout << "Dervie::fun(double)" << endl;
	}
};
int main(){
	Derive d;
	Base* pb = &d;
	d.Base::fun();
	d.Base::fun(1);
	d.fun(1.0);
	d.fun();
	return 0;

}