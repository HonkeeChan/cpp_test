#include <iostream>
#include <cstring>
#include <iterator>
using namespace std;
/*
    使用strcpy会将字符末尾的\0复制过去。使用memcpy就是单纯的复制制定字节的数据。
    strlen()返回的是不算\0的字符数。
*/

void printBuf(char* buf, int len);
int main(){
    char* s1 = "abcdefghij";
    char s2[] = "abcdefghij";
    char s3[20] = "abcdefghij";
    char* s4 = s1;
    cout << "sizeof(s1): " << sizeof(s1) << endl;
    cout << "sizeof(s2): " << sizeof(s2) << endl; //包括\0字符的长度
    cout << "sizeof(s3): " << sizeof(s3) << endl;
    cout << "sizeof(s4): " << sizeof(s4) << endl;

    cout << "strlen(s1): " << strlen(s1) << endl; //strlen 计算长度不包括\0
    cout << "strlen(s2): " << strlen(s2) << endl;
    cout << "strlen(s3): " << strlen(s3) << endl;
    cout << "strlen(s4): " << strlen(s4) << endl;

    char buf[20];
    memset(buf, 1, sizeof(buf));
    printBuf(buf, 20);
    strcpy(buf, s1);
    printBuf(buf, 20);

    memset(buf, 1, sizeof(buf));
    memcpy(buf, s1, strlen(s1));
    printBuf(buf, 20);

    memset(buf, 1, sizeof(buf));
    memcpy(buf, s1, strlen(s1) + 1);
    printBuf(buf, 20);

    memset(buf, 1, sizeof(buf));
    memcpy(buf, s1, strlen(s1) + 10);
    printBuf(buf, 20);
}

void printBuf(char* buf, int len){
    copy(buf, buf + len, ostream_iterator<int>(cout, " "));
    cout << endl;
}