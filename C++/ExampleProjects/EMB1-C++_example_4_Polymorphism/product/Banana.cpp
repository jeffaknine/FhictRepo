#include "Banana.h"

#include <string>
#include <iostream>
using namespace std;

Banana::Banana()
{
    cout << "Banana::Banana() was called" << endl;
}

void Banana::PrepareNonVirtual()
{
    cout << "Banana::PrepareNonVirtual: Banana was peeled." << endl;
}

void Banana::Prepare()
{
    cout << "Banana::Prepare: Banana was peeled." << endl;
}

Banana::~Banana(void)
{
    cout << "Banana::~Banana() was called" << endl;
}
