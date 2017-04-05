#include <iostream>
// extern "C"{
// #include "example_c.h"     
// }
#include "example_cpp.h"
using namespace std;
static int i = 1;
int j = 2;
int main(int argc, char* argv[])
{
    cout << add(2,3) << endl;
    cout << add(1) << endl;
    cout << sub(1) << endl;
    //cout << multi(1) << endl;
    return 0;
}
