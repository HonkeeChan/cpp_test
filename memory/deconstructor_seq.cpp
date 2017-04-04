#include <iostream>
using namespace std;
class Inner{
public:
    Inner(){
        cout << "inner constructor" << endl;
    }
    ~Inner(){
        cout << "inner deconstructor" << endl;
    }
};

class Outer{
public:
    Outer(){
        cout << "outer constructor" << endl;
    }
    ~Outer(){
        cout << "outer deconstructor" << endl;
    }
private:
    Inner inner;
};
/*
output:
inner constructor
outer constructor
outer deconstructor
inner deconstructor
*/

int main(){
    Outer o;
    return 0;
}