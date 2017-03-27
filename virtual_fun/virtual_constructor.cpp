#include <iostream>
using namespace std;

typedef void(*Fun)(void);
class A{
public:
    A(){

        //void (*f)(void) ;
        //void* ptr = this;
        cout << "in A constructor" << endl;
        cout << "vtable addr: " << *(int*)(this) << endl;
        Fun f = (Fun)*((int*)*(int*)(this));
        f();
    }
    virtual void fun(){
        cout << "A fun" << endl;
    }
    virtual void bar(){
        cout << "B bar" << endl;
    }
    virtual ~A(){}
};
class B: public A{
public:
    B(){
        cout << "in B constructor" << endl;
        cout << "vtable addr: " << *(int*)(this) << endl;
        Fun f = (Fun)*((int*)*(int*)(this));
        f();
    }
    virtual void fun(){
        cout << "B fun" << endl;
    }
};

int main(){
    A a;
    B b;
    //Fun f = (Fun)*((int*)*(int*)(&a));
    //f();
    cout << "A vtable addr: " << *(int*)(&a) << endl;
    cout << "B vtable addr: " << *(int*)(&b) << endl;
}