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

using namespace std;

int main()
{
	/*
	clearScreen();

	double x;
	if (convertStr2Double("15.0", x))
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	cout << x << endl;

	if (convertStr2Double("dgfdg", x))
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	displayLogo();


	displayMessage(5);
	displayMessage(10);
	displayMessage(15);
	displayMessage(20);
	displayMessage(25);
	displayMessage(30);
	displayMessage(35);
	displayMessage(40);
	displayMessage(45);
	displayMessage(0);

	cout << toUpper("test123!") << endl;

	systemPause();

	cout << mainMenu() << endl;
	*/

	/*
	login();
	*/

	/*
	while (true)
	{
		cout << getPhoneNumber() << endl;
		cout << getSSN() << endl;
	}
	*/

	Customer database;

	database.setFilename(ACCOUNT_DATAFILE);
	database.loadData();

	database.deleteCustomer("9876");
}
