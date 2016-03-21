#include "Fruit.h"

#include <string>
#include <iostream>
using namespace std;

Fruit::Fruit()
{
    cout << "Fruit::Fruit() was called" << endl;
}

void Fruit::PrepareNonVirtual()
{
    cout << "Fruit::PrepareNonVirtual: Don't know how." << endl;
}

void Fruit::Prepare()
{
    cout << "Fruit::Prepare: Don't know how." << endl;
}

Fruit::~Fruit(void)
{
    cout << "Fruit::~Fruit() was called" << endl;
}
