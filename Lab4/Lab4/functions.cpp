/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: Lab 4
Date Assigned: March 8 2021
Due Date: March 15 2021
Description: Create a dynamic array of Student objects.
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


/*	Function: int getTargetEntries();
*	Pre: None.
*	Post: Returns a number between 1 and 1000 indicating how many entries to read
*	into memory.
*	Purpose: Get the amount of entries to load.
*********************************************************/
int getTargetEntries()
{
	int entries;
	string line;

	cout << "Input the amount of entries to load (1-1000): ";

	getline(cin, line);

	// Attempt to convert the input to an int. Set entries to -1 if the conversion fails.
	try
	{
		entries = stoi(line);
	}
	catch (invalid_argument)
	{
		entries = -1;
	}

	while (entries < 1 || entries > 1000)
	{
		cout << "Invalid input. Enter a number between 1 and 1000: ";
		getline(cin, line);

		// Same method of attempting conversion as above.
		try
		{
			entries = stoi(line);
		}
		catch (invalid_argument)
		{
			entries = -1;
		}
	}

	return entries;
}
