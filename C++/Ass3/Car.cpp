#include "Car.h"
#include <stdexcept>      // out_of_range
#include <iostream>       // std::cerr

using namespace std;

 bool Car::indexInRange(int index)
 {
 	if(index < (int)(wheels.size())){
		return true;
	}
	
	return false;
 }
  
 void Car::deleteAllWheels()
 {
	for(unsigned int i=0; i < wheels.size(); i++){
		
		delete wheels[i];
		wheels[i] = NULL;
	}
	 
 	wheels.clear();
 } 
    
void Car::copyCar(const Car& otherCar)
{
	deleteAllWheels();
		for (unsigned int i = 0; i < wheels.size(); ++i)
		{
			wheels.push_back(new Wheel(*(otherCar.wheels[i])));
		}
		licensePlate = otherCar.licensePlate;
		model = otherCar.model;
}

Car::Car(const string& model, const string& material, int diameter, int nrWheels)
{
	this->model = model;

	for(int i = 0; i < nrWheels; i++){

		Wheel *w = new Wheel(diameter, material);
		wheels.push_back(w);
	}
}

Car::~Car()
{
	deleteAllWheels();
}


string Car::getModel() const
{
	return model;
}
    
void Car::setLicensePlate(const string& license)
{
	licensePlate = license;
}
  
string Car::getLicensePlate() const
{
	return licensePlate;
}

int Car::getNrWheels() const
{
	int count = 0;
		for (unsigned int i = 0; i < wheels.size(); ++i)
		{
			if (wheels[i] != NULL)
			{
				count = count + 1;
			}
			else break;
		}
		return count;
}
    
Wheel* Car::getWheel(int index)
{
	return wheels[index];
}
   
void Car::removeWheel(int index)
{
  if (index >= 0 && index < Car::getNrWheels())
		{
			delete wheels[index];
			wheels.erase(wheels.begin() + index);

		}
		else
		{
			//throw out_of_range
			cout << "illegal index" <<endl;
		}
}

void Car::addWheel(int diameter, const string& material)
{
	Wheel *w = new Wheel(diameter, material);
	wheels.push_back(w);
}
  
Car::Car(const Car& myCar)
{
	copyCar(myCar);
}
 
Car& Car::operator=(const Car& myCar)
{
	if (&myCar == this)
		{
			return *this;
		}
		copyCar(myCar);
		return *this;
}