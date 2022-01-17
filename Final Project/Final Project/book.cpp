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

#include "book.h"


/*********************************************************
*						Constructors					 *
*********************************************************/

/*	Function: Book::Book();
*	Pre: None.
*	Post: All member variables will be initialized.
*	Purpose: Default constructor.
*	Author: Fiona Wilson
*********************************************************/
Book::Book() : Item()
{
	mISBN = "";
	mTitle = "";
	mAuthor = "";
}


/*	Function: Book::Book(string code, double price, int stock, string isbn, string author, string title);
*	Pre: Initial values.
*	Post: Member variables will be initialized with the provided values.
*	Purpose: Paramaterized constructor.
*	Author: Fiona Wilson
*********************************************************/
Book::Book(string code, double price, int stock, string isbn, string title, string author) : Item(code, price, stock)
{
	mISBN = isbn;
	mTitle = title;
	mAuthor = author;
}


/*********************************************************
*						Destructor						 *
*********************************************************/

/*	Function: Book::~Book();
*	Pre: None
*	Post: None
*	Purpose: Destructor
*	Author: Fiona Wilson
*********************************************************/
Book::~Book()
{

}


/*********************************************************
*						Accessors						 *
*********************************************************/

/*	Function: string Book::getAuthor();
*	Pre: None
*	Post: Returns the author.
*	Purpose: Get the author of a book.
*	Author: Fiona Wilson
*********************************************************/
string Book::getAuthor()
{
	return mAuthor;
}


/*	Function: string Book::getISBN();
*	Pre: None
*	Post: Returns the ISBN.
*	Purpose: Get the ISBN of a book.
*	Author: Fiona Wilson
*********************************************************/
string Book::getISBN()
{
	return mISBN;
}


/*	Function: string Book::getTitle();
*	Pre: None
*	Post: Returns the title.
*	Purpose: Get the title of a book.
*	Author: Fiona Wilson
*********************************************************/
string Book::getTitle()
{
	return mTitle;
}


/*********************************************************
*						Mutators					 *
*********************************************************/

/*	Function: void Book::setAuthor(string author);
*	Pre: The new author.
*	Post: The author of the book will be updated.
*	Purpose: Change the author of a book.
*	Author: Fiona Wilson
*********************************************************/
void Book::setAuthor(string author)
{
	mAuthor = author;
}


/*	Function: void Book::setISBN(string isbn);
*	Pre: The new ISBN.
*	Post: The ISBN of the book will be updated.
*	Purpose: Change the ISBN of a book.
*	Author: Fiona Wilson
*********************************************************/
void Book::setISBN(string isbn)
{
	mISBN = isbn;
}


/*	Function: void Book::setTitle(string title);
*	Pre: The new title.
*	Post: The title of the book will be updated.
*	Purpose: Change the title of a book.
*	Author: Fiona Wilson
*********************************************************/
void Book::setTitle(string title)
{
	mTitle = title;
}


/*********************************************************
*						Other							 *
*********************************************************/

/*	Function: istream& Book::load(istream& in);
*	Pre: The stream to read from.
*	Post: The state of the object will be read from the stream.
*	Purpose: Load a Book object from a stream.
*	Author: Fiona Wilson
*********************************************************/
istream& Book::load(istream& in)
{
	string line;

	getline(in, mCode);

	getline(in, line);
	mPrice = stod(line);

	getline(in, line);
	mStock = stoi(line);

	getline(in, mISBN);
	getline(in, mTitle);
	getline(in, mAuthor);

	return in;
}


/*	Function: ifstream& Book::load(ifstream& in);
*	Pre: The file stream to read from.
*	Post: The state of the object will be read from the stream.
*	Purpose: Load a Book object from a file stream.
*	Author: Fiona Wilson
*********************************************************/
ifstream& Book::load(ifstream& in)
{
	string line;

	getline(in, mCode);

	getline(in, line);
	mPrice = stod(line);

	getline(in, line);
	mStock = stoi(line);

	getline(in, mISBN);
	getline(in, mTitle);
	getline(in, mAuthor);

	return in;
}


/*	Function: ostream& Book::print(ostream& out);
*	Pre: The stream to print to.
*	Post: The state of the object will be printed to the stream.
*	Purpose: Print a Book object to a stream.
*	Author: Fiona Wilson
*********************************************************/
ostream& Book::print(ostream& out)
{
	out << fixed << setprecision(2);

	out
		<< mCode << endl
		<< mPrice << endl
		<< mStock << endl
		<< mISBN << endl
		<< mTitle << endl
		<< mAuthor << endl;

	return out;
}


/*	Function: ofstream& Book::print(ofstream& out);
*	Pre: The file stream to print to.
*	Post: The state of the object will be printed to the stream.
*	Purpose: Print a Book object to a file stream.
*	Author: Fiona Wilson
*********************************************************/
ofstream& Book::print(ofstream& out)
{
	out << fixed << setprecision(2);

	out
		<< mCode << endl
		<< mPrice << endl
		<< mStock << endl
		<< mISBN << endl
		<< mTitle << endl
		<< mAuthor << endl;

	return out;
}


/*********************************************************
*						Operators						 *
*********************************************************/

/*	Function: bool Book::operator ==(const Book& rhs);
*	Pre: The book to compare to.
*	Post: Returns true if the codes match, otherwise returns false.
*	Purpose: Compare the codes of two Book objects.
*	Author: Fiona Wilson
*********************************************************/
bool Book::operator ==(const Book& rhs)
{
	return mCode == rhs.mCode;
}


/*	Function: bool Book::operator ==(const string& rhs);
*	Pre: The string to use.
*	Post: Returns true if the string matches the code of
*	the Book object, otherwise returns false.
*	Purpose: Check if a string matches a Book objects code.
*	Author: Fiona Wilson
*********************************************************/
bool Book::operator ==(const string& rhs)
{
	return mCode == rhs;
}


/*	Function: bool Book::operator !=(const Book& rhs);
*	Pre: The Book object to use.
*	Post: Returns false if the codes match, otherwise returns true.
*	Purpose: Compare the codes of two Book objects.
*	Author: Fiona Wilson
*********************************************************/
bool Book::operator !=(const Book& rhs)
{
	return mCode != rhs.mCode;
}


/*	Function: bool Book::operator !=(const string& rhs);
*	Pre: The string to use.
*	Post: Returns false if the string matches the code of
*	the book object, otherwise returns true.
*	Purpose: Check if a string doesn't match a Book objects code.
*	Author: Fiona Wilson
*********************************************************/
bool Book::operator !=(const string& rhs)
{
	return mCode != rhs;
}


/*********************************************************
*						Friend Functions				 *
*********************************************************/

/*	Function: bool operator ==(const string& lhs, const Book& rhs);
*	Pre: The string and Book object to use.
*	Post: Returns true if the string matches the books code,
*	otherwise returns false.
*	Purpose: Compare a string with a Book objects code.
*	Author: Fiona Wilson
*********************************************************/
bool operator ==(const string& lhs, const Book& rhs)
{
	return lhs == rhs.mCode;
}


/*	Function: bool operator !=(const string& lhs, const Book& rhs);
*	Pre: The string and Book object to use.
*	Post: Returns false if the string matches the books code,
*	otherwise returns true.
*	Purpose: Compare a string with a Book objects code.
*	Author: Fiona Wilson
*********************************************************/
bool operator !=(const string& lhs, const Book& rhs)
{
	return lhs == rhs.mCode;
}
