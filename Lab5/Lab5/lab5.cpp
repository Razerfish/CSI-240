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

#include <iostream>
#include <sstream>
#include <string>

#include "item.h"
#include "book.h"
#include "comic.h"

using namespace std;

void itemTest()
{
	istringstream itemTestString("789\n2.99\n14");

	cout << fixed << setprecision(2);

	Item test1;
	test1.setCode("123");
	test1.setPrice(4.99);
	test1.setQuantity(10);

	cout
		<< test1.getCode() << endl
		<< test1.getPrice() << endl
		<< test1.getQuantity() << endl << endl;


	Item test2("456", 9.99, 50);

	cout
		<< test2.getCode() << endl
		<< test2.getPrice() << endl
		<< test2.getQuantity() << endl << endl;


	Item test3;
	itemTestString >> test3;

	cout
		<< test3.getCode() << endl
		<< test3.getPrice() << endl
		<< test3.getQuantity() << endl << endl;
}


void bookTest()
{
	istringstream bookTestString("789\n12.99\n5\nStory 3\nJohn Smith");

	cout << fixed << setprecision(2);

	Book test1;
	test1.setCode("123");
	test1.setPrice(4.99);
	test1.setQuantity(43);
	test1.setTitle("Real Book");
	test1.setAuthor("A. Mann");

	cout
		<< test1.getCode() << endl
		<< test1.getPrice() << endl
		<< test1.getQuantity() << endl
		<< test1.getTitle() << endl
		<< test1.getAuthor() << endl << endl;


	Book test2("456", "Title", "Author", 1.99, 100);

	cout
		<< test2.getCode() << endl
		<< test2.getPrice() << endl
		<< test2.getQuantity() << endl
		<< test2.getTitle() << endl
		<< test2.getAuthor() << endl << endl;


	Book test3;
	bookTestString >> test3;

	cout
		<< test3.getCode() << endl
		<< test3.getPrice() << endl
		<< test3.getQuantity() << endl
		<< test3.getTitle() << endl
		<< test3.getAuthor() << endl << endl;
}


void comicTest()
{
	istringstream comicTestString("789\n4.99\n34\nComic3\nAuthor3\n3\n3");

	cout << fixed << setprecision(2);

	Comic test1;
	test1.setCode("123");
	test1.setPrice(0.99);
	test1.setQuantity(0);
	test1.setTitle("Comic1");
	test1.setAuthor("Author1");
	test1.setSeries(1);
	test1.setVolume(1);

	cout
		<< test1.getCode() << endl
		<< test1.getPrice() << endl
		<< test1.getQuantity() << endl
		<< test1.getTitle() << endl
		<< test1.getAuthor() << endl
		<< test1.getSeries() << endl
		<< test1.getVolume() << endl << endl;


	Comic test2("456", "Comic2", "Author2", 1.99, 4, 2, 2);

	cout
		<< test2.getCode() << endl
		<< test2.getPrice() << endl
		<< test2.getQuantity() << endl
		<< test2.getTitle() << endl
		<< test2.getAuthor() << endl
		<< test2.getSeries() << endl
		<< test2.getVolume() << endl << endl;


	Comic test3;
	comicTestString >> test3;

	cout
		<< test3.getCode() << endl
		<< test3.getPrice() << endl
		<< test3.getQuantity() << endl
		<< test3.getTitle() << endl
		<< test3.getAuthor() << endl
		<< test3.getSeries() << endl
		<< test3.getVolume() << endl << endl;
}


int main()
{
	itemTest();
	bookTest();
	comicTest();

	return 0;
}
