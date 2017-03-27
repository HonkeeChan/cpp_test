#include <iostream>
#include <map>
#include <unordered_map>
#include <iterator>

using namespace std;
typedef map<string, int>::iterator MSIITER;

void printMap(const map<string, int>& m);
void printUnorderMap(const unordered_map<string, int>& um);
int main(){
    

    map<string, int> m, bak;

    m.insert(make_pair("1", 1));
    m.insert(make_pair("2", 2));
    m.insert(make_pair("3", 3));
    m.insert(make_pair("4", 4));
    m.insert(make_pair("5", 5));
    m.insert(make_pair("6", 6));
    m.insert(make_pair("7", 7));
    bak = m;
    int cnt = 0;
    printMap(m);
    for(auto it = m.begin(); it != m.end(); ){
        if(cnt++ % 2 == 0){
            it = m.erase(it);
        }else{
            ++it;
        }
    }
    printMap(m);
    printMap(bak);

    unordered_map<string, int> um;
    um.insert(make_pair("1", 1));
    um.insert(make_pair("2", 2));
    um.insert(make_pair("3", 3));
    um.insert(make_pair("4", 4));
    um.insert(make_pair("5", 5));
    um.insert(make_pair("6", 6));
    um.insert(make_pair("7", 7));
    printUnorderMap(um);
    
    
}

void printMap(const map<string, int>& m){
    for(auto it = m.begin(); it != m.end(); ++it){
        cout << it->first << " ";
    }
    cout << endl;
}
void printUnorderMap(const unordered_map<string, int>& um){
    for(auto it = um.begin(); it != um.end(); ++it){
        cout << it->first << " ";
    }
    cout << endl;
}