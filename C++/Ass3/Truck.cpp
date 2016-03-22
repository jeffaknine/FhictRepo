#include "Truck.h"
#include "Car.h"
#include <string>

using namespace std;

Truck::Truck(const string& model, const string& material, int diameter, int nrWheels, int power)
	:Car(model, material, diameter, nrWheels)
{
	 this->power = new int(power);
}

Truck::~Truck()
{
	delete power;
	power = NULL;
}

int Truck::getPower() const
{
	return *power;
}

Truck::Truck(const Truck& myTruck) : Car(myTruck)
{
	power = new int(myTruck.getPower());
}

Truck& Truck::operator=(const Truck& myTruck)
{
	if(this == &myTruck) return *this;
	delete power;
	Car::operator=(myTruck);
	power = new int(myTruck.getPower());
	
	return *this;
}