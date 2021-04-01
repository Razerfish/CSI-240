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

#ifndef _COMIC_H
#define _COMIC_H

#include <iostream>
#include <iomanip>
#include <string>

#include "book.h"

using namespace std;

class Comic : public Book
{
private:
	int mVolume;
	int mSeries;

public:
	// Constructors
	Comic();
	Comic(string code, string title, string author, double price, int quantity, int volume, int series);

	// Destructor
	~Comic();

	// Accessors
	int getSeries();
	int getVolume();

	// Mutators
	void setSeries(int series);
	void setVolume(int volume);

	// Friend functions
	friend istream& operator >>(istream& input, Comic& comic);
	friend ostream& operator <<(ostream& output, const Comic& comic);
};

#endif
