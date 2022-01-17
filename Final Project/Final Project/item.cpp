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

#include "item.h"

/*********************************************************
*						Constructors					 *
*********************************************************/

/*	Function: Item::Item();
*	Pre: None
*	Post: All member variables will be initialized.
*	Purpose: Default constructor.
*	Author: Fiona Wilson
*********************************************************/
Item::Item()
{
	mCode = "";
	mPrice = 0.0;
	mStock = 0;
}


/*	Function: Item::Item(string code, double price, int stock);
*	Pre: The values to initialize the object with.
*	Post: Member variables will be initialized using the
*	provided values.
*	Purpose: Paramaterized constructor.
*	Author: Fiona Wilson
*********************************************************/
Item::Item(string code, double price, int stock)
{
	mCode = code;
	mPrice = price;
	mStock = stock;
}


/*********************************************************
*						Destructor						 *
*********************************************************/

/*	Function: Item::~Item();
*	Pre: None
*	Post: None
*	Purpose: Destructor
*	Author: Fiona Wilson
*********************************************************/
Item::~Item()
{

}


/*********************************************************
*						Accessors						 *
*********************************************************/

/*	Function: string Item::getCode();
*	Pre: None
*	Post: Returns the code of the item.
*	Purpose: Get the code of an item.
*	Author: Fiona Wilson
*********************************************************/
string Item::getCode()
{
	return mCode;
}


/*	Function: double Item::getPrice();
*	Pre: None
*	Post: Returns the price of the item.
*	Purpose: Get the price of an item.
*	Author: Fiona Wilson
*********************************************************/
double Item::getPrice()
{
	return mPrice;
}


/*	Function: int Item::getStock();
*	Pre: None
*	Post: Returns the quantity of the item.
*	Purpose: Get the quantity of an item.
*	Author: Fiona Wilson
*********************************************************/
int Item::getStock()
{
	return mStock;
}


/*********************************************************
*						Mutators						 *
*********************************************************/

/*	Function: void Item::setCode(string code);
*	Pre: The new code.
*	Post: The code of the item will be set to the provided value.
*	Purpose: Change an items code.
*	Author: Fiona Wilson
*********************************************************/
void Item::setCode(string code)
{
	mCode = code;
}


/*	Function: void Item::setPrice(double price);
*	Pre: The new price.
*	Post: The price of the item will be set to the provided value.
*	Purpose: Change the price of an item.
*	Author: Fiona Wilson
*********************************************************/
void Item::setPrice(double price)
{
	mPrice = price;
}


/*	Function: void Item::setStock(int stock);
*	Pre: The new stock.
*	Post: The stock of the item will be set to the provided value.
*	Purpose: Change the stock of an item.
*	Author: Fiona Wilson
*********************************************************/
void Item::setStock(int stock)
{
	mStock = stock;
}


/*********************************************************
*						Other							 *
*********************************************************/

/*	Function: istream& Item::load(istream& in);
*	Pre: The stream to read from.
*	Post: The state of object will be updated using the data
*	from the stream.
*	Purpose: Read item state from a stream.
*	Author: Fiona Wilson
*********************************************************/
istream& Item::load(istream& in)
{
	string line;

	getline(in, mCode);
	
	getline(in, line);
	mPrice = stod(line);

	getline(in, line);
	mStock = stoi(line);

	return in;
}


/*	Function: ifstream& Item::load(ifstream& in);
*	Pre: The file stream to read from.
*	Post: The object state will be updated using the data
*	from the file stream.
*	Purpose: Read item state from a file stream.
*	Author: Fiona Wilson
*********************************************************/
ifstream& Item::load(ifstream& in)
{
	string line;

	getline(in, mCode);

	getline(in, line);
	mPrice = stod(line);

	getline(in, line);
	mStock = stoi(line);

	return in;
}


/*	Function: ostream& Item::print(ostream& out);
*	Pre: The stream to output to.
*	Post: The state of the object will be output to the stream.
*	Purpose: Output the item state to a stream.
*	Author: Fiona Wilson
*********************************************************/
ostream& Item::print(ostream& out)
{
	out << fixed << setprecision(2);

	out
		<< mCode << endl
		<< mPrice << endl
		<< mStock << endl;

	return out;
}


/*	Function: ofstream& Item::print(ofstream& out);
*	Pre: The file stream to output to.
*	Post: The item state will be output to the file stream.
*	Purpose: Output the state of the item to a file stream.
*	Author: Fiona Wilson
*********************************************************/
ofstream& Item::print(ofstream& out)
{
	out << fixed << setprecision(2);

	out
		<< mCode << endl
		<< mPrice << endl
		<< mStock << endl;

	return out;
}


/*********************************************************
*						Operators						 *
*********************************************************/

/*	Function: bool Item::operator ==(const string& rhs);
*	Pre: The string to compare the code to.
*	Post: Returns true if the string and the code match,
*	otherwise returns false.
*	Purpose: Check if a string is equal to an items code.
*	Author: Fiona Wilson
*********************************************************/
bool Item::operator ==(const string& rhs)
{
	return mCode == rhs;
}


/*	Function: bool Item::operator !=(const string& rhs);
*	Pre: The string to compare the code to.
*	Post: Returns true if the string and the code don't match
*	otherwise returns false.
*	Purpose: Check if a string is unequal to an items code.
*	Author: Fiona Wilson
*********************************************************/
bool Item::operator !=(const string& rhs)
{
	return mCode != rhs;
}


/*********************************************************
*						Friend Functions				 *
*********************************************************/

/*	Function: istream& operator >>(istream& in, Item& obj);
*	Pre: The input stream and Item to use.
*	Post: The data in the stream will be used to populated
*	the item object.
*	Purpose: Read Item state from a stream.
*	Author: Fiona Wilson
*********************************************************/
istream& operator >>(istream& in, Item& obj)
{
	return obj.load(in);
}


/*	Function: ifstream& operator >>(ifstream& in, Item& obj);
*	Pre: The input file stream and Item to use.
*	Post: The data in the file stream will be used to populate
*	the item object.
*	Purpose: Read Item state from a file stream.
*	Author: Fiona Wilson
*********************************************************/
ifstream& operator >>(ifstream& in, Item& obj)
{
	return obj.load(in);
}


/*	Function: ostream& operator <<(ostream& out, Item& obj);
*	Pre: The output stream and Item object to use.
*	Post: The Item state will be output to the stream.
*	Purpose: Output the Item state to a stream.
*	Author: Fiona Wilson
*********************************************************/
ostream& operator <<(ostream& out, Item& obj)
{
	return obj.print(out);
}


/*	Function: ofstream& operator <<(ofstream& out, Item& obj);
*	Pre: The file stream and Item object to use.
*	Post: The Item state will be output to the file stream.
*	Purpose: Output the Item state to a file stream.
*	Author: Fiona Wilson
*********************************************************/
ofstream& operator <<(ofstream& out, Item& obj)
{
	return obj.print(out);
}
