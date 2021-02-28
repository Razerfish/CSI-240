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

/*	Function: bool changeItemName(int index, string newName, VendingMachine& machine);
*	Pre: The index of the item whose name to change, the new name and a reference to
*	the VendingMachine object.
*	Post: The item at the provided index will have it's name change to the provided value.
*	If the provided index is valid but not listed this function will return false and the
*	value will not be changed.
*	Purpose: Change the name of any listed item stocked by a vending machine.
*********************************************************/
bool changeItemName(int index, string newName, VendingMachine& machine)
{
	Item newItem;

	// Prevent the user from changing the names of unlisted items.
	if (index > machine.getItemCount() - 1 || index < 0)
	{
		return false;
	}

	newItem = machine.getItem(index);

	newItem.name = newName;

	machine.setItem(index, newItem);

	return true;
}


/*	Function: bool changeItemPrice(int index, double newPrice, VendingMachine& machine);
*	Pre: The index of a listed whose price to change.
*	Post: If the item is listed the price will be changed and the function will return true,
*	otherwise the price will not be changed and the function will return false.
*	Purpose: Change the price of a listed item.
*********************************************************/
bool changeItemPrice(int index, double newPrice, VendingMachine& machine)
{
	Item newItem;

	// Prevent the user from changing the price of unlisted items.
	if (index > machine.getItemCount() - 1 || index < 0)
	{
		return false;
	}

	newItem = machine.getItem(index);

	newItem.price = newPrice;

	machine.setItem(index, newItem);

	return true;
}


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

	cout << "\nRe-enter the new password: ";
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
			cout << "\nPasswords do not match!\n";
		}

		cout << "\nEnter the new password: ";
		pass1 = promptPassword();

		cout << "\nRe-enter the new password: ";
		pass2 = promptPassword();
	}

	machine.setPassword(pass1);
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

	return password;
}
