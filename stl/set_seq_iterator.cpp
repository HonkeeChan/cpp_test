/*
测试set存储的顺序,
结果是： set 是按插入的大小的顺序排序的。
*/
#include <iostream>
#include <set>
#include <iterator>
using namespace std;
int main(){
    set<int> si;
    si.insert(1);
    si.insert(2);
    si.insert(3);
    si.insert(5);
    si.insert(4);
    copy(si.begin(), si.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    si.erase(si.begin());
    copy(si.begin(), si.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    si.insert(6);
    copy(si.begin(), si.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    si.erase(si.begin());
    copy(si.begin(), si.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    si.erase(si.begin());
    copy(si.begin(), si.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}