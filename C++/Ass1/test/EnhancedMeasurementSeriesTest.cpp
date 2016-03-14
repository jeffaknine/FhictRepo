#include "gtest/gtest.h"
#include "EnhancedMeasurementSeries.h"
#include <stdio.h>

using namespace std;

TEST(TestNrOfTimes, InitialNrOfTimesIsZero)
{
	EnhancedMeasurementSeries myEnhanced("Plop");
	EXPECT_EQ(0, myEnhanced.getNrTimes(1));
}

TEST(TestNrOfTimes, NrOfTimesIsOne)
{
	EnhancedMeasurementSeries myEnhanced("Plop");
	myEnhanced.addValue(1);
	EXPECT_EQ(1, myEnhanced.getNrTimes(1));	
}


TEST(TestNrOfTimes, NrOfTimesIsThree)
{
	EnhancedMeasurementSeries myEnhanced("Plop");
	myEnhanced.addValue(1);
	myEnhanced.addValue(1);
	myEnhanced.addValue(1);
	EXPECT_EQ(3, myEnhanced.getNrTimes(1));	
}


TEST(GetDifferent, InitialDifferentIsZero)
{
	EnhancedMeasurementSeries myEnhanced("Plop");
	EXPECT_EQ(0, myEnhanced.getNrDifferentValues());
}

TEST(GetDifferent, IsOne)
{
	EnhancedMeasurementSeries myEnhanced("Plop");
	myEnhanced.addValue(1);
	EXPECT_EQ(1, myEnhanced.getNrDifferentValues());
}

TEST(GetDifferent, IsThree)
{
	EnhancedMeasurementSeries myEnhanced("Plop");
	myEnhanced.addValue(1);
	myEnhanced.addValue(2);
	myEnhanced.addValue(3);
	myEnhanced.addValue(1);
	EXPECT_EQ(3, myEnhanced.getNrDifferentValues());
}