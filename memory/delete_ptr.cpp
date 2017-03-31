#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
int main(){
	int* p = new int[10];
	int* p1 = p;
	for(int i = 0; i < 10; ++i){
		p[i] = i;
	}
	// for(int i = 0; i < 10; ++i){
	// 	cout << "p[i]: "  << p[i] << "p1[i]: " << p1[i] << endl;
	// }
	delete [] p;
	for(int i = 0; i < 10; ++i){
		cout << "p[i]: "  << p[i] << "p1[i]: " << p1[i] << endl;
	}

	p = (int*)malloc(sizeof(int) * 10);
	p1 = p;
	for(int i = 0; i < 10; ++i){
		p[i] = i;
	}
	free(p);
	for(int i = 0; i < 10; ++i){
		cout << "p[i]: "  << p[i] << "p1[i]: " << p1[i] << endl;
	}
	return 0;
}