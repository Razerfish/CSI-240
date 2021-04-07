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

#include "customer.h"
#include "banking.h"

using namespace std;

int main()
{
	int selection;
	bool proceed;

	Customer database;
	database.setFilename(ACCOUNT_DATAFILE);
	
	// Set precision
	cout << fixed << setprecision(2);

	if (!database.loadData())
	{
		displayMessage(ACCOUNT_DB_NOT_AVAILABLE);
		return 1;
	}

	while (true) // Always stay in this loop.
	{
		login();

		proceed = true;

		while (proceed)
		{
			selection = mainMenu();
			switch (selection)
			{
			case 1:
				addAccount(database);
				break;
			case 2:
				deleteAccount(database);
				break;
			case 3:
				updateAccount(database);
				break;
			case 4:
				customerSearch(database);
				break;
			case 5:
				deposit(database);
				break;
			case 6:
				withdraw(database);
				break;
			case 7:
				displayBalance(database);
				break;
			case 8:
				proceed = false;
				break;
			case 9:
				return 0;
			}
			systemPause();
			clearScreen();
		}
	}
}
