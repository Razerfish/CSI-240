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

#ifndef _VENDINGMACHINE_H
#define _VENDINGMACHINE_H

#include <iostream>
#include <iomanip> // Maybe?
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_LENGTH = 30;

const int MAX_STOCK = 20;

const int MIN_ITEMS = 4;

const double MIN_BALANCE = 5.00;

// Too many constants apparently?

struct Item
{
	string name = "";
	int quantity = 0;
	double price = 0.0;
};


class VendingMachine
{
private:
	Item items[MAX_LENGTH];
	int itemCount;
	double balance;
	string name;
	string password;

	/*
	Incorrect naming scheme.
	Should be:
	Item mItems[MAX_LENGTH];
	int mItemCount;
	double mBalance;
	string mName;
	string mPassword;
	*/

public:
	// Constructor
	VendingMachine();

	// Destructor
	~VendingMachine();

	// Accessors
	double getBalance();
	Item getItem(int index);
	int getItemCount();
	string getName();
	string getPassword();

	// Mutators
	void setBalance(double newBalance);
	void setItem(int index, Item newItem);
	void setItemCount(int newCount);
	void setName(string newName);
	void setPassword(string newPassword);

	// Other
	void showStockerMenu();
	void showUserMenu();
};

#endif
