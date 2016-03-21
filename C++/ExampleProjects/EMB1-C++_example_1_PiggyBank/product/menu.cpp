//============================================================================
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

#include "PiggyBank.h"
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
	cout << ("\n[4] Show PiggyBank balance.");
	cout << ("\n[5] Test if PigyBank is Broken.");
	cout << ("\n[6] Break PiggyBank and return money");
	cout << ("\n[7] Quit.");
	cout <<  ("\n\nChoice : ");
}

int main( void )
{
	string name = "";
	bool quit = false;
	char choice = '\0';
	int amount = 0;

	PiggyBank myPiggyBank("Hagrid");

	while (!quit)
	{
		showMenu();
		cin.get(choice);    // C++ style i/o: chapter 3 in book
        cin.ignore();       // C++ style i/o: chapter 3 in book

		switch (choice)
		{
			case '1' :
				cout << "" << myPiggyBank.getOwnerName()<< endl;
				break;
			case '2' :
				cout << "Please enter new owner name : ";
				getline(cin, name);                              // C++ style i/o: chapter 3 in book
				myPiggyBank.setOwnerName(name);
				break;
			case '3' :
				if (myPiggyBank.isBroken())
					cout << "You cannot deposit money in a broken PiggyBank!" << endl;
				else
				{
					cout << "Please enter the amount you want to deposit: ";
					cin >> amount;
					cin.ignore();     // C++ style i/o: chapter 3 in book
					myPiggyBank.depositMoney(amount);
				}
				break;
			case '4' :
				if (myPiggyBank.isBroken())
					cout << "A broken PiggyBank can no longer contain money" << endl;
				else
					cout << "PiggyBank balance is: " << myPiggyBank.getBalance() << " Euro" << endl;
			    break;
			case '5' :
				if (myPiggyBank.isBroken())
					cout << "PiggyBank is dead-ish" << endl;
				else
					cout << "PiggyBank is alive and ready to store your money :)" << endl;
			    break;
			case '6' :
				if (myPiggyBank.isBroken())
					cout << "How dare you smashing an already tormented PiggyBank" << endl;
				else
				{
					amount = myPiggyBank.smash();
					cout << "Breaking the PiggyBank gave us 300 pieces of plastic and: " << amount << " Euro" << endl;
				}
				break;
			case '7' :
				quit = true;
				break;
			default:
				cout << "\n\nI am terribly sorry for not understanding choice: " << choice;
				break;
		}
	}



	return 0;
}
