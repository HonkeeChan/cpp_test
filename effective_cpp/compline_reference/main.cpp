

 // Main.h
 #include "Person.h"
#include "MyAddress.h"
#include "MyDate.h"
class MyAddress;
class MyDate;

void ProcessPerson(const string& name, const MyAddress& addr, const MyDate& date);

int main(){
    MyAddress ma;
    MyDate md;
    string str;
    ProcessPerson(str, ma, md);
    return 0;
}

void ProcessPerson(const string& name, const MyAddress& addr, const MyDate& date)
{
    Person* p = Person::CreatePerson(name, addr, date);

}
