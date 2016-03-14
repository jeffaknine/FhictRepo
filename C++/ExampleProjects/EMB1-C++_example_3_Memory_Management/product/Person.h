/*
 * Person.h
 *
 *  Created on: Sep 10, 2013
 *  Author: P. Lambooij
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
	private:
		string firstName;
		string lastName;

	public:
		Person();
		/*	pre :
			post: object Person has a name == ""
		*/

		Person(string firstName, string lastName);
		/*	pre :
			post: object Person has name == name
		*/

		virtual ~Person(void);
        /*  pre :
            post:
        */
};

#endif /* PERSON_H_ */
