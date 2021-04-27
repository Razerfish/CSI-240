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

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "item.h"

using namespace std;

class Book : public Item
{
private:
	string mISBN;
	string mTitle;
	string mAuthor;

public:
	// Constructors
	Book();
	Book(string code, double price, int stock, string isbn, string title, string author);

	// Deconstructor
	~Book();

	// Accessors
	string getAuthor();
	string getISBN();
	string getTitle();

	// Mutators
	void setAuthor(string author);
	void setISBN(string isbn);
	void setTitle(string title);

	// Other
	istream& load(istream& in) override;
	ifstream& load(ifstream& in) override;

	ostream& print(ostream& out) override;
	ofstream& print(ofstream& out) override;

	// Operators
	bool operator ==(const Book& rhs);
	bool operator ==(const string& rhs);
	bool operator !=(const Book& rhs);
	bool operator !=(const string& rhs);

	// Friends
	friend bool operator ==(const string& lhs, const Book& rhs);
	friend bool operator !=(const string& lhs, const Book& rhs);
};

#endif
