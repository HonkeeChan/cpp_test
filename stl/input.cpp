#include <iostream>

using namespace std;
int main(){
    // int n;
    // cin >> n;
    // string s;
    // int cnt = 0;
    // char buf[10];
    // while(cin.get(buf, 10)){
    //     cout << "times: " << ++cnt << " " << s << endl;
    // }


    // string str1, str2, str3;
    // cin >> str1 >> str2 >> str3;
    // cout << "str1: " << str1 << endl;
    // cout << "str2: " << str2 << endl;
    // cout << "str3: " << str3 << endl;

    //cin 读到空行会失效
    // char name[50];
    // char volume[50];
    // double price;
        
    // cout<<"Input Your Name:";
    // cin.get(name, 20);
    // cout<<"Enter volume in cubic feet:";
    // //cin.get(); //如果加上这一句， 程序就没有问题
    // cin.get(volume, 20);
    // cout<<"Enter price:";
    // cin>>price;
    // cout<<"Hello,"<<name<<",Your Volume is "<<volume<<" with "<<price<<" Dollars."<<endl; 

    // int i;
    // for(;;)
    // {
    //     i = 10;
    //     cout << "waiting for input " << endl;
    //     cin.clear();
    //     cin.sync();
    //     //fflush(stdin);

    //     // string a;
    //     // cin >> a;
    //     // cout << "a: " << a << endl;
    //     cin >> i;
        
        
    // }

    int a;
    while(cout<<"input a integer (1-10) :",cin>>a,! (a>=1 && a<=10) || cin.fail())
    {
       cout<<"try again!"<<endl;
       cin.clear(); //清除std::cin的错误状态
       cin.sync(); //清空输入缓冲区
    }


    return 0;
}