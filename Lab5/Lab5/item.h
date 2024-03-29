/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: Lab 5
Date Assigned: March 29 2021
Due Date: April 1 2021
Description: Create an item class, a book class that inherits from item and a comic class that inherits from book. Write a stub driver to test them all.
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

#ifndef _ITEM_H
#define _ITEM_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Item
{
protected:
	string mCode;
	double mPrice;
	int mQuantity;

public:
	// Constructors
	Item();
	Item(string code, double price, int quantity);

	// Destructor
	~Item();

	// Accessors
	string getCode() const;
	double getPrice() const;
	int getQuantity() const;

	// Mutators
	void setCode(string code);
	void setPrice(double price);
	void setQuantity(int quantity);

	// Friend functions
	friend istream& operator >>(istream& input, Item& item);
	friend ostream& operator <<(ostream& output, const Item& item);
};

#endif
