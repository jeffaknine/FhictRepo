#include "EnhancedMeasurementSeries.h"
#include <iostream>
#include <string>

using namespace std;

void showMenu( void )
{
	cout << ("\n\nMeasurements MENU");
	cout << ("\n===========================");
	cout << ("\n(1) Show all values");
	cout << ("\n(2) Add a measurement value.");
	cout << ("\n(3) Test if another measurement value can be added");
	cout << ("\n(4) Show how often a certain value is stored");
	cout << ("\n(5) Show the measurement series' name");
	cout << ("\n(6) Change the measurement series' name");
	cout << ("\n(7) Test if a certain value is stored");
	cout << ("\n(8) Add measurement series m1 with value 8 and 9");
	cout << ("\n(9) Add enhanced measurement series mx1 with values -2 and -3");
	cout << ("\n(10) Show the number of different values");
	cout << ("\n(11) QUIT");
	cout <<  ("\n\nChoice : ");
}

void showAllValues( EnhancedMeasurementSeries myEnhanced)
{
	for (int i = 0; i < 10; ++i)
	{
		cout << "\nValue " << i << " = " << myEnhanced.getValue(i);
	}
}
void case2(EnhancedMeasurementSeries& myEnhanced)
{
	int addvalue = 0;
	if (myEnhanced.isFull() == true)
	{
		cout << "The array is full, no more measurement can be added" << endl;	
	}				
	else
	{
		cout << "Please enter the measurement value : "<<endl;
		cin >> addvalue;
		cin.ignore();
		myEnhanced.addValue(addvalue);
	}
}

void case3(EnhancedMeasurementSeries myEnhanced)
{
	if (myEnhanced.isFull() == true)
	{
		cout << "The array is full, no more measurement can be added" << endl;
	}
	else
	{
		cout << "The array isn't full, some measurement can be added" << endl;	
	}
}

void case4(EnhancedMeasurementSeries myEnhanced)
{	
	int number;
	cout << "Please enter a number :" << endl;
	cin >> number;
	cin.ignore();
	myEnhanced.getNrMeasurements(number);
	cout << number<<endl;
}


void case6(EnhancedMeasurementSeries& myEnhanced)
{
	string name = "";
	cout << "Please enter the new measurement series' name :" << endl;
	getline(cin,name);
	myEnhanced.setName(name);
	cout << "New name is : " << myEnhanced.getName();
}

void case7(EnhancedMeasurementSeries myEnhanced)
{
	int value = 0;
	cout << "Please enter the value you want to check :" << endl;
	cin >> value;
	cin.ignore();
	bool plop = myEnhanced.valueExists(value);
	if (plop == true)
	{
		cout << "Yes the value " << value << " is stored"<< endl;
	}
	else
	{
		cout << "No the value " << value << " is not stored" << endl;
	}
}

void case8(EnhancedMeasurementSeries myEnhanced)
{
	MeasurementSeries m1("m1");
	m1.addValue(8);
	m1.addValue(9);
	myEnhanced.addSerie(&m1);
}

void case9(EnhancedMeasurementSeries myEnhanced)
{
	EnhancedMeasurementSeries mx1("mx1");
	mx1.addValue(-2);
	mx1.addValue(-3);
	myEnhanced.addSerie(&mx1);
}

void case10(EnhancedMeasurementSeries myEnhanced)
{
	int nrOfDifferent = myEnhanced.getNrDifferentValues();
	cout << "The number of different values is " <<nrOfDifferent<<endl;
}
int main(void)
{
	bool quit = false;
	int choice;
	EnhancedMeasurementSeries myEnhanced("Plop");
	while (!quit)
	{
		showMenu();
		cin>>choice;    // C++ style i/o: chapter 3 in book
        //cin.ignore();       // C++ style i/o: chapter 3 in book

        switch (choice)
        {
        	case 1:
        	showAllValues(myEnhanced);
        	break;

        	case 2:
        	case2(myEnhanced);
        	break;

        	case 3:
        	case3(myEnhanced);
        	break;

        	case 4:
        	case4(myEnhanced);
        	break;

        	case 5:
        	cout << "Measurement Series' name is : " << myEnhanced.getName() <<endl;
        	break;

        	case 6:
        	case6(myEnhanced);
        	break;

        	case 7:
        	case7(myEnhanced);
        	break;

        	case 8:
        	case8(myEnhanced);
        	break;

        	case 9:
        	case9(myEnhanced);
        	break;
        	
        	case 10:
        	case10(myEnhanced);
        	break;

        	case 11:
        	quit = true;
        	break;
        	default:
        	cout << "\n\nI am terribly sorry for not understanding choice: " << choice;
        	break;
        }
    }
}