/*
 * Student.h
 *
 *  Created on: Sep 10, 2013
 *  Author: P. Lambooij
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

#include <string>
using namespace std;

class Student: public Person
{
	private:
		string nickName;

	public:
		Student();
		/*	pre :
			post: object Student has a nickname == ""
		*/

		Student(string firstName, string lastName, string nickName);
		/*	pre :
			post: object Student has nickName == nickName
		*/

		~Student(void);
        /*  pre :
            post:
        */
};

#endif /* STUDENT_H_ */
