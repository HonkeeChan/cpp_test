#include <iostream>

using namespace std;
// dynamic_cast_6.cpp
// compile with: /c /GR
class A {virtual void f(){};};
class B : public A {virtual void f(){};};
class C : public A { };
class D {virtual void f(){};};
class E : public B, public C, public D {virtual void f(){};};

void f(D* pd) {
  B* pb = dynamic_cast<B*>(pd);  // cross cast
  cout << "pb: " << pb;
  A* pa = pb;  // upcast, implicit conversion
  cout << "pa: " << pa;
}

int main(){
    D d;
    f(&d);
}
