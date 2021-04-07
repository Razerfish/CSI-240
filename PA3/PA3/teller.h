/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: PA3 - Part 1
Date Assigned: March 17 2021
Due Date: March 25 2021
Description: Create a class and a struct and write stub drivers for both of them.
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking)
*/

#ifndef _TELLER_H
#define _TELLER_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>

#include "employee.h"

class Teller
{
private:
	int mCount;
	Employee* mTellers;

public:
	// Default constructor
	Teller();

	// Default destructor
	~Teller();

	// Other
	bool loadData(string filename);
	void storeData(string filename);
	bool verifyTeller(const string& id, const string& password);
};

#endif
