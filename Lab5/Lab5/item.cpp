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

#include "item.h"


/*********************************************************
*						Constructors					 *
*********************************************************/

/*	Function: Item::Item();
*	Pre: None
*	Post: All member variables will be set to default values.
*	Purpose: Default constructor.
*********************************************************/
Item::Item()
{
	mCode = "";
	mPrice = 0.0;
	mQuantity = 0;
}


/*	Function: Item::Item(string code, double price, int quantity);
*	Pre: Values to initialize with.
*	Post: All member variables will be set to the supplied values.
*	Purpose: Non-default constructor.
*********************************************************/
Item::Item(string code, double price, int quantity)
{
	mCode = code;
	mPrice = price;
	mQuantity = quantity;
}


/*********************************************************
*						Destructor						 *
*********************************************************/

/*	Function: Item::~Item();
*	Pre: None
*	Post: None
*	Purpsoe: Destructor
*********************************************************/
Item::~Item()
{

}


/*********************************************************
*						Accessors						 *
*********************************************************/

/*	Function: const string Item::getCode();
*	Pre: None
*	Post: Returns the code of the item.
*	Purpose: Get the code of an item.
*********************************************************/
string Item::getCode() const
{
	return mCode;
}


/*	Function: const double Item::getPrice();
*	Pre: None
*	Post: Returns the price of the item.
*	Purpose: Get the price of the item.
*********************************************************/
double Item::getPrice() const
{
	return mPrice;
}


/*	Function: const int Item::getQuantity();
*	Pre: None
*	Post: Returns the quantity of the item.
*	Purpose: Get the quantity of an item.
*********************************************************/
int Item::getQuantity() const
{
	return mQuantity;
}


/*********************************************************
*						Mutators						 *
*********************************************************/

/*	Function: void Item::setCode(string code);
*	Pre: The new code.
*	Post: The code of the item will be set to the supplied value.
*	Purpose: Change the code of an item.
*********************************************************/
void Item::setCode(string code)
{
	mCode = code;
}


/*	Function: void Item::setPrice(double price);
*	Pre: The new price.
*	Post: The price of the item will be set to the supplied value.
*	Purpose: Change the price of an item.
*********************************************************/
void Item::setPrice(double price)
{
	mPrice = price;
}


/*	Function: void Item::setQuantity(int quantity);
*	Pre: The new quantity.
*	Post: The quantity of the item will be set to the supplied value.
*	Purpose: Change the quantity of an item.
*********************************************************/
void Item::setQuantity(int quantity)
{
	mQuantity = quantity;
}


/*********************************************************
*						Friend Functions				 *
*********************************************************/

/*	Function: istream& operator >>(const istream& input, Item& item);
*	Pre: None
*	Post: Code, price and quantity are read from the stream.
*	Purpose: Read Item values from a stream.
*********************************************************/
istream& operator >>(istream& input, Item& item)
{
	string line;

	getline(input, item.mCode);

	getline(input, line);
	item.mPrice = stod(line);
	
	getline(input, line);
	item.mQuantity = stoi(line);

	return input;
}


/*	Function: ostream& operator <<(const ostream& output, const Item& item);
*	Pre: None
*	Post: Code, price and quantity will be output to the stream.
*	Purpose: Output the state of the object to the stream.
*********************************************************/
ostream& operator <<(ostream& output, const Item& item)
{
	output << fixed << setprecision(2);

	output
		<< item.mCode << endl
		<< item.mPrice << endl
		<< item.mQuantity << endl;

	return output;
}
