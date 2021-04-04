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

#include "book.h"

/*********************************************************
*						Constructors					 *
*********************************************************/

/*	Function: Book::Book;
*	Pre: None
*	Post: All member variables will be set to default values.
*	Purpose: Default constructor.
*********************************************************/
Book::Book() : Item()
{
	mAuthor = "";
	mTitle = "";
}


/*	Function: Book::Book(string code, string title, string author, double price, int quantity);
*	Pre: Values to initialize with.
*	Post: All member variables will be set to the supplied values.
*	Purpose: Non-default constructor.
*********************************************************/
Book::Book(string code, string title, string author, double price, int quantity) : Item(code, price, quantity)
{
	mTitle = title;
	mAuthor = author;
}


/*********************************************************
*						Destructor						 *
*********************************************************/

/*	Function: Book::~Book();
*	Pre: None
*	Post: None
*	Purpsoe: Destructor
*********************************************************/
Book::~Book()
{

}


/*********************************************************
*						Accessors						 *
*********************************************************/

/*	Function: const string Book::getAuthor();
*	Pre: None
*	Post: Returns the author of the book.
*	Purpose: Get the author of a book;
*********************************************************/
string Book::getAuthor() const
{
	return mAuthor;
}


/*	Function: const string Book::getTitle();
*	Pre: None
*	Post: Returns the title of the book.
*	Purpose: Get the title of a book;
*********************************************************/
string Book::getTitle() const
{
	return mTitle;
}


/*********************************************************
*						Mutators						 *
*********************************************************/

/*	Function: void Book::setAuthor(string author);
*	Pre: The new author.
*	Post: The author of the book will be set to the supplied value.
*	Purpose: Change the author of a book.
*********************************************************/
void Book::setAuthor(string author)
{
	mAuthor = author;
}


/*	Function: void Book::setTitle(string title);
*	Pre: The new title.
*	Post: The title of the book will be set to the supplied value.
*	Purpose: Change the title of a book.
*********************************************************/
void Book::setTitle(string title)
{
	mTitle = title;
}


/*********************************************************
*						Friend Functions				 *
*********************************************************/

/*	Function: istream& operator >>(const istream& input, Book& book);
*	Pre: None
*	Post: Code, price, quantity, title and author are read from the stream.
*	Purpose: Read Book values from a stream.
*********************************************************/
istream& operator >>(istream& input, Book& book)
{
	string line;

	getline(input, book.mCode);

	getline(input, line);
	book.mPrice = stod(line);

	getline(input, line);
	book.mQuantity = stoi(line);

	getline(input, book.mTitle);

	getline(input, book.mAuthor);

	return input;
}


/*	Function: ostream& operator <<(const ostream& output, const Book& book);
*	Pre: None
*	Post: Code, price, quantity, title and author will be output to the stream.
*	Purpose: Output the state of the object to the stream.
*********************************************************/
ostream& operator <<(ostream& output, const Book& book)
{
	output << fixed << setprecision(2);

	output
		<< book.mCode << endl
		<< book.mPrice << endl
		<< book.mQuantity << endl
		<< book.mTitle << endl
		<< book.mAuthor << endl;

	return output;
}
