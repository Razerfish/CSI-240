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
	while (line == "" || !isDoubleString(line))
	{
		if (line.length() == 0)
		{
			cout << "Price cannot be blank.\nEnter the price of the item: ";
		}
		else
		{
			cout << "Price must be a number.\nEnter the price of the item: ";
		}
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
	while (!isDoubleString(line))
	{
		cout
			<< "Price must be either a number or blank\n"
			<< "Enter the new price for the item (or leave blank to not change): ";
		getline(cin, line);
	}
	if (line != "")
	{
		newItem.price = stod(line);
	}

	machine.setItem(index, newItem);
}


/*	Function: void firstTimeSetup(VendingMachine& machine);
*	Pre: A vending machine object that was unable to locate
*	a data.txt file.
*	Post: The user will be prompted for 4 items which will
*	be used to populate the vending machine.
*	Purpose: Run the first time setup.
*********************************************************/
void firstTimeSetup(VendingMachine& machine)
{
	cout << "data.txt not found! Initiating first time setup...\n";
	cout << "Creating entries for initial menu of " << MIN_ITEMS << " items\n";

	// Create items.
	for (int i = 0; i < MIN_ITEMS; i++)
	{
		cout << "\nItem " << i + 1 << endl;
		createItem(machine);
	}

	cout << "\nFirst time setup complete!\n";

	// Pause and clear screen.
	system("PAUSE");
	system("cls");
}


/*	Function: int getSelection();
*	Pre: None.
*	Post: Returns an int of the users selection.
*	Purpose: Loop until the user enters a valid selection.
*********************************************************/
int getSelection()
{
	string line;
	int selection;

	getline(cin, line);
	while (!isIntString(line) || line == "")
	{
		cout << "Invalid input. Try again: ";
		getline(cin, line);
	}

	selection = stoi(line);

	return selection;
}


/*	Function: double getPayment();
*	Pre: None.
*	Post: Returns a double of the users input.
*	Purpose: Loop until the user inputs a valid double.
*********************************************************/
double getPayment()
{
	string line;
	double value;

	getline(cin, line);
	while (!isDoubleString(line) || line == "")
	{
		cout << "Invalid input. Try again: ";
		getline(cin, line);
	}

	value = stod(line);

	return value;
}


/*	Function: bool isDoubleString(string input);
*	Pre: A string to check.
*	Post: Returns true if the string can be run through stod,
*	returns false if it cannot.
*	Purpose: Check whether a string can be converted into a double
*	by stod.
*********************************************************/
bool isDoubleString(string input)
{
	bool valid = true;
	for (int i = 0; i < input.length(); i++)
	{
		if (!(isdigit(input[i]) || input[i] == '.'))
		{
			valid = false;
			break;
		}
	}

	return valid;
}


/*	Function: bool isIntString(string input);
*	Pre: A string to check.
*	Post: Returns true if the string can be converted to an int,
*	otherwise returns false.
*	Purpose: Check if a string can be safely run through stoi.
*********************************************************/
bool isIntString(string input)
{
	bool valid = true;

	for (int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			valid = false;
			break;
		}
	}

	return valid;
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
	if (machine.getBalance() < change)
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


