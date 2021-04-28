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

#include "commonFunctions.h"


/*	Function: void clearScreen();
*	Pre: None
*	Post: The terminal will be cleared.
*	Purpose: Clear the terminal window.
*********************************************************/
void clearScreen()
{
	system("CLS");
}


/*	Function: int cashierMenu(Account& cashier);
*	Pre: The account of the cashier to greet.
*	Post: The cashier will be presented with the actions
*	they can perform and input will be prompted.
*	Purpose: Prompt the cashier for an action.
*********************************************************/
int cashierMenu(Account& cashier)
{
	int choice = 0;

	cout
		<< "\nHello " << cashier.getName() << "!\n"
		<< "Please enter your desired action:\n\n"
		<< "1. Add item to cart\n"
		<< "2. Remove item from cart\n"
		<< "3. Search items\n"
		<< "4. Checkout\n"
		<< "5. Cancel transaction\n"
		<< "6. Logout\n\n"
		<< "Enter your selection: ";

	cin >> choice;

	while (choice < 1 || choice > 6 || cin.fail())
	{
		clearScreen();
		cin.ignore(INT_MAX, '\n');
		cin.clear();

		cout
			<< "Invalid selection!\n"
			<< "Please enter your desired action:\n\n"
			<< "1. Add item to cart\n"
			<< "2. Remove item from cart\n"
			<< "3. Search items\n"
			<< "4. Checkout\n"
			<< "5. Cancel transaction\n"
			<< "6. Logout\n\n"
			<< "Enter your selection: ";

		cin >> choice;
	}

	// Cleanup for possible future getlines
	cin.ignore(INT_MAX, '\n');
	cin.clear();

	return choice;
}


/*	Function: int managerMenu(Account& manager);
*	Pre: The manager to greet.
*	Post: The user will be prompted for an action.
*	Purpose: Get the user to choose an action.
*********************************************************/
int managerMenu(Account& manager)
{
	int choice = 0;

	cout
		<< "Hello " << manager.getName() << "!\n"
		<< "Please enter your desired action:\n\n"
		<< "1. Generate daily report\n"
		<< "2. Search cashiers\n"
		<< "3. Update cashier information\n"
		<< "4. Hire cashier\n"
		<< "5. Fire cashier\n"
		<< "6. Logout\n"
		<< "7. Shutdown system\n\n"
		<< "Enter your selection: ";

	cin >> choice;

	while (choice < 1 || choice > 7 || cin.fail())
	{
		clearScreen();
		cin.ignore(INT_MAX, '\n');
		cin.clear();

		cout
			<< "Invalid selection!\n"
			<< "Please enter your desired action:\n\n"
			<< "1. Generate daily report\n"
			<< "2. Search cashiers\n"
			<< "3. Update cashier information\n"
			<< "4. Hire cashier\n"
			<< "5. Fire cashier\n"
			<< "6. Logout\n"
			<< "7. Shutdown system\n\n"
			<< "Enter your selection: ";

		cin >> choice;
	}

	// Cleanup after cin extraction
	cin.ignore(INT_MAX, '\n');
	cin.clear();

	return choice;
}


/*	Function: string promptName(string message);
*	Pre: The message to prompt the user with.
*	Post: A non-blank name will be returned.
*	Purpose: Prompt the user for a name.
*********************************************************/
string promptName(string message)
{
	string name;

	cout << message;
	getline(cin, name);

	while (name.length() == 0)
	{
		cout << "Names cannot be blank!\n";
		cout << message;
		getline(cin, name);
	}

	return name;
}


/*	Function: string promptPassword(string message);
*	Pre: The message to prompt the user with.
*	Post: A non-blank password will be returned.
*	Purpose: Prompt the user for a password.
*********************************************************/
string promptPassword(string message)
{
	string password;

	cout << message;
	getline(cin, password);

	while (password.length() == 0)
	{
		cout << "Passwords cannot be blank!\n";
		cout << message;
		getline(cin, password);
	}

	return password;
}


/*	Function: int promptSearchType();
*	Pre: A cashier should be logged in.
*	Post: Prompts the user for the type of search
*	to perform.
*	Purpose: Prompt search type.
*********************************************************/
int promptSearchType()
{
	int choice;

	cout
		<< "What type of search should be performed?\n\n"
		<< "1. Book search\n"
		<< "2. Snack search\n"
		<< "3. Abort\n\n"
		<< "Enter your selection: ";

	cin >> choice;

	while (choice < 1 || choice > 3 || cin.fail())
	{
		clearScreen();

		cin.ignore(INT_MAX, '\n');
		cin.clear();

		cout
			<< "Invalid selection!\n"
			<< "What type of search should be performed?\n\n"
			<< "1. Book search\n"
			<< "2. Snack search\n"
			<< "3. Abort\n\n"
			<< "Enter your selection: ";
	}

	cin.ignore(INT_MAX, '\n');
	cin.clear();

	return choice;
}


/*	Function: string promptUsername(string message);
*	Pre: The message to prompt the user with.
*	Post: Returns a valid username.
*	Purpose: Prompt the user for a valid username.
*********************************************************/
string promptUsername(string message)
{
	string username;
	bool valid = true;
	int i;

	cout << message;
	getline(cin, username);

	for (i = 0; i < username.length(); i++)
	{
		if (username[i] == ' ')
		{
			valid = false;
			break;
		}
	}

	while (!valid)
	{
		cout << "Invalid username, usernames cannot contain spaces.\n";
		cout << message;
		getline(cin, username);

		valid = true;
		for (i = 0; i < username.length(); i++)
		{
			if (username[i] == ' ')
			{
				valid = false;
				break;
			}
		}
	}

	return username;
}


/*	Function: void systemPause();
*	Pre: None
*	Post: Execution will be halted until the user presses
*	a key.
*	Purpose: Pause execution.
*********************************************************/
void systemPause()
{
	system("PAUSE");
}
