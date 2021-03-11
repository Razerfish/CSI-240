// Author: Fiona Wilson
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
		// Check that itemCount is less than or equal to MAX_LENGTH
		// and alert the user and default to MAX_LENGTH if it isnt.
		if (itemCount > MAX_LENGTH)
		{
			// Sorry if the formatting here is weird, I'm working on this on my laptop
			// and the screen doesn't fit much.
			cerr
				<< "\nUnable to load all items."
				<< endl << itemCount << " items supplied but MAX_LENGTH is " << MAX_LENGTH
				<< "\nDefaulting to MAX_LENGTH and ignoring extra items.\n";

			itemCount = MAX_LENGTH;
		}

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
		balance = 5.00;
		password = "password";
	}

	din.close();
}


/*	Function: VendingMachine::~VendingMachine();
*	Pre: None
*	Post: The current state of the VendingMachine will be written to data.txt.
*	Purpose: Store the state of the object on destruction.
*********************************************************/
VendingMachine::~VendingMachine()
{
	ofstream dout;

	// Open and file and clear it's contents.
	dout.open("data.txt", ios::out | ios::trunc);

	// Check that the output stream is good.
	if (dout.good())
	{
		// If so, write the machine state to file.

		// Set precision to 2.
		dout << fixed << setprecision(2);

		// Write itemCount, balance and password.
		dout << itemCount << " " << balance << " " << password << endl;

		// Write item entries.
		for (int i = 0; i < itemCount; i++)
		{
			dout
				<< items[i].name << endl
				<< items[i].quantity << " "
				<< items[i].price << endl;
		}
	}
	else
	{
		// Otherwise alert the user.
		cerr << "\nFailed to write machine state to file.\n";
	}

	// Forgot to close output file.
}


/*********************************************************
*						Accessors						 *
*********************************************************/

/*	Function: double getBalance();
*	Pre: None.
*	Post: Returns the current balance.
*	Purpose: Get the current balance of the machine.
*********************************************************/
double VendingMachine::getBalance()
{
	return balance;
}


/*	Function: Item VendingMachine::getItem(int index);
*	Pre: Supply the index of the item to retrieve, this value will
*	be clamped between 0 and MAX_LENGTH - 1.
*	Post: The item at the given index will be returned.
*	Purpose: Retrieve the given item.
*********************************************************/
Item VendingMachine::getItem(int index)
{
	if (index < 0)
	{
		index = 0;
	}
	else if (index > MAX_LENGTH - 1)
	{
		index = MAX_LENGTH - 1;
	}

	return items[index];
}


/*	Function: int VendingMachine::getItemCount();
*	Pre: None.
*	Post: Returns the amount of items loaded.
*	Purpose: Get the amount of items loaded into the vending machine.
*********************************************************/
int VendingMachine::getItemCount()
{
	return itemCount;
}


/*	Function: string VendingMachine::getName();
*	Pre: None.
*	Post: Returns the name of the machine.
*	Purpose: Get the name of the machine.
*********************************************************/
string VendingMachine::getName()
{
	return name;
}


/*	Function: string VendingMachine::getPassword();
*	Pre: None.
*	Post: Returns the machines current password.
*	Purpose: Get the current password of the machine.
*********************************************************/
string VendingMachine::getPassword()
{
	return password;
}


/*********************************************************
*						Mutators						 *
*********************************************************/

/*	Function: void VendingMaching::setBalance(double newBalance);
*	Pre: Supply the new value to store as the balance.
*	Post: The balance of the machine will be set to the supplied value.
*	Purpose: Change the value of the balance to the supplied value.
*********************************************************/
void VendingMachine::setBalance(double newBalance)
{
	balance = newBalance;
}


/*	Function: void VendingMachine::setItem(int index, Item newItem);
*	Pre: The index of the item to change and the value to change it to.
*	The index will be clamped between 0 and MAX_LENGTH - 1.
*	Post: The item at the supplied index will be changed to the supplied item.
*	Purpose: Change the item at the given index.
*********************************************************/
void VendingMachine::setItem(int index, Item newItem)
{
	if (index < 0)
	{
		index = 0;
	}
	else if (index > MAX_LENGTH - 1)
	{
		index = MAX_LENGTH - 1;
	}

	items[index] = newItem;
}


/*	Function: void VendingMachine::setItemCount(int newCount);
*	Pre: The new amount of items that the machine stocks.
*	Post: The item count will be set to the supplied value.
*	Purpose: Change the itemCount to a supplied value.
*********************************************************/
void VendingMachine::setItemCount(int newCount)
{
	itemCount = newCount;
}


/*	Function: void VendingMachine::setName(string newName);
*	Pre: The new name of the machine.
*	Post: The name of the machine will be set to the supplied value.
*	Purpose: Change the name of the machine.
*********************************************************/
void VendingMachine::setName(string newName)
{
	name = newName;
}


/*	Function: void VendingMachine::setPassword(string newPassword);
*	Pre: The new password for the machine.
*	Post: The passowrd of the machine will be set to the supplied value.
*	Purpose: Change the password for the machine.
*********************************************************/
void VendingMachine::setPassword(string newPassword)
{
	password = newPassword;
}


/*********************************************************
*						Other							 *
*********************************************************/


/*	Function: void VendingMachine::showStockerMenu();
*	Pre: User should input the secret phrase before the stocker
*	menu is shown.
*	Post: The stocker menu will be displayed in the console.
*	Purpose: Display the stocker menu.
*********************************************************/
void VendingMachine::showStockerMenu()
{
	cout
		<< "\t1. Change password\n"
		<< "\t2. Check balance\n"
		<< "\t3. Collect money\n"
		<< "\t4. Edit item\n"
		<< "\t5. Add item\n"
		<< "\t6. Remove item\n"
		<< "\t7. Restock item\n"
		<< "\t8. Restock all items\n"
		<< "\t9. Shutdown machine\n"
		<< "\t0. Exit stocker menu\n"
		<< "\n\tInput your selection: ";
}


/*	Function: void VendingMachine::showUserMenu();
*	Pre: None.
*	Post: The user menu will be displayed in the console.
*	Purpose: Display the user menu.
*********************************************************/
void VendingMachine::showUserMenu()
{
	// Loop through and display items.
	for (int i = 0; i < itemCount; i++)
	{
		cout << "\t" << i + 1 << ". " << items[i].name << " $" << items[i].price << endl;
	}

	cout << "\nPlease enter your selection: ";
}
