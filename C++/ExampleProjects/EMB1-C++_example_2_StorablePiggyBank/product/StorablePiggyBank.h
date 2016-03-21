/*
 * StorablePiggyBank.h
 *
 *  Created on: Aug 31, 2012
 *      Author: Peter Lambooij
 */

#ifndef STORABLEPIGGYBANK_H_
#define STORABLEPIGGYBANK_H_

#include "PiggyBank.h"

class StorablePiggyBank: public PiggyBank
{
private:
	static int nrOfObjects;

	public:
		StorablePiggyBank();
		/*	pre :
			post: an object StorablePiggyBank has been created with
			owner, broken and balance identical to the base class
		*/

		StorablePiggyBank(string name);
		/*	pre :
			post: an object StorablePiggyBank has been created with
			owner = name and broken and balance identical to the base class
		*/

		StorablePiggyBank(string name, int amount);
		/*	pre :
			post: an object StorablePiggyBank has been created with
			owner, broken and balance identical to the base class
		*/

		virtual ~StorablePiggyBank();
		/*	pre :
			post: an object PiggyBank has been created with owner name "",
			broken is false and balance is 0
		*/

		bool store(string filename);
		/*	pre :
			post: The values of owner, balance and broken are stored in file filename.
		*/

		bool load(string filename);
		/*	pre :
			post: The values of owner, balance and broken are read from file filename.
		*/

		string serialize(void);
		/*	pre :
			post: The values of owner, balance and broken are packed in a string.
		*/

		bool deserialize(string stored);
		/*	pre :
			post: The values of owner, balance and broken are unpacked from string stored.
		*/

		static int getNrOfObjects();
		/* pre :
		   post: The number of StoredPiggyBank objects currently in memory is returned.
		*/
};

#endif /* STORABLEPIGGYBANK_H_ */
