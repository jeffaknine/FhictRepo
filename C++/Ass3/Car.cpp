#include "Car.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

	bool Car::indexInRange(int index)
	{
		if (wheels[index] != NULL)
		{
			return true;
		}
		else return false;
	}

	void Car::deleteAllWheels()
	{
		for (unsigned int i = 0; i < wheels.size(); ++i)
		{
			delete wheels[i];
			wheels[i] = NULL;
		}
	}

	void Car::copyCar(const Car& otherCar)
	{
		for (unsigned int i = 0; i < wheels.size(); ++i)
		{
			wheels.push_back(new Wheel(otherCar::wheels[i]))
		}
		licensePlate = otherCar.licensePlate;
		model = otherCar.model;
	}


	Car::Car(const string& mod, const string& material, int diameter, int nrWheels)
	{
		std::vector<Wheel*>();
		licensePlate = "";
		model = mod;
		
		for (int i = 0; i < nrWheels; ++i)
		{
			Wheel wheel(diameter,material);
		}
	}

	Car:: virtual ~Car()
	{

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
		Wheel wheel(diameter,material);
	}

	Car::Car(const Car& myCar)
	{

	}

	Car& operator=(const Car& myCar)
	{
		
	}

