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

#include <iostream>
#include <string>
#include <sstream>

#include "employee.h"

using namespace std;

int main()
{
	Employee test;

	string data = "j-doe happy";
	istringstream input(data);

	cout << "Test input: " << data << endl;

	input >> test;

	cout
		<< "Output:\n"
		<< "ID: " << test.ID << endl
		<< "Password: " << test.password << endl;

	return 0;
}
