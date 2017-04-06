#include <iostream>
extern "C"{
#include "example_c.h"     
}
using namespace std;
static int globalStatic = 1;
int globalDefined = 2;
int globalDeclare;
const int globalConstInt = 3;

static int staticFun(){}
int main(int argc, char* argv[])
{
	int localIntDeclare;
	int localIntDefined = 2;
	const int localConstInt = 3;
    cout << add(2,3) << endl;
    //cout << multi(1) << endl;
    return 0;
}
