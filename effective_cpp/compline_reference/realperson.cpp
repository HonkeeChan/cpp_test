// RealPerson.cpp
#include "realperson.h"

Person* Person::CreatePerson(string name, const MyAddress& addr, const MyDate& date)
{
    return new RealPerson();
}
