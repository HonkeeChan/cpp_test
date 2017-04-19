/*
    测试list的迭代器会不会因为erase失效
    结果是不会。
*/

#include <list>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;
int main(){
    typedef list<int> LI;
    typedef LI::iterator LII;
    typedef vector<LII> VLII;
    typedef VLII::iterator VI;

    VLII v;
    LI l;
    for(int i = 0; i < 30; ++i){
        l.push_back(i);
        v.push_back(--l.end());
    }
    int i = 0;
    for(LII it = l.begin(); it != l.end(); ){
        if(i % 3 == 0){
            it = l.erase(it);
        }else{
            it ++;
        }
        i++;
    }
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    i = 0;
    for(VI it = v.begin(); it != v.end(); ++it){
        if(i++ % 3 ==0) continue;
        cout << **it << " ";
    }
    cout << endl;
    return 0;
}

