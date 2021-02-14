/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: Lab 2
Date Assigned: February 8 2021
Due Date: February 15 2021
Description: An updated version of the PA1 COVID data parser
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

#include "header.h"

/*	Function: bool fileAvailable(string file)
*	Pre: A string containing the relative path to file that you want to check the existance of.
*	Post: Returns a bool representing whether or not the file exists.
*	Purpose: Check whether or not a file exists before attempting to read it or possibly overwrite it.
*	This is accomplished by checking if the file can be opened for reading, which in most cases serves as a good
*	enough proxy for a files existance, although it may run into problems for files that can be read from normally but
*	require elevated privileges to write to, so don't do that.
*********************************************************/
bool fileAvailable(string file)
{
	ifstream fileIN;
	bool exists = true;

	fileIN.open(file.c_str());

	if (fileIN.fail() || fileIN.bad())
	{
		exists = false;
	}

	fileIN.close();

	return exists;
}
