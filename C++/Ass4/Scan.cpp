#include <iostream>
#include <cstddef>
#include "Scan.h"
using namespace std;

Scan::Scan(int number){
	serialNumber = number;
	timesRecycled = 0;
}

Scan::~Scan(){
}

int Scan::getSerialNumber(){
	return serialNumber;
}
Scan* Scan::getNext(){
	return (Scan*)next;
}
void Scan::setNext(Scan * next){
	this-> next = next;
}
void Scan::recycle(){
	timesRecycled++;
}

int Scan::getTimesRecycled(){
	return timesRecycled;
}