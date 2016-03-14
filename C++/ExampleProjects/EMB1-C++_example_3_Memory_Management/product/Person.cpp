#include "Person.h"

#include <string>
#include <iostream>
using namespace std;

Person::Person()
{
    cout << "Person::Person() was called" << endl;
}

Person::Person(string firstName, string lastName)
: firstName(firstName), lastName(lastName)
{
    cout << "Person::Person(" << firstName << ", " << lastName << ") was called" << endl;
}

Person::~Person(void)
{
    cout << "Person::~Person() of " << firstName << " " << lastName << " was called" << endl;
}
