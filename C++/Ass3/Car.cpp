#include "Car.h"
#include <vector>
#include <string>

using namespace std;


private:

	wheels = new vector<Wheel*>;
	licensePlate = "";
	model = "";
	bool Car::indexInRange(int index)
	{
		if (wheels[index] != NULL)
		{
			return true;
		}
		else return false;
	}

	void Car::deleteAllWheels();
	{
		for (int i = 0; i < wheels.size(); ++i)
		{
			delete wheels[i];
			wheels[i] = NULL;
		}
	}

	void Car::copyCar(const Car& otherCar)
	{

	}

public:
	Car::Car(const string& model, const string& material, int diameter, int nrWheels)
	{

	}

	Car:: virtual ~Car()
	{

	}

	void Car::setLicensePlate(const string& license)
	{

	}

	string Car::getLicensePlate() const
	{

	}

	int Car::getNrWheels() const
	{

	}

	Wheel* Car::getWheel(int index)
	{

	}

	void Car::removeWheel(int index)
	{

	}

	void Car::addWheel(int diameter, const std::string& material)
	{

	}

	Car::Car

