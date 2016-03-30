#include "Scan.h"
#include "gtest/gtest.h"
#include <stdio.h>
using namespace std;

Scan::Scan(int number)
{
	serialNumber = number;
	timesRecycled = 0;
}

Scan::~Scan()
{
	delete next;
}

int Scan::getSerialNumber()
{
	return serialNumber;
}

Scan* Scan::getNext()
{
	return (Scan*)next;
}

void Scan::setNext(Scan* nextScan)
{
	this->next = nextScan;
}

void Scan::recycle()
{
	this->timesRecycled++;
}

int Scan::getTimesRecycled()
{
	return this->timesRecycled;
}