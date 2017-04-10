#include <iostream>
#include <set>

using namespace std;
int main(){
    set<int> si;
    for(int i = 0; i < 100000; ++i){

        si.insert(i);
    }

    cout << si.size() << endl;
    return 0;
}
