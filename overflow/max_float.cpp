#include <iostream>
#include <limits>
#include <cmath>
using namespace std;
int main(){
    int j;

    double dMax = numeric_limits<double>::max();
    int i = 0;
    cout << "max double: " << dMax << endl;
    while(abs(dMax - 0 ) > 0.00000001){
        dMax /= 2;
        i++;
    }
    cout << i << endl;
    long double ldMax = numeric_limits<long double>::max();
    i = 0;
    cout << "max long double: " << ldMax << endl;
    while(abs(ldMax - 0 ) > 0.00000001){
        ldMax /= 2;
        i++;
    }
    cout << i << endl;

    float fMax = numeric_limits<float>::max();
    i = 0;
    cout << "max float: " << fMax << endl;
    while(abs(fMax - 0 ) > 0.00000001){
        fMax /= 2;
        i++;
    }
    cout << i << endl;
}