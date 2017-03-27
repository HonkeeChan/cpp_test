#include <iostream>

using namespace std;
class A{
public:
    A(){
        cout << "A" << endl;
    }
    virtual void show() const{cout << "inshow A" << endl;}

    ~A(){
        cout << "~A"  << endl;
    }
};

class B : public A{
public:
    B(){
        cout << "B" << endl;
    }
    //B& operator= (const A& a){ return a;}
    void show() const{cout << "inshow B" << endl;}
    ~B(){
        cout << "~B"  << endl;
    }
};

class C{
    //C() = 0;
    //  ~C() =  0; //error: initializer specified for non-virtual method ‘C::~C()’
    virtual ~C() =  0;
};

class constTest{
public:
    constTest(){a = 1;}
    int getA(){ 
        cout << "get A version" << endl;
        return a;
    }
    const int& getA() const{ 
        cout << "get a const version" << endl;
        return a;
    }
    int& get() const{
        return a;
    }
private:
    int a;
};
void referenceParam(const A& a);
int main(){
    double dval = 1.5;
    const int& ci = dval;
    cout << "dval: " << dval << " const int&: " << ci << endl;
    //B b = B();
    B b;
    A a;
    A& aa = a;
    A& ab = b;
    const int cint = 19;
    int arr[cint];

    const constTest ct;
    const int& i = ct.getA();
    int& ri = const_cast<int&>(i);
    ri = 10;
    //i = 10;
    cout << "get const test: " <<  ct.getA() << endl;
    referenceParam(a);
    referenceParam(b);
    cout << "********* virtual deconstruce *******" << endl;
    A* pa = new B();
    delete pa;
    cout << "********* end  *******" << endl;
    return 0;
}

void referenceParam(const A& a){
    a.show();
}

