#include <iostream>
#include <climits>
using namespace std;
typedef void(*Fun)(void);
class Base {
public:
Base(){ 
    ii = INT_MAX;
    for(int i = 0; i < 10; ++i){
 	b[i] = 1; 
 	//c[i] = 1;
    }
}
virtual void f() { cout << "Base::f" << endl;}
virtual void g() { cout << "Base::g" << endl;}
virtual void h() { cout << "Base::h" << endl;}
public:
int ii;
int b[10];
//char c[10];
};

int main(){
    Base b;
    cout << "size of (int)" << sizeof(int) << endl;
    cout << "size of (int *)" << sizeof(int*) << endl;
    cout << "size of(void *)" << sizeof(void*) << endl;
    cout << "size of(Base)" << sizeof(Base) << endl;
    Fun pFun = NULL;
    cout << "虚函数表地址：" << (int*)(&b) << endl;
    cout << "虚函数表 — 第1个函数地址：" << *((int*)*(int*)(&b)) << endl;
    pFun = (Fun)*((int*)*(int*)(&b));
    pFun();
    cout << "虚函数表 — 第2个函数地址：" << *((int*)(*(int*)(&b) + 8 ))<< endl;
    pFun = (Fun)*((int*)( *(int*)(&b) + 8));
    pFun();
    cout << "虚函数表 — 第3个函数地址：" << *((int*)(*(int*)(&b) + 16 )) << endl;
    pFun = (Fun)*((int*)( *(int*)(&b) + 16 ) );
    pFun();

    for(int i = -2; i < 20; ++i){
        int*p = (int *)((long)((int*)(&b)) + i * 4);
        cout << i << " addr: " << p << " value: " << *p << endl;
    }
    cout << "b obj addr: " << &b << endl;
    cout << "sizeof(b): " << sizeof(b) << endl;
    cout << "b obj addr end: " << &b + sizeof(b) << endl; 
    cout << "ii addr: " << &b.ii << endl;
    cout << "b addr: " << &b.b << endl;
    return 0;    
}

