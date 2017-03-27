#include <iostream>

using namespace std;
class A{
public:
    A(){
        cout << "A constructer" << endl;
    }
    ~A(){
         cout << "A deconstructer" << endl;
    }
};


int main(){
    A* pa = new A[10];
    A* paa = &pa[0];
    delete paa;
    //delete[] pa;
}