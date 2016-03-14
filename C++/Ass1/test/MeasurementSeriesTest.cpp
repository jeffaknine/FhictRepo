#include "gtest/gtest.h"
#include "MeasurementSeries.h"

#include <stdio.h>

using namespace std;

TEST(TestOwnerName, setName)
{
	MeasurementSeries myMeasurements("plop");
	const string name = "Plop";
	myMeasurements.setName(name);
	EXPECT_EQ(myMeasurements.getName(),name);
}

TEST(TestIsFullT, isFull)
{
	MeasurementSeries myMeasurements("Plop");
	myMeasurements.addValue(1);
	myMeasurements.addValue(1);
	myMeasurements.addValue(1);
	myMeasurements.addValue(1);
	myMeasurements.addValue(1);
	myMeasurements.addValue(1);
	myMeasurements.addValue(1);
	myMeasurements.addValue(1);
	myMeasurements.addValue(1);
	myMeasurements.addValue(1);
	EXPECT_TRUE(myMeasurements.isFull());
}

TEST(TestIsFullF, isFull)
{
	MeasurementSeries myMeasurements("Plop");
	myMeasurements.addValue(0);
	myMeasurements.addValue(1);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	

	EXPECT_FALSE(myMeasurements.isFull());
}

TEST(TestExistF, valueExists)
{
	MeasurementSeries myMeasurements("Plop");
	for (int i = 0; i < 10; ++i)
	{
		myMeasurements.addValue(i);
	}
	EXPECT_FALSE(myMeasurements.valueExists(11));
}

TEST(TestExistT, valueExists)
{
	MeasurementSeries myMeasurements("Plop");
	for (int i = 0; i < 10; ++i)
	{
		myMeasurements.addValue(i);
	}
	EXPECT_TRUE(myMeasurements.valueExists(0));
}

TEST(TestgetValue, getValue)
{
	MeasurementSeries myMeasurements("Plop");
	myMeasurements.addValue(0);
	myMeasurements.addValue(1);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	myMeasurements.addValue(0);
	EXPECT_EQ(myMeasurements.getValue(1),1);	
}


TEST(TestGetNrMeasurements, getNrMeasurements)
{
	int number = 0;
	MeasurementSeries myMeasurements("Plop");
	for (int i = 0; i < 10; ++i)
	{
		myMeasurements.addValue(i);
	}
	myMeasurements.getNrMeasurements(number);
	EXPECT_EQ(number,10);
}

class MeasurementSeriesTest : public ::testing::Test 
{
protected:
	
	MeasurementSeries* myMeasurements;

	virtual void SetUp()
    {
    	myMeasurements = new MeasurementSeries("Plop");
		myMeasurements->addValue(0);
		myMeasurements->addValue(1);
		myMeasurements->addValue(0);
		myMeasurements->addValue(0);
		myMeasurements->addValue(0);
		myMeasurements->addValue(0);
		myMeasurements->addValue(0);
		myMeasurements->addValue(0);
		myMeasurements->addValue(0);
		myMeasurements->addValue(0);
	}

	virtual void TearDown()
	{
		delete myMeasurements;
	}
};

TEST_F(MeasurementSeriesTest, AllTestWithOneInstance)
{
	EXPECT_EQ(myMeasurements->getValue(1),1);	
}