/*	Function: bool stockerMenu(VendingMachine& machine);
*	Pre: A reference to a VendingMachine obeject.
*	Post: Changes may be made through the stocker menu.
*	Returns true unless the program should be terminated.
*	Purpose: Display and handle the stocker menu.
*********************************************************/
bool stockerMenu(VendingMachine& machine)
{
	string line;

	int selection;
	int index;

	bool loop = true;

	while (loop)
	{
		machine.showStockerMenu();
		getline(cin, line);

		// Validate input.
		if (!isIntString(line) || line == "")
		{
			cout << "Invalid selection\n";
			system("PAUSE");
			system("cls");
			continue;
		}

		selection = stoi(line);

		// Check password.
		// I wasn't clear if you wanted the password entered just once
		// to access the stocker menu or every time that an option is selected
		// so I wrote this but commented it out so that testing is easier.
		/*
		cout << "Enter password: ";
		if (promptPassword() != machine.getPassword())
		{
			cout << "Incorrect password\n";
			system("PAUSE");
			system("cls");
			continue;
		}
		*/

		switch (selection)
		{
		case 1:
			changePassword(machine);
			cout << "Password changed. Please log in again to continue using the stocker menu\n";
			system("PAUSE");
			system("cls");

			return true;
		case 2:
			checkBalance(machine);
			break;
		case 3:
			cout << "\nCollected $" << collectMoney(machine) << endl;
			break;
		case 4:
			cout << "Enter the item to edit: ";
			getline(cin, line);
			while (!isIntString(line) || line == "")
			{
				cout << "Invalid input\nEnter the item to edit: ";
				getline(cin, line);
			}

			index = stoi(line);

			editItem(index - 1, machine);
			break;
		case 5:
			createItem(machine);
			break;
		case 6:
			cout << "Enter the item to delete: ";
			getline(cin, line);
			while (!isIntString(line) || line == "")
			{
				cout << "Invalid input\nEnter the item to delete: ";
				getline(cin, line);
			}

			index = stoi(line);

			removeItem(index - 1, machine);
			break;
		case 7:
			cout << "Enter the item to restock: ";
			getline(cin, line);
			while (!isIntString(line) || line == "")
			{
				cout << "Invalid input\nEnter the item to restock: ";
				getline(cin, line);
			}

			index = stoi(line);

			restockItem(index - 1, machine);
			break;
		case 8:
			restockAll(machine);
			break;
		case 9:
			return false;
		case 0:
			loop = false;
			break;
		default:
			cout << "Invalid selection\n";
			system("PAUSE");
			system("cls");
		}

		cout << endl;
		system("PAUSE");
		system("cls");
	}

	system("cls");
	return true;
}


/*	Function: void removeItem(int index, VendingMachine& machine);
*	Pre: The index of the item to be removed and a reference to a
*	VendingMachine object.
*	Post: The selected item will be removed, all remaining items will be shifted down
*	and the item count will be decremented by 1.
*	Purpose: Remove any given item.
*********************************************************/
void removeItem(int index, VendingMachine& machine)
{
	// Validate index.
	if (index >= machine.getItemCount() || index < 0 || index > MAX_LENGTH)
	{
		cout << "\nInvalid selection.\n";
		return;
	}

	// Check that we won't go below MIN_ITEMS.
	if (machine.getItemCount() - 1 < MIN_ITEMS)
	{
		cout << "Unable to remove item without going below minimum item count\n";
		return;
	}

	// Shift items down and overwrite the item to be removed.
	Item tmp;
	for (int i = index + 1; i < machine.getItemCount() + 1; i++)
	{
		tmp = machine.getItem(i);
		machine.setItem(i - 1, tmp);
	}

	machine.setItemCount(machine.getItemCount() - 1);

	cout << "\nItem deleted.\n";
}


/*	Function: void restockItem(int index, VendingMachine& machine);
*	Pre: The index of the item to restock and a reference to a
*	VendingMachine object.
*	Post: The selected item will be restocked.
*	Purpose: Restock any selected item.
*********************************************************/
void restockItem(int index, VendingMachine& machine)
{
	// Ensure that index is valid.
	if (index >= machine.getItemCount() || index < 0 || index > MAX_LENGTH)
	{
		cout << "\nInvalid selection.\n";
		return;
	}

	Item restock = machine.getItem(index);

	restock.quantity = MAX_STOCK;

	machine.setItem(index, restock);

	cout << "\nItem restocked\n";
}


/*	Function: void restockAll(VendingMachine& machine);
*	Pre: A reference to a VendingMaching object.
*	Post: All listed items will be restocked.
*	Purpose: Restock all items.
*********************************************************/
void restockAll(VendingMachine& machine)
{
	Item restock;

	for (int i = 0; i < machine.getItemCount(); i++)
	{
		restock = machine.getItem(i);
		restock.quantity = MAX_STOCK;
		machine.setItem(i, restock);
	}

	cout << "\nAll items restocked\n";
}


/*	Function: int vendLoop(VendingMachine& machine);
*	Pre: A reference to the VendingMachine object to use
*	in the loop.
*	Post: Will return with a code once the loop has ended.
*	Purpose: Handle the vending part of the vending machine.
*********************************************************/
int vendLoop(VendingMachine& machine)
{
	string password;

	int selection;

	double payment;

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
