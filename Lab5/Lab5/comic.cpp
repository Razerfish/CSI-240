/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: Lab 5
Date Assigned: March 29 2021
Due Date: April 1 2021
Description: Create an item class, a comic class that inherits from item and a comic class that inherits from comic. Write a stub driver to test them all.
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

#include "comic.h"

/*********************************************************
*						Constructors					 *
*********************************************************/

/*	Function: Comic::Comic;
*	Pre: None
*	Post: All member variables will be set to default values.
*	Purpose: Default constructor.
*********************************************************/
Comic::Comic() : Book()
{
	mSeries = 0;
	mVolume = 0;
}


/*	Function: Comic::Comic(string code, string title, string author, double price, int quantity);
*	Pre: Values to initialize with.
*	Post: All member variables will be set to the supplied values.
*	Purpose: Non-default constructor.
*********************************************************/
Comic::Comic(string code, string title, string author, double price, int quantity, int volume, int series) : Book(code, title, author, price, quantity)
{
	mSeries = series;
	mVolume = volume;
}


/*********************************************************
*						Destructor						 *
*********************************************************/

/*	Function: Comic::~Comic();
*	Pre: None
*	Post: None
*	Purpsoe: Destructor
*********************************************************/
Comic::~Comic()
{

}


/*********************************************************
*						Accessors						 *
*********************************************************/

/*	Function: int Comic::getSeries();
*	Pre: None
*	Post: Returns the series of the comic.
*	Purpose: Get the series of a comic.
*********************************************************/
int Comic::getSeries()
{
	return mSeries;
}


/*	Function: int Comic::getVolume();
*	Pre: None
*	Post: Returns the volume of the comic.
*	Purpose: Get the volume of a comic.
*********************************************************/
int Comic::getVolume()
{
	return mVolume;
}


/*********************************************************
*						Mutators						 *
*********************************************************/

/*	Function: void Comic::setSeries(int series);
*	Pre: The new series.
*	Post: The series of the comic will be set to the supplied value.
*	Purpose: Change the series of a comic.
*********************************************************/
void Comic::setSeries(int series)
{
	mSeries = series;
}


/*	Function: void Comic::setVolume(int volume);
*	Pre: The new volume.
*	Post: The volume of a comic will be set to the supplied value.
*	Purpose: Change the volume of a comic.
*********************************************************/
void Comic::setVolume(int volume)
{
	mVolume = volume;
}


/*********************************************************
*						Friend Functions				 *
*********************************************************/

/*	Function: istream& operator >>(const istream& input, Comic& comic);
*	Pre: None
*	Post: Code, price, quantity, title and author are read from the stream.
*	Purpose: Read Comic values from a stream.
*********************************************************/
istream& operator >>(istream& input, Comic& comic)
{
	string line;

	getline(input, comic.mCode);

	getline(input, line);
	comic.mPrice = stod(line);

	getline(input, line);
	comic.mQuantity = stoi(line);

	getline(input, line);
	comic.setTitle(line);

	getline(input, line);
	comic.setAuthor(line);

	getline(input, line);
	comic.mSeries = stoi(line);

	getline(input, line);
	comic.mVolume = stoi(line);

	return input;
}


/*	Function: ostream& operator <<(const ostream& output, const Comic& comic);
*	Pre: None
*	Post: Code, price, quantity, title, author, series and volume will be output to the stream.
*	Purpose: Output the state of the object to the stream.
*********************************************************/
ostream& operator <<(ostream& output, const Comic& comic)
{
	output << fixed << setprecision(2);

	output
		<< comic.mCode << endl
		<< comic.mPrice << endl
		<< comic.mQuantity << endl
		<< comic.getTitle() << endl
		<< comic.getAuthor() << endl
		<< comic.mSeries << endl
		<< comic.mVolume << endl;

	return output;
}

