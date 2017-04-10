#include <iostream>
struct A
{
	char c;
	int i;
};
struct B
{
	char c;
	long ll;
};

using namespace std;
int main(){
	cout << "sizeof A: " << sizeof(A) << endl; 
	cout << "sizeof B: " << sizeof(B) << endl; 
}
