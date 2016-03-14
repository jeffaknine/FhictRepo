/*
 * Orange.h
 *
 *  Created on: Sep 10, 2013
 *  Author: P. Lambooij
 */
#ifndef ORANGE_H
#define ORANGE_H

#include "Fruit.h"
#include <string>
using namespace std;

class Orange: public Fruit
{
	private:

	public:
		Orange();
		/*	pre :
			post: object Orange has been constructed
		*/

		virtual ~Orange(void);
        /*  pre :
            post: object Orange was deleted
        */

        void PrepareNonVirtual();
        /*  pre :
            post: object Orange has been prepared for eating
        */

        virtual void Prepare();
        /*  virtual version of OrangePrepare */
};

#endif /* ORANGE_H_ */
