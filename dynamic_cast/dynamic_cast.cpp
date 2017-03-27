#include <iostream>
// dynamic_cast_5.cpp
// compile with: /c /GR
class A {virtual void f() = 0;};
class B : public A {virtual void f(){};};
class C : public A { };
class D {virtual void f(){};};
class E : public B, public C, public D {virtual void f(){};};

void fun(D* pd) {
  E* pe = dynamic_cast<E*>(pd);
  B* pb = pe;  // upcast, implicit conversion
  A* pa = pb;  // upcast, implicit conversion
}

int main(){
    D d;
    fun(&d);
}