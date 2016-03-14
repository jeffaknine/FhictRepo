#include "Orange.h"

#include <string>
#include <iostream>
using namespace std;

Orange::Orange()
{
    cout << "Orange::Orange() was called" << endl;
}

void Orange::PrepareNonVirtual()
{
    cout << "Orange::PrepareNonVirtual: Orange was peeled and cut." << endl;
}

void Orange::Prepare()
{
    cout << "Orange::Prepare: Orange was peeled and cut." << endl;
}

Orange::~Orange(void)
{
    cout << "Orange::~Orange() was called" << endl;
}
