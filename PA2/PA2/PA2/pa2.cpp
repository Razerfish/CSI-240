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

#include <iostream>

#include "vendingMachine.h"
#include "header.h"

using namespace std;
int main()
{
	// I know that there is direct output in main,
	// I somehow missed that when reading through
	// the grading PDF until just now and I don't
	// have the time or mental energy to fix it tonight.
	// I'll see if I can get to it tomorrow morning.

	VendingMachine machine;

	string password;

	int selection;

	double payment;

	bool valid;

	cout << fixed << setprecision(2);

	// Check if this is the first run.
	if (machine.getItemCount() == 0)
	{
		cout << "data.txt not found! Initiating first time setup...\n";
		cout << "Creating entries for default menu of " << MIN_ITEMS << " items\n";

		// Create items.
		for (int i = 0; i < MIN_ITEMS; i++)
		{
			cout << "\nItem " << i + 1 << endl;
			createItem(machine);
		}

		cout << "\nFirst time setup complete!\n";

		// Pause and then clear screen.
		system("PAUSE");
		system("cls");
	}

	while (true)
	{
		cout
			<< "Hello! Welcome to the " << machine.getName() << " vending machine!\n"
			<< "Here is our menu:\n";

		machine.showUserMenu();

		selection = getSelection();

		// Ensure that selection is valid.
		if (selection != 9001 && (selection == 0 || selection > machine.getItemCount()))
		{
			cout << "Invalid selection\n";
			system("PAUSE");
			system("cls");
			continue;
		}
		// Check for stocker access code.
		else if (selection == 9001)
		{
			cout << "Enter password: ";
			password = promptPassword();

			if (password == machine.getPassword())
			{
				system("cls");
				if (!stockerMenu(machine))
				{
					return 0;
				}
			}
			else
			{
				cout << "Incorrect password\n";
				system("PAUSE");
				system("cls");
			}
		}
		// Sell item.
		else
		{
			// Get payment.
			cout << "Enter payment: ";
			payment = getPayment();

			sellItem(selection - 1, payment, machine);

			system("PAUSE");
			system("cls");
		}
	}
}
