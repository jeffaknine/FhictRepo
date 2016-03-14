#include "MeasurementSeries.h"
#include "gtest/gtest.h"
#include <stdio.h>

using namespace std;

class MeasurementSeriesTest
{
public:
	MeasurementSeriesTest();
	MeasurementSeries myMeasurements;
	

	
	MeasurementSeries getMeasurementObject()
	{
		return myMeasurements;
	}
	void array1(int count)
	{
		for (int i = 0; i < count; ++i)
		{
			getMeasurementObject().addValue(i);
		}
	}

	
	void array2()
	{
		for (int i = 0; i < 10; ++i)
		{
			getMeasurementObject().addValue(1);
		}
	}
};


TEST(TestOwnerName, setName)
{
	MeasurementSeries myMeasurements("plop");
	const string name = "Plop";
	myMeasurements.setName(name);
	EXPECT_EQ(myMeasurements.getName(),name);
}

TEST(TestIsFullT, isFull)
{
	MeasurementSeriesTest myMeasurementSeriesTest;
	myMeasurementSeriesTest.array2();
	EXPECT_TRUE(myMeasurementSeriesTest.getMeasurementObject().isFull());
}

TEST(TestIsFullF, isFull)
{
	MeasurementSeriesTest myMeasurementSeriesTest;
	myMeasurementSeriesTest.array1(9);
	EXPECT_FALSE(myMeasurementSeriesTest.myMeasurements.isFull());
}

TEST(TestExistF, valueExists)
{
	MeasurementSeriesTest myMeasurementSeriesTest;
	myMeasurementSeriesTest.array1(10);
	EXPECT_FALSE(myMeasurementSeriesTest.myMeasurements.valueExists(11));
}

TEST(TestExistT, valueExists)
{
	MeasurementSeriesTest myMeasurementSeriesTest;
	myMeasurementSeriesTest.array1(10);
	EXPECT_TRUE(myMeasurementSeriesTest.myMeasurements.valueExists(0));
}

TEST(TestgetValue, getValue)
{
	MeasurementSeriesTest myMeasurementSeriesTest;
	myMeasurementSeriesTest.array1(10);
	EXPECT_EQ(myMeasurementSeriesTest.myMeasurements.getValue(1),1);	
}


TEST(TestGetNrMeasurements, getNrMeasurements)
{
	int number = 0;
	MeasurementSeriesTest myMeasurementSeriesTest;
	myMeasurementSeriesTest.array1(10);
	myMeasurementSeriesTest.myMeasurements.getNrMeasurements(number);
	EXPECT_EQ(number,10);
}


