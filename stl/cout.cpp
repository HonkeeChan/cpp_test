#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    float f = 13.1415926;
    cout << "precision(2)" << setprecision(2) << f << endl;
    cout << "precision(3)" << setprecision(3) << f << endl;
    cout << "precision(5)" << setprecision(5) << f << endl;
    return 0;
}