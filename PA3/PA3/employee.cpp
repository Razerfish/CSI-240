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

#include "employee.h"

/*	Function: istream& operator >>(istream& input, Employee& obj
*	Pre: None.
*	Post: The Employee object will be populated using the contents of
*	the input stream.
*	Purpose: Populate an Employee object from an input stream.
*********************************************************/
istream& operator >>(istream& input, Employee& obj)
{
	input >> obj.ID;
	input >> obj.password;

	// Discard rest of line

	input.ignore(INT_MAX, '\n');
	input.clear();

	return input;
}


/*	Function: ostream& operator <<(ostream& output, const Employee& obj);
*	Pre: None.
*	Post: The ID and password of the Employee object will be output into
*	the output stream.
*	Purpose: Output the contents of an Employee object.
*********************************************************/
ostream& operator <<(ostream& output, const Employee& obj)
{
	output << obj.ID << ' ' << obj.password << endl;
	return output;
}
