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
    // for(int j = 4;j > 0; --j)
    // {
    //     i = 10;
    //     cout << "waiting for input " << endl;
    //     //cout << "cin.clear: " << cin.clear() << endl;
        
    //     //fflush(stdin);

    //     // string a;
    //     // cin >> a;
    //     // cout << "a: " << a << endl;
    //     cin >> i;
    //     cout << "cin.sync: " << cin.sync() << endl;;
        
        
    // }

    int a;
    char  b;
    int ret = 0;
    cout << "input a:" << endl;
    cin >> a;
    cout << "a:" << a << endl;
    //cin.clear();
    //cin.ignore();
    cout << "input b:" << endl;
    cin >> b;
    cout << "b:" << b << endl;


    // int a;
    // int ret = 0;
    // while(cout<<"input a integer :", cin >> a, (ret = cin.fail()))
    // {
    //    cout<<"try again!" << "ret val: " << ret <<endl;

    //    cin.clear(); //清除std::cin的错误状态
    //    cin.ignore(1000, '\n');
    //    string str;
    //    getline(cin, str);
    //    cout << "get line str: " << str << endl;
    //    cin.sync(); //清空输入缓冲区
    // }

    // int c;
    // cin>>c;
    // cout<< c<< endl;

    // cout<< cin.fail()<< endl;
    // cin >>c;
    // cout<< c<< endl;

    // int i, j;
    // cin >> i >> j;
    // cin.get();
    // while(i--){
    //  string s;
    //  getline(cin, s);
    //  cout << s << endl;
    // }

    return 0;
}