#include <iostream>
#include <string>

using namespace std;
template<class T>
class NameObject{
public:
    NameObject(string& name):nameValue(name){
        //nameValue = name;
    }
    string& getString(){
        return nameValue;
    }
private:
    string& nameValue;
    
};

int main(){
    //int &r = 0;
    string s = "str";
    string s1 = "str1";
    NameObject<int> no1(s);
    NameObject<int> no2(s1);
    
    no1 = no2;
    //cout << "s.getString" << s.getString() << endl;
}