#include <iostream>
using namespace std;
// dynamic_cast_2.cpp
// compile with: /c /GR
class A {virtual void f(){};};
class B {virtual void f(){};};

void f() {
  A* pa = new A;
  B* pb = new B;
  void* pv = dynamic_cast<void*>(pa);
  // pv now points to an object of type A
  cout << "pv: " << pv << endl;
  pv = dynamic_cast<void*>(pb);
  // pv now points to an object of type B
  cout << "pv: " << pv << endl;
}

int main(){
    f();
    return 0;
}