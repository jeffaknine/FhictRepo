/*
 * Fruit.h
 *
 *  Created on: Sep 10, 2013
 *  Author: P. Lambooij
 */

#ifndef FRUIT_H
#define FRUIT_H

#include <string>
using namespace std;

class Fruit
{
	private:

	public:
		Fruit();
		/*	pre :
			post: object Fruit has been constructed
		*/

		virtual ~Fruit(void);
        /*  pre :
            post: object Fruit was deleted
        */

        void PrepareNonVirtual();
        /*  pre :
            post: object Fruit has been prepared for eating
        */

        virtual void Prepare();
        /*  virtual version of FruitPrepare */
};

#endif /* FRUIT_H_ */
