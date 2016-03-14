#ifndef MEASUREMENTSERIES_H
#define MEASUREMENTSERIES_H

#include <string>
using namespace std;
const int MaxMeasurementValues = 10;

class MeasurementSeries
{
private:
	std::string name;
	int count;
	int measurementData[MaxMeasurementValues];

public:
	MeasurementSeries(std::string n);
	/*  pre : -
		post: MeasurementSeries has no measurement data, name is stored
	*/

	std::string getName() const;
	/*  pre : -
		post: MeasurementSeries' name is returned
	*/
	
	void setName(std::string name);
	/*  pre : -
		post: Name is stored
	*/

	bool isFull() const;
	/*  pre : -
		post: true if measurmentData is completely filled, else false
	*/

	void addValue(int value);
	/*  pre : measurementData is completely filled
		post: value is added to end of measurementData
	*/

	bool valueExists(int value) const;
	/*  pre : -
		post: true if value exists in measured values, else false
	*/

	int getValue(int index) const;
	/*  pre : 0 <= i <"nr measurement values"
		post: measurement value on position index is returned
	*/

	void getNrMeasurements(int& number) const;
	/*  pre : -
		post: returns current nr of measurements
	*/

};

#endif