/*
 * Banana.h
 *
 *  Created on: Sep 10, 2013
 *  Author: P. Lambooij
 */
#ifndef BANANA_H
#define BANANA_H

#include "Fruit.h"
#include <string>
using namespace std;

class Banana: public Fruit
{
	private:

	public:
		Banana();
		/*	pre :
			post: object Banana has been constructed
		*/

		virtual ~Banana(void);
        /*  pre :
            post: object Banana was deleted
        */

        void PrepareNonVirtual();
        /*  pre :
            post: object Banana has been prepared for eating
        */

        virtual void Prepare();
        /*  virtual version of BananaPrepare */
};

#endif /* BANANA_H_ */
