#include <iostream>
#include <string>

using namespace std;
int main(){
	string str;
	cout << "str.capacity: " << str.capacity() << endl;
	str += "hello";
	cout << "str.capacity: " << str.capacity() << endl;
	str = str + "hello";
	cout << "str.capacity: " << str.capacity() << endl;
	str = str + "hello";
	cout << "str.capacity: " << str.capacity() << endl;
	str = str + "hello";
	cout << "str.capacity: " << str.capacity() << endl;
	str = str + "hello";
	cout << "str.capacity: " << str.capacity() << endl;
	str = str + "hello";
	cout << "str.capacity: " << str.capacity() << endl;
	str = str + "hello";
	cout << "str.capacity: " << str.capacity() << endl;
	str = str + "hello";
	cout << "str.capacity: " << str.capacity() << endl;
	(str += "hello") += "hi";
	cout << "str.capacity: " << str.capacity() << endl;
	cout << str << endl;
	str.append("hi").append("hello");
	return 0;
}
