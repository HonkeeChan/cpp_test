#include <iostream>

using namespace std;
class SelfIncrease{
public:
    SelfIncrease():i(0){}
    int Get() const{
        return i;
    }
    SelfIncrease& operator++(){
        i++;
        return *this;
    }
    const SelfIncrease operator++(int){
        SelfIncrease temp = *this;
        i++;
        return temp;
    }

private:
    int i;
};

int main(){
    SelfIncrease si;
    cout << si.Get() << endl;
    cout << (si++).Get() << endl;
    cout << (++si).Get() << endl;
    int i = 0;
    //cout << ++(i++) << endl; !!!!!error
    return 0;
}