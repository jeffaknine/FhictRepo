//==========================================s==================================
// Name        : menu.cpp
// Author      : Peter Lambooij
// Version     :
// Copyright   : copyright Peter Lambooij
// Description : Example code EMB1-C++ week 1
//
//				 Chapter 3 van the study book (Gaddis et al.):
//				 	 cin, cout, getline, cin.getc(), cin.ignore(), endl
//
//				 Chapter 7 of the book :
//					 Classes with constructor and member functions
//					 (properties like in C# do not exist in C++,
//					  and there is always a split-up in header and source file)
//
//				 Parameter passing is shown in C# style, as taught in PCSx courses.
//				 In the next example project another way of passing will be shown: "call-by-reference".
//============================================================================

#include "StorablePiggyBank.h"
#include <iostream>

#include <string>    // C++ has a so-called string class that resembles the C# String/string classes.
using namespace std; // These two lines (#include and using) are necessary to be able to use the C++ string class.

void showMenu( void )
{
	cout << ("\n\nPIGGYBANK MENU");
	cout << ("\n===========================");
	cout << ("\n[1] Show owner name.");
	cout << ("\n[2] Change owner name.");
	cout << ("\n[3] Deposit money in PiggyBank.");
	cout << ("\n[4] Test if PigyBank is Broken.");
	cout << ("\n[5] Break PiggyBank and return money");
	cout << ("\n[6] Save the PiggyBank state in a file.");
	cout << ("\n[7] Load the PiggyBank state from a file.");
	cout << ("\n[8] Show number of created piggybanks.");
	cout << ("\n[9] Exit.");
	cout << ("\n\nChoice : ");
}

int main( void )
{
	string name = "";
	bool quit = false;
	bool success = false;
	char choice = '\0';
	int amount = 0;

	StorablePiggyBank myStorablePiggyBank("Bill Gates");

	while (!quit)
	{
		showMenu();
		cin.get(choice);    // C++ style i/o: chapter 3 in book
        cin.ignore();       // C++ style i/o: chapter 3 in book

		switch (choice)
		{
			case '1' :
				cout << "" << myStorablePiggyBank.getOwnerName()<< endl;
				break;
			case '2' :
				cout << "Please enter new owner name : ";
				getline(cin, name); // C++ style i/o: chapter 3 in book
				myStorablePiggyBank.setOwnerName(name);
				break;
			case '3' :
				if (myStorablePiggyBank.isBroken())
					cout << "You cannot deposit money in a broken PiggyBank!" << endl;
				else
				{
					cout << "Please enter the amount you want to deposit: ";
					cin >> amount;
					cin.ignore();     // C++ style i/o: chapter 3 in book
					myStorablePiggyBank.depositMoney(amount);
				}
				break;
			case '4' :
				if (myStorablePiggyBank.isBroken())
					cout << "The piggybank is broken." << endl;
				else
					cout << "The piggybank is still intact." << endl;
			    break;
			case '5' :
				if (myStorablePiggyBank.isBroken())
					cout << "A piggybank cannot be smashed twice!" << endl;
				else
				{
					amount = myStorablePiggyBank.smash();
					cout << "Breaking the PiggyBank gave us 300 pieces of plastic and: " << amount << " Euro" << endl;
				}
				break;
			case '6' :
				cout << "Please enter file name: ";
				cin >> name;
				cin.ignore(); // C++ style i/o: chapter 3 in book
				success = myStorablePiggyBank.store(name);
				if (success)
				{
					cout << "Piggybank state was stored successfully." << endl;
				}
				else
				{
					cout << "Failed to store piggybank state." << endl;
				}
				break;
			case '7':
				cout << "Please enter file name: ";
				cin >> name;
				cin.ignore();
				success = myStorablePiggyBank.load(name);
				if (success)
				{
					cout << "Piggybank state was loaded successfully." << endl;
				}
				else
				{
					cout << "Failed to load piggybank state." << endl;
				}
				break;
			case '8':
				// static member functions are called like this: classname::functionname()
				cout << StorablePiggyBank::getNrOfObjects() << " piggybanks have been created" << endl;
				break;
			case '9':
				quit = true;
				break;
			default:
				cout << "\n\nInvalid choice:";
				break;
		}
	}

	return 0;
}
