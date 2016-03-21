/*
 * StorablePiggyBank.cpp
 *
 *  Created on: Aug 31, 2012
 *      Author: Peter Lambooij
 */

#include "StorablePiggyBank.h"
#include <fstream>
#include <sstream>
#include <iostream>

int StorablePiggyBank::nrOfObjects = 0; // static data members need to be initialized!

StorablePiggyBank::StorablePiggyBank()
	: PiggyBank()
{
	nrOfObjects++;
}

StorablePiggyBank::StorablePiggyBank(string name)
	: PiggyBank(name)
{
	nrOfObjects++;
}

StorablePiggyBank::StorablePiggyBank(string name, int amount)
	: PiggyBank(name, amount)
{
	nrOfObjects++;
}

StorablePiggyBank::~StorablePiggyBank()
{
	nrOfObjects--;	// the default destructor will call the default constructor of the base class
}

bool StorablePiggyBank::store(string filename)
{
	ofstream file_out(filename.c_str());
	if (file_out.is_open())
	{
		file_out << serialize();
		file_out.close();
		return true;
	}
	return false;
}

bool StorablePiggyBank::load(string filename)
{
	ifstream file_in(filename.c_str());
	if (file_in.is_open())
	{
		string stored;
		file_in >> stored;
		file_in.close();
		return (deserialize(stored));
	}
	return false;
}

string StorablePiggyBank::serialize()
{
	stringstream ss; // example of stringstream to pack data into a string
	ss << owner << ',';
	ss << balance << ',';
	ss << broken;
	return ss.str();
}

bool StorablePiggyBank::deserialize(string stored)
{
	int index1 = stored.find(',', 0);        // info owner is before the first ´,´
	int index2 = stored.find(',', index1+1); // info broken is after the second ´,´

	cout << index1 << ',' << index2 << endl;
	if (index1 < 0 || index2 <= index1) return false; // if invalid info in file return with failure

	owner = stored.substr(0, index1);

	stringstream ss1(stored.substr(index1+1, index2-index1-1));
	ss1 >> balance;

	stringstream ss2(stored.substr(index2+1));
	ss2 >> broken;

	return true;
}

int StorablePiggyBank::getNrOfObjects()
{
	return nrOfObjects;
}
