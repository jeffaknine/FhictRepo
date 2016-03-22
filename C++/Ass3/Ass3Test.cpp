#include "gtest/gtest.h"
#include "Truck.h"

#include <stdio.h>
using namespace std;

class Ass3Test : public ::testing::Test {
protected:
	Truck *myTruck;
	virtual void SetUp()
	{
		myTruck = new Truck("Daf","steel",10,8,1000);
	}

	virtual void TearDown()
	{
		
	}
};


TEST_F(Ass3Test, getPowerTest)
{
	EXPECT_EQ(myTruck->getPower(),10);
}