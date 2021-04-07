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

/*	Function: void clearScreen();
*	Pre: None
*	Post: The console will be cleared.
*	Purpose: Clear the console.
*********************************************************/
void clearScreen()
{
	system("CLS");
}


/*	void displayLogo();
*	Pre: None
*	Post: The bank logo will be printed to the console.
*	Purpose: Display the bank's logo.
*********************************************************/
void displayLogo()
{
	cout
		<< string(50, '$') << endl
		<< setw(15) << left << '$'
		<< "Generic Credit Union"
		<< setw(15) << right << '$' << endl
		<< string(50, '$') << endl << endl;
}


/*	Function: void displayMessage(int errorCode);
*	Pre: The code of the message to display.
*	Post: The message with the corrasponding code will be displayed.
*	Purpose: Display an error message.
*********************************************************/
void displayMessage(int errorCode)
{
	switch (errorCode)
	{
	case 5:
		cout << "ERROR:	ACCOUNT ALREADY EXISTS\n";
		break;
	case 10:
		cout << "ERROR: ACCOUNT NOT FOUND\n";
		break;
	case 15:
		cout << "ERROR: INSUFFICIENT FUNDS FOR WITHDRAWL\n";
		break;
	case 20:
		cout << "ERROR: INVALID AMOUNT\n";
		break;
	case 25:
		cout << "ERROR: INVALID INPUT\n";
		break;
	case 30:
		cout << "ERROR: INVALID LOGIN CREDENTIALS\n";
		break;
	case 35:
		cout << "ERROR: INVALID SELECTION\n";
		break;
	case 40:
		cout << "ERROR: ACCOUNT DATABASE NOT AVAILABLE\n";
		break;
	case 45:
		cout << "ERROR: TELLER DATABASE NOT AVAILABLE\n";
		break;
	default:
		cout << "ERROR: UNKNOWN ERROR CODE: " << errorCode << endl;
	}
}


/*	Function: int mainMenu();
*	Pre: None
*	Post: Returns an int containing the validated selection
*	from the teller.
*	Purpose: Display the main menu to the teller and get their selection.
*********************************************************/
int mainMenu()
{
	int selection;

	// Loop until we get good input
	while (true)
	{
		clearScreen();
		displayLogo();

		cout
			<< "1. Add acccount\n"
			<< "2. Delete account\n"
			<< "3. Update account information\n"
			<< "4. Search accounts\n"
			<< "5. Deposit\n"
			<< "6. Withdrawl\n"
			<< "7. Check balance\n"
			<< "8. Logout\n"
			<< "9. Shutdown\n"
			<< "\nInput your selection: ";

		cin >> selection;

		if (cin.fail())
		{
			selection = 0;
		}

		// Clear cin of leftover input
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		if (selection > 0 && selection < 10)
		{
			return selection;
		}

		displayMessage(INVALID_SELECTION);
		systemPause();
	}
}


/*	Function: void systemPause();
*	Pre: None
*	Post: Execution is paused until a key is pressed.
*	Purpose: Pause the program.
*********************************************************/
void systemPause()
{
	system("PAUSE");
}
