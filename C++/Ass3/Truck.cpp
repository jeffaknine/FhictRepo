#include "Truck.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Truck::Truck(const string& model, const string& material, int diameter, int nrWheels, int power)
:Car(model,material,diameter,nrWheels),
power(new int (power))
{
}

Truck::~Truck()
{
	delete power;
}

int Truck::getPower() const
{
	return *power;
}

Truck::Truck(const Truck& myTruck):Car(myTruck)
{
	delete power;
	power = new int (myTruck.getPower());
}

Truck& Truck::operator=(const Truck& myTruck)
{
	Car::operator=(myTruck);
	delete power;
	power = new int(myTruck.getPower());
	return *this;
}