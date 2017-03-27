#include <iostream>
using namespace std;
// dynamic_cast_3.cpp
// compile with: /c /GR
class B {virtual void f(){};};
class D : public B {virtual void f(){};};

void f() {
  B* pb = new D;  // unclear but ok
  B* pb2 = new B;

  D* pd = dynamic_cast<D*>(pb);  // ok: pb actually points to a D
  D* pd2 = dynamic_cast<D*>(pb2);  // pb2 points to a B not a D
}

int main(){
    f();
    return 0;
}