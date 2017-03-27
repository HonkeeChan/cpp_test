// dynamic_cast_1.cpp
// compile with: /c
class B { };
class C : public B { };
class D : public C { };

void f(D* pd) {
  C* pc = dynamic_cast<C*>(pd);  // ok: C is a direct base class
                  // pc points to C subobject of pd 
  B* pb = dynamic_cast<B*>(pd);  // ok: B is an indirect base class
                  // pb points to B subobject of pd
}

int main(){
    D d;
    f(&d);
    return 0;
}