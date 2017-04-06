#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    float f = 13.1415926;
    cout << "precision(2)" << setw(10)<< setprecision(2) << f << endl;
    cout << "precision(3)" <<  setw(10) << setprecision(3) << f << endl;
    //fixed 使用小数计数法
    //scientific 使用科学计数法
    cout << "precision(5)" << fixed <<  setw(10) << setprecision(9) << f << endl;
    cout << "precision(5)" << scientific  << setw(10) << setprecision(5) << f << endl;
    return 0;
}
