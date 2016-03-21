#include "Student.h"

#include <string>
#include <iostream>
using namespace std;

Student::Student()
{
    cout << "Student::Student() was called" << endl;
}

Student::Student(string firstName, string lastName, string nickName)
: Person(firstName, lastName), nickName(nickName)
{
    cout << "Student::Student(" << firstName << ", " << lastName << ", " << nickName << ") was called" << endl;
}

Student::~Student()
{
    cout << "Student::~Student() of " << nickName << " was called" << endl;
}
