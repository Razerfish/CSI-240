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

/*	Function: void customerSearch(Customer& database);
*	Pre: Provide the initialized database to search through
*	Post: The user will be prompted for a search query and
*	the results will be printed to the console.
*	Purpose: Search through the database.
*********************************************************/
void customerSearch(Customer& database)
{
	int selection = searchMenu();
	string query;

	switch (selection)
	{
	case 1: // Account num
		query = promptAccountNumber("Account number to search for: ");
		database.searchByAccountNum(query);
		break;
	case 2: // Address
		cout << "Address to search for: ";
		getline(cin, query);
		database.searchByAddress(query);
		break;
	case 3: // Name
		cout << "Name to search for: ";
		getline(cin, query);
		database.searchByName(query);
		break;
	case 4: // Phone number
		cout << "Phone number to search for: ";
		getline(cin, query); // Not enforcing formatting rules since we aren't entering data
		database.searchByPhoneNumber(query);
		break;
	case 5: // SSN
		cout << "SSN to search for: ";
		getline(cin, query); // Not enforcing formatting rules since we aren't entering data.
		database.searchBySSN(query);
		break;
	}
}


/*	Function: int searchMenu();
*	Pre: None.
*	Post: Returns a valid search type selection from the user.
*	Purpose: Prompt the user for a search type.
*********************************************************/
int searchMenu()
{
	int selection = -1;

	cout
		<< "Please select a search type:\n"
		<< "1. Search by account number\n"
		<< "2. Search by address\n"
		<< "3. Search by name\n"
		<< "4. Search by phone number\n"
		<< "5. Search by SSN\n\n"
		<< "Please enter your selection: ";

	cin >> selection;

	while (selection < 1 || selection > 5)
	{
		displayMessage(INVALID_SELECTION);

		cout
			<< "Please select a search type:\n"
			<< "1. Search by account number\n"
			<< "2. Search by address\n"
			<< "3. Search by name\n"
			<< "4. Search by phone number\n"
			<< "5. Search by SSN\n\n"
			<< "Please enter your selection: ";

		cin >> selection;
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return selection;
}
