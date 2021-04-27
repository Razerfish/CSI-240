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

#include "snack.h"

/*********************************************************
*						Constructors					 *
*********************************************************/

/*	Function: Snack::Snack();
*	Pre: None
*	Post: All member variables will be initialized to default
*	values.
*	Purpose: Default constructor.
*********************************************************/
Snack::Snack() : Item()
{
	mName = "";
}


/*	Function: Snack::Snack(string code, double price, int stock, string name);
*	Pre: Values to use.
*	Post: Member variables will be initialized to the supplied values.
*	Purpose: Parameterized constructor.
*********************************************************/
Snack::Snack(string code, double price, int stock, string name) : Item(code, price, stock)
{
	mName = name;
}


/*********************************************************
*						Deconstructor					 *
*********************************************************/

/*	Function: Snack::~Snack();
*	Pre: None
*	Post: None
*	Purpose: Deconstructor
*********************************************************/
Snack::~Snack()
{

}


/*********************************************************
*						Accessors						 *
*********************************************************/

/*	Function: string Snack::getName();
*	Pre: None
*	Post: The name of the snack will be returned.
*	Purpose: Get the name of a snack.
*********************************************************/
string Snack::getName()
{
	return mName;
}


/*********************************************************
*						Mutators						 *
*********************************************************/

/*	Function: void Snack::setName(string name);
*	Pre: The new name to use.
*	Post: The name of the snack will be changed to the
*	supplied value.
*	Purpose: Change the name of a snack item.
*********************************************************/
void Snack::setName(string name)
{
	mName = name;
}


/*********************************************************
*						Other							 *
*********************************************************/

/*	Function: istream& Snack::load(istream& in);
*	Pre: The stream to read from.
*	Post: The state of the object will be read from the stream.
*	Purpose: Load a snack object from a stream.
*********************************************************/
istream& Snack::load(istream& in)
{
	string line;

	getline(in, mCode);

	getline(in, line);
	mPrice = stod(line);

	getline(in, line);
	mStock = stoi(line);

	getline(in, mName);

	return in;
}


/*	Function: ifstream& Snack::load(ifstream& in);
*	Pre: The file stream to read from.
*	Post: The state of the object will be read from the stream.
*	Purpose: Load a snack object from a file stream.
*********************************************************/
ifstream& Snack::load(ifstream& in)
{
	string line;

	getline(in, mCode);

	getline(in, line);
	mPrice = stod(line);

	getline(in, line);
	mStock = stoi(line);

	getline(in, mName);

	return in;
}


/*	Function: ostream& Snack::print(ostream& out);
*	Pre: The stream to write to.
*	Post: The state of the object will be written to the stream.
*	Purpose: Write the state of the object to a stream.
*********************************************************/
ostream& Snack::print(ostream& out)
{
	out << fixed << setprecision(2);

	out
		<< mCode << endl
		<< mPrice << endl
		<< mStock << endl
		<< mName << endl;

	return out;
}


/*	Function: ofstream& Snack::print(ofstream& out);
*	Pre: The file stream to write to.
*	Post: The state of the object will be written to the stream.
*	Purpose: Write the state of the object to a file stream.
*********************************************************/
ofstream& Snack::print(ofstream& out)
{
	out << fixed << setprecision(2);

	out
		<< mCode << endl
		<< mPrice << endl
		<< mStock << endl
		<< mName << endl;

	return out;
}


/*********************************************************
*						Overloads						 *
*********************************************************/

/*	Function: bool Snack::operator ==(const Snack& rhs);
*	Pre: The snack item to compare.
*	Post: Returns true if the items have the same code,
*	otherwise returns false.
*	Purpose: Check if two snack objects have the same code.
*********************************************************/
bool Snack::operator ==(const Snack& rhs)
{
	return mCode == rhs.mCode;
}


/*	Function: bool Snack::operator ==(const string& rhs);
*	Pre: The string to compare to.
*	Post: Returns true if the string matches the snack
*	objects code, otherwise returns false.
*	Purpose: Compare a snack objects code with a string.
*********************************************************/
bool Snack::operator ==(const string& rhs)
{
	return rhs == mCode;
}


/*	Function: bool Snack::operator !=(const Snack& rhs);
*	Pre: The snack item to compare.
*	Post: Returns false if the items have the same code
*	otherwise returns true.
*	Purpose: Check if two snack object don't have the same
*	code.
*********************************************************/
bool Snack::operator !=(const Snack& rhs)
{
	return mCode != rhs.mCode;
}


/*	Function: bool Snack::operator !=(const string& rhs);
*	Pre: The string to compare to.
*	Post: Returns false if the string matches the snack
*	objects code, otherwise returns true.
*	Purpose: Compare a snack objects code with a string.
*********************************************************/
bool Snack::operator !=(const string& rhs)
{
	return rhs != mCode;
}


/*********************************************************
*						Friends							 *
*********************************************************/

/*	Function: bool operator ==(const string& rhs, const Snack& lhs);
*	Pre: The objects to compare.
*	Post: Returns true if the string matches the snacks code,
*	otherwise returns false.
*	Purpose: Compare a string with a snack objects code.
*********************************************************/
bool operator ==(const string& lhs, const Snack& rhs)
{
	return lhs == rhs.mCode;
}


/*	Function: bool operator !=(const string& lhs, const Snack& rhs);
*	Pre: The objects to compare.
*	Post: Returns false if the string matches the snacks code,
*	otherwise returns true.
*	Purpose: Compare a string with a snack objects code.
*********************************************************/
bool operator !=(const string& lhs, const Snack& rhs)
{
	return lhs != rhs.mCode;
}
