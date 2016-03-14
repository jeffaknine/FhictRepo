#ifndef ENHANCEDMEASUREMENTSERIES_H
#define ENHANCEDMEASUREMENTSERIES_H

#include "MeasurementSeries.h"
class EnhancedMeasurementSeries : public MeasurementSeries
{
    private:
	 int nrDifferentValues;

	public:
		EnhancedMeasurementSeries(string name);
		/*	pre :
			post: name stored
		*/

		int getNrTimes(int value);
		/*
			post: returns the number of times value is in EnhancedMeasurementSeries
		*/

		void addSerie(const MeasurementSeries* serie);
		/*	pre : enough empty measurement values are available
			post: All values from serie are added to <EnhancedMeasurementSeries>, nrDifferentValues is updated
		*/

		void addValue(int value);
		/*	pre : an empty measurement value is available
			post: value is added to <EnhancedMeasurementSeries>, nrDifferentValues is updated
		*/

		int getNrDifferentValues();
		/*	
			post: returns the number of different values in Enhanced
		*/
};

#endif
