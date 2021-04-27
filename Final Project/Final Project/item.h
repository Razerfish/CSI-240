/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: Final Project
Date Assigned: April 5 2021
Due Date: April 29 2021
Description: Create a management system for the Champlain bookstore.
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

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Item
{
private:
	string mCode;
	double mPrice;
	int mStock;

public:
	// Constructors
	Item();
	Item(string code, double price, int stock);

	// Destructor
	~Item();

	// Accessors
	string getCode();
	double getPrice();
	int getStock();

	// Mutators
	void setCode(string code);
	void setPrice(double price);
	void setStock(int stock);

	// Other
	virtual istream& load(istream& in);
	virtual ifstream& load(ifstream& in);

	virtual ostream& print(ostream& out);
	virtual ofstream& print(ofstream& out);

	// Operators
	bool operator ==(const string& rhs);
	bool operator !=(const string& rhs);

	// Friends
	friend istream& operator >>(istream& in, Item& obj);
	friend ifstream& operator >>(ifstream& in, Item& obj);

	friend ostream& operator <<(ostream& out, Item& obj);
	friend ofstream& operator <<(ofstream& out, Item& obj);
};

#endif
