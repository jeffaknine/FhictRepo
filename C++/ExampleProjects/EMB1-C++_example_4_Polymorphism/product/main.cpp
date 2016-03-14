/*
 *  main.cpp
 *
 *  Created on: Sep 10, 2013
 *  Author: P. Lambooij
 */

#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "Fruit.h"
#include "Apple.h"
#include "Banana.h"
#include "Orange.h"

int main()
{
    cout << "Some illustration of polymorphism and virtual member functions" << endl;
    vector<Fruit*> myFruitBasket;

    cout << endl << "Adding an apple:" << endl;
    myFruitBasket.push_back(new Apple());
    cout << endl << "Adding a banana:" << endl;
    myFruitBasket.push_back(new Banana());
    cout << endl << "Adding an orange:" << endl;
    myFruitBasket.push_back(new Orange());
    cout << endl << "Adding an unknown fruit:" << endl;
    myFruitBasket.push_back(new Fruit());

    cout << endl << "Preparing all my Fruit with PrepareNonVirtual(), static binding:" << endl;
    for (unsigned int i=0; i < myFruitBasket.size(); i++)
    {
        myFruitBasket.at(i)->PrepareNonVirtual();
    }

    cout << endl << "Preparing all my Fruit with Prepare(), dynamic binding:" << endl;
    for (unsigned int i=0; i < myFruitBasket.size(); i++)
    {
        myFruitBasket.at(i)->Prepare();
    }

    cout << endl << "Cleaning up all my fruit with the Fruit destructor, dynamic binding" << endl;
    for (unsigned int i=0; i < myFruitBasket.size(); i++)
    {
        delete myFruitBasket.at(i);
    }
}
