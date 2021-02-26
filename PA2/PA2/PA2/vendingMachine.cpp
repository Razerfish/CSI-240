// Author: 
// Class: CSI-240-03
// Assignment: PA2
// Date Assigned: February 22 2021
// Due Date: March 1 2021
// Description: Simulate a vending machine.
// Certification of Authenticity:
// I certify that this is entirely my own work, except where I have given fully documented references to the work of others. I understand the definition and
// consequences of plagiarism and acknowledge that the assessor of this assignment
// may, for the purpose of assessing this assignment:
// - Reproduce this assignment and provide a copy to another member of
// academic staff; and/or
// - Communicate a copy of this assignment to a plagiarism checking service
// (which may then retain a copy of this assignment on its database for
// the purpose of future plagiarism checking)

#include "vendingMachine.h"

/*	Function: VendingMachine::VendingMachine();
*	Pre: None
*	Post: items, balance, name and password will be initialized.
*	Purpose: Initializes values from the contents of data.txt, or
*	if data.txt doesn't exist or is emtpy uses default values.
*********************************************************/
VendingMachine::VendingMachine()
{
	ifstream din;

	string line;

	name = "Something funny";

	din.open("data.txt");

	// Check that file exists and is not empty.
	if (din.good() && getline(din, line))
	{
		istringstream input(line);
		string token;

		// Read the first line of config data.
		// Item count.
		getline(input, token, ' ');
		itemCount = stoi(token);

		// Balance
		getline(input, token, ' ');
		balance = stod(token);

		// Password
		getline(input, token, ' ');
		password = token;


		// Fill item entries.
		for (int i = 0; i < itemCount; i++)
		{
			// Get item name.
			getline(din, items[i].name);

			// Get quantity and price.
			getline(din, line);
			input.str(line);
			input.clear();

			getline(input, token, ' ');
			items[i].quantity = stoi(token);

			getline(input, token, ' ');
			items[i].price = stod(token);
		}
	}
	// Otherwise use default values.
	else
	{
		itemCount = 0;
		balance = 0.0;
		password = "password";
	}

	din.close();
}


VendingMachine::~VendingMachine()
{
}
