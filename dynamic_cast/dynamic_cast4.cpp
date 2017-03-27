#include <iostream>
// dynamic_cast_4.cpp
// compile with: /c /GR
class A {virtual void f(){};};
class B : public A{virtual void f(){};};
class C : public A {virtual void f(){};};
class D : public B, public C {virtual void f(){};};

void f() {
  D* pd = new D;
  //A* pa = dynamic_cast<A*>(pd); 
  B* pb = dynamic_cast<B*>(pd);  // first cast to B
  A* pa2 = dynamic_cast<A*>(pb);  // ok: unambiguous
}
int main(){
    //D d;
    f();
}