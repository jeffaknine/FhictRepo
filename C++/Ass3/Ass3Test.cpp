#include "gtest/gtest.h"
#include "Truck.h"
#include "Car.h"
#include "Wheel.h"

#include <stdio.h>
using namespace std;


class Ass3Test : public ::testing::Test {
protected:
	Truck *myTruck;
	Car *myCar;
	Wheel *myWheel;
	virtual void SetUp()
	{
		myTruck = new Truck("Daf","steel",10,8,1000);
		myCar = new Car("Porsche", "carbon",20,4);
		myWheel = new Wheel(25,"alu");

	}

	virtual void TearDown()
	{
		delete myWheel;
		delete myCar;
		delete myTruck;
	}
};


TEST_F(Ass3Test, Test)
{

	//Wheel testing
	EXPECT_EQ(myWheel->getDiameter(), 25);
	myWheel->setMaterial("plop");
	EXPECT_EQ(myWheel->getMaterial(), "plop");
	

	//Car Testing
	myCar->setLicensePlate("Plop");
	EXPECT_EQ(myCar->getLicensePlate(), "Plop");
	EXPECT_EQ(myCar->getNrWheels(),4);

	myCar->addWheel(1,"a");
	myCar->addWheel(2,"b");
	myCar->addWheel(25,"alu");
	EXPECT_EQ(myCar->getNrWheels(),7);

	myCar->removeWheel(4);
	EXPECT_EQ(myCar->getNrWheels(),6);

	Wheel* wheel(myCar->getWheel(5));
	EXPECT_EQ(wheel->getDiameter(),25);
	EXPECT_EQ(wheel->getMaterial(),"alu");
	
	Car *car = myCar;
	EXPECT_EQ(car->getNrWheels(),6);	

	//Truck Testing
	EXPECT_EQ(myTruck->getPower(),1000);
	Truck *truck(myTruck);
	EXPECT_EQ(truck->getPower(),1000);
	Truck *plop = truck;
	EXPECT_EQ(plop->getPower(),1000);
}