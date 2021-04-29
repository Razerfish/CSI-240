/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: Final Project
Date Assigned: April 5 2021
Due Date: April 29 2021
Description: Create a management system for the Champlain bookstore.
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

#include "store.h"
#include "mainFunctions.h"
#include "commonFunctions.h"

using namespace std;

int main()
{
	bool shutdown = false;

	Store database;
	Account user;

	if (!load(database))
	{
		return 1;
	}

	clearScreen();

	while (!shutdown)
	{
		user = database.login();
		shutdown = true;

		if (user.isManager())
		{
			shutdown = managerLoop(database, user);
			systemPause();
			clearScreen();
		}
		else
		{
			cashierLoop(database, user);
		}
	}
}
