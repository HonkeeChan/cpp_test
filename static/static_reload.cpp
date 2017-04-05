#include <iostream>

using namespace std;
static void fun1(){
    cout << "static fun1()" << endl;
}

void fun1(int i){
    cout << "fun1(int)" << endl;
}
// void fun1(){
//     cout << "fun1()" << endl;
// }

class A{
public:
    static void fun1(){
        cout << "static A.fun1()" << endl;
    }
    void fun1(int i){
        cout << " A.fun1(int)" << endl;
    }
};

int main(){
    fun1();
    fun1(1);

    A a;
    a.fun1();
    A::fun1();
    //A::fun1(1)
    a.fun1(2);
    return 0;
}

