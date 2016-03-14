/*
 * Apple.h
 *
 *  Created on: Sep 10, 2013
 *  Author: P. Lambooij
 */
#ifndef APPLE_H
#define APPLE_H

#include "Fruit.h"
#include <string>
using namespace std;

class Apple: public Fruit
{
	private:

	public:
		Apple();
		/*	pre :
			post: object Apple has been constructed
		*/

		virtual ~Apple(void);
        /*  pre :
            post: object Apple was deleted
        */

        void PrepareNonVirtual();
        /*  pre :
            post: object Apple has been prepared for eating
        */

        virtual void Prepare();
        /*  virtual version of ApplePrepare */
};

#endif /* APPLE_H_ */
