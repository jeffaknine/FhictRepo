/*
 * PiggyBank.cpp
 *
 *  Created on: Aug 31, 201
 *  Author: Peter Lambooij
 */

#include "PiggyBank.h"

//---------------------------------------------------------------------------

// the default constructor, without parameters, implemented by every c++ class
PiggyBank::PiggyBank(void)
    : owner("")         // initializer list. As with C#, this "code" is executed before the code in the body
    , balance(0)        // please keep in mind that these members are *always* initialised in the order of appearance
    , broken(false)    // in the header file, so please keep that order the same as here!
{
}

PiggyBank::PiggyBank(string name)
    : owner(name)
    , balance(0)
    , broken(false)
{
}

PiggyBank::PiggyBank(string name, int startBalance)
{
	// an alternative for initializer lists (see above): assign values to class data members attributes in the body
	owner = name;
	balance = startBalance;
}

PiggyBank::~PiggyBank(void)
{
	// the so-called destructor contains code that needs to be executed
	// just before an object is destroyed (e.g. check if a file has been closed properly)
	// we will come back to destructors in a later lesson
}

string PiggyBank::getOwnerName()
{
	return owner;
}

void PiggyBank::setOwnerName(string name)
{
	owner = name;
}

int PiggyBank::getBalance()
{
    return balance;
}

bool PiggyBank::isBroken()
{
	return broken;
}

void PiggyBank::depositMoney(int amount)
{
	if (!isBroken())
    {
        balance += amount;
    }
}

int PiggyBank::smash()
{
    int currentBalance = balance;

    balance = 0;
    broken = true;

    return currentBalance;
}

