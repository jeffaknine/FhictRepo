#include "Apple.h"

#include <string>
#include <iostream>
using namespace std;

Apple::Apple()
{
    cout << "Apple::Apple() was called" << endl;
}

void Apple::PrepareNonVirtual()
{
    cout << "Apple::PrepareNonVirtual: Apple was cut." << endl;
}

void Apple::Prepare()
{
    cout << "Apple::Prepare: Apple was cut." << endl;
}

Apple::~Apple(void)
{
    cout << "Apple::~Apple() was called" << endl;
}
