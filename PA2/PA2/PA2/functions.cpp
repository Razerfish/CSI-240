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
	if (index > machine.getItemCount() - 1)
	{
		return false;
	}

	newItem = machine.getItem(index);

	newItem.name = newName;

	machine.setItem(index, newItem);

	return true;
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
		password.push_back(c);
		_putch('*');
	}

	return password;
}
