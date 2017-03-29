#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    float f = 13.1415926;
    cout << "precision(2)" << setprecision(2) << f << endl;
    cout << "precision(3)" << setprecision(3) << f << endl;
    //fixed 使用小数计数法
    //scientific 使用科学计数法
    cout << "precision(5)" << fixed << setprecision(5) << f << endl;
    cout << "precision(5)" << scientific << setprecision(5) << f << endl;
    return 0;
}
