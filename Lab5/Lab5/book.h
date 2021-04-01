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

#ifndef _BOOK_H
#define _BOOK_H

#include <iostream>
#include <iomanip>
#include <string>

#include "item.h"

using namespace std;

class Book : public Item
{
private:
	string mTitle;
	string mAuthor;

public:
	// Constructors
	Book();
	Book(string code, string title, string author, double price, int quantity);

	// Destructor
	~Book();

	// Accessors
	string getAuthor() const;
	string getTitle() const;

	// Mutators
	void setAuthor(string author);
	void setTitle(string title);

	// Friend Functions
	friend istream& operator >>(istream& input, Book& book);
	friend ostream& operator <<(ostream& output, const Book& book);
};

#endif
