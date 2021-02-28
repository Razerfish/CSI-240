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

#include "header.h"


/*	Function: void changePassword(VendingMachine& machine);
*	Pre: Authenticate the current password and pass a reference to the machine.
*	Post: The user will be propted for a new password and that password will be set
*	as the new machine password.
*	Purpose: Change the machines password.
*********************************************************/
void changePassword(VendingMachine& machine)
{
	string pass1, pass2;
	bool match = false;

	cout << "\n\nEnter the new password: ";
	pass1 = promptPassword();

	cout << "Re-enter the new password: ";
	pass2 = promptPassword();

	// If passwords don't match or are empty repeat until valid.
	while (pass1 != pass2 || (pass1 == "" && pass2 == ""))
	{
		if (pass1 == "" && pass2 == "")
		{
			cout << "\nPasswords cannot be blank!\n";
		}
		else
		{
			cout << "Passwords do not match!\n";
		}

		cout << "\nEnter the new password: ";
		pass1 = promptPassword();

		cout << "\nRe-enter the new password: ";
		pass2 = promptPassword();
	}

	machine.setPassword(pass1);
}


/*	Function: double collectMoney(VendingMachine& machine);
*	Pre: A reference to a VendingMachine object.
*	Post: Returns the amount of money that can be withdrawn without bringing
*	the machines balance below MIN_BALANCE and sets the machines balance to MIN_BALANCE.
*	If the machines balance is already less than MIN_BALANCE $0.00 will be returned
*	and the balance will not be changed.
*	Purpose: Collect the available money from the machine.
*********************************************************/
double collectMoney(VendingMachine& machine)
{
	double available = machine.getBalance() - MIN_BALANCE;

	if (available > 0)
	{
		machine.setBalance(MIN_BALANCE);
		return available;
	}
	else
	{
		return 0.00;
	}
}


/*	Function: void checkBalance(VendingMachine& machine);
*	Pre: A reference to a VendingMachine object.
*	Post: The current balance will be displayed.
*	Purpose: The machine balance will be displayed.
*********************************************************/
void checkBalance(VendingMachine& machine)
{
	cout << fixed << setprecision(2);
	cout << "\nThe current balance is: $" << machine.getBalance() << endl;
}


/*	Function: void createItem(VendingMachine& machine);
*	Pre: A reference to a VendingMachine object.
*	Post: A new item will be created using the users input.
*	Purpose: Add an item to a machine.
*********************************************************/
void createItem(VendingMachine& machine)
{
	// Check that there is room for another item.
	if (machine.getItemCount() >= MAX_LENGTH)
	{
		cout << "\nOut of space. Unable to add a new item.\n";
		return;
	}

	Item newItem;

	string line;

	cout << "\nEnter the name of the item: ";
	getline(cin, line);
	// Ensure that input is not blank.
	while (line == "")
	{
		cout << "Name cannot be blank.\nEnter the name of the item: ";
		getline(cin, line);
	}
	newItem.name = line;

	cout << "\nEnter the price of the item: ";
	getline(cin, line);
	// Ensure that input is not blank.
	while (line == "")
	{
		cout << "Price cannot be blank.\nEnter the price of the item: ";
		getline(cin, line);
	}
	newItem.price = stod(line);

	newItem.quantity = MAX_STOCK;

	machine.setItem(machine.getItemCount(), newItem);
	machine.setItemCount(machine.getItemCount() + 1);
}


/*	Function: void editItem(int index, VendingMachine& machine);
*	Pre: The index of the item to edit and a reference to a
*	VendingMachine object.
*	Post: The item at the selected index will be edited.
*	Purpose: Edit a given item.
*********************************************************/
void editItem(int index, VendingMachine& machine)
{
	// Validate index.
	if (index >= machine.getItemCount() || index < 0 || index > MAX_LENGTH)
	{
		cout << "\nInvalid index.\n";
		return;
	}

	Item newItem = machine.getItem(index);
	string line;

	// Change item name.
	cout << "\nEnter the new name for the item (or leave blank to not change): ";
	getline(cin, line);
	if (line != "")
	{
		newItem.name = line;
	}

	// Change item price.
	cout << "\nEnter the new price for the item (or leave blank to not change): ";
	getline(cin, line);
	if (line != "")
	{
		newItem.price = stod(line);
	}

	machine.setItem(index, newItem);
}


/*	Function: string promptPassword();
*	Pre: None
*	Post: The password that the user entered will be returned.
*	Purpose: Mask the users input while they are entering their password.
*********************************************************/
string promptPassword()
{
	// Code for this function adapted from here: http://www.cplusplus.com/reference/string/string/operator+=/

	char c;
	string password = "";

	while ((c = _getch()) != '\r')
	{
		// Handle backspace
		if (c == '\b')
		{
			// Only take action if the string is not empty.
			if (password.length() > 0)
			{
				password.pop_back();
				_putch('\b');
				_putch(' ');
				_putch('\b');
			}
		}
		else
		{
			password.push_back(c);
			_putch('*');
		}
	}
	cout << endl;

	return password;
}


/*	Function: void sellItem(int index, double payment, VendingMachine& machine);
*	Pre: The index of the item to sell and a reference to the VendingMachine object.
*	NOTE, the index of an item is NOT the same as the number that the user selects an item with.
*	To get the index from the input subtract 1.
*	Post: Money will be collected, the item stock will be reduced and change will be dispensed from
*	the machine balance. If the transaction is unable to be completed the money will be returned and
*	an error message will be displayed.
*	Purpose: Handle the sale of an item.
*********************************************************/
void sellItem(int index, double payment, VendingMachine& machine)
{
	Item target = machine.getItem(index);
	double change = payment - target.price;

	// Check that the user has enough money for the item.
	if (change < 0)
	{
		cout << "\n\nPayment insufficient.\nYour money has been returned.\n";
		return;
	}

	// Check that the item is in stock.
	if (target.quantity <= 0)
	{
		cout << "\n\nItem out of stock.\nYour money has been returned.\n";
		return;
	}

	// Check that we have enough money to give change.
	if (machine.getBalance() + payment < change)
	{
		cout << "\n\nUnable to give change\nYour money has been returned.\n";
		return;
	}

	// Sell item.
	machine.setBalance(machine.getBalance() + payment - change);

	target.quantity--;
	machine.setItem(index, target);

	cout << "\n\nThank you for your purchase!\nYour change is $" << change << endl;
}
