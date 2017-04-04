#include <iostream>
#include <memory>

using namespace std;
class A{
public:
    ~A(){cout << "~A()" << endl;}
};
int main(){
    //智能指针的创建  
    unique_ptr<int> u_i; //创建<span style="font-family:Arial,Helvetica,sans-serif">“</span><span style="font-family:Arial,Helvetica,sans-serif">空智能指针”</span>  
    u_i.reset(new int(3)); //"绑定”动态对象  
    cout << "u_i " << u_i.get() << " *u_i: " << *u_i << endl;
    unique_ptr<int> u_i2(new int(4));//创建时指定动态对象  
    cout << "*u_i2 " << *u_i2 << endl;
    //所有权的变化  
    int *p_i = u_i2.release(); //释放所有权
    cout << "*p_i" << *p_i << endl;  
    unique_ptr<string> u_s(new string("abc"));  
    cout << "u_s " << u_s.get()  << " *u_s: " << *u_s << endl;;
    unique_ptr<string> u_s2 = std::move(u_s); //所有权转移(通过移动语义)，u_s所有权转移后，变成“空指针”  
    cout << "u_s " << u_s.get() << endl;
    cout << "u_s2 " << u_s2.get()  << " *u_s2" << *u_s2 << endl;
    u_s2=nullptr;


    unique_ptr<A> upA(new A());
    upA = nullptr;
    return 0;
}