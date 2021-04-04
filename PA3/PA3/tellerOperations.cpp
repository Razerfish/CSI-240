/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: PA3 - Part 3
Date Assigned: March 26 2021
Due Date: April 5 2021
Description: Make a banking system
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

#include "banking.h"

/*	Function: void getIdPassword(string& id, string& password);
*	Pre: The variables to store the id and password in.
*	Post: Prompts the user for their id and password.
*	Purpose: Get the id and password from the user.
*********************************************************/
void getIdPassword(string& id, string& password)
{
	cout << "Enter ID: ";
	getline(cin, id);

	cout << "Enter password: ";
	getline(cin, password);

	// Cleanup after getline.
	cin.clear();
}


/*	Function: void login();
*	Pre: None
*	Post: Prompt the user for an id and password until they enter a correct one.
*	Purpose: Loop until the user supplies valid login credentials.
*********************************************************/
void login()
{
	string id, password;

	// Loop until successful login
	while (true)
	{
		getIdPassword(id, password);

		if (validateLogin(id, password))
		{
			return;
		}
	}
}


/*	Function: bool validateLogin(string id, string password);
*	Pre: The id and password to check
*	Post: Returns true if the login info is valid, otherwise returns false.
*	Purpose: Check login info against the teller database.
*********************************************************/
bool validateLogin(string id, string password)
{
	Teller database;

	if (!database.loadData(TELLER_DATAFILE))
	{
		displayMessage(TELLER_DB_NOT_AVAILABLE);
		return false;
	}

	if (database.verifyTeller(id, password))
	{
		return true;
	}
	else
	{
		displayMessage(INVALID_CREDS);
		return false;
	}
}
