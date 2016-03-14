#include "MeasurementSeries.h"
#include <iostream>
using namespace std;

MeasurementSeries::MeasurementSeries(string owner)
{
	name = owner;
	count = 0;
	for (int i = 0; i < MaxMeasurementValues; ++i)
	{
		measurementData[i] = 0;
	}
}


std::string MeasurementSeries::getName() const
{
	return name;
}

void MeasurementSeries::setName(string owner)
{
	name = owner;
}

bool MeasurementSeries::isFull() const
{
	if (count == MaxMeasurementValues)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void MeasurementSeries::addValue(int value)
{
	measurementData[count] = value;
	count = count +1;
}

bool MeasurementSeries::valueExists(int value) const
{
	for(int i=0;i < count;++i)
	{
		if(measurementData[i]==value)
		{
			return true;
		}
	}
	return false;
}

int MeasurementSeries::getValue(int index) const
{
	if (measurementData[index] != 0)
	{
		return measurementData[index];
	}
	else return -1;
}

void MeasurementSeries::getNrMeasurements(int& number) const
{
	number=count;
}
