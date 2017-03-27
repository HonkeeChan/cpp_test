// RealPerson.h
#include "Person.h"
#include "MyAddress.h"
#include "MyDate.h"

class RealPerson: public Person
{
private:
    string Name;
    MyAddress Address;
    MyDate Birthday;
public:
    RealPerson(){}
    RealPerson(string name, const MyAddress& addr, const MyDate& date):
        Name(name), Address(addr), Birthday(date){}
    virtual string GetName() const{};
    virtual string GetAddress() const{};
    virtual string GetBirthday() const{};
};
