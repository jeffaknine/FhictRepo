#include "EnhancedMeasurementSeries.h"
#include <iostream>
using namespace std;

EnhancedMeasurementSeries::EnhancedMeasurementSeries(string name)
: MeasurementSeries(name)

{
	nrDifferentValues = 0;
}

int EnhancedMeasurementSeries::getNrTimes(int value)
{
	int temp= 0;
	int count =0;
	MeasurementSeries::getNrMeasurements(temp);
	for (int i = 0; i < temp ; ++i)
	{
		if(MeasurementSeries::getValue(i)==value)
		{
			count++;
		}
	}
	return count;
}

void EnhancedMeasurementSeries::addSerie(const MeasurementSeries* serie)
{
	int measurementsCount = 0;	
	for (int i = 0; i < measurementsCount; ++i)
	{
		addValue(serie -> getValue(i));
		// cout << serie -> getValue(i) << " was added" << endl;
	}
		
}

void EnhancedMeasurementSeries::addValue(int value)
{
	if (valueExists(value) == false)
	{
		nrDifferentValues =  nrDifferentValues + 1;
	}
	MeasurementSeries::addValue(value);
	
	
}

int EnhancedMeasurementSeries::getNrDifferentValues()
{
	return nrDifferentValues;
}


