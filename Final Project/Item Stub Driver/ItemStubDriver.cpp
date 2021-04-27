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

#include <iostream>
#include <fstream>
#include <string>

#include "item.h"
#include "snack.h"
#include "book.h"

using namespace std;

void testItem()
{
	ifstream din;
	ofstream dout;

	int count;

	Item test1;

	test1.setCode("123");
	test1.setPrice(1.99);
	test1.setStock(15);

	cout << fixed << setprecision(2);

	cout
		<< test1.getCode() << endl
		<< test1.getPrice() << endl
		<< test1.getStock() << endl << endl;

	Item test2("123", 1.99, 15);
	cout << test2 << endl;

	if (test1 == "123")
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	Item* arr;

	din.open("item_input.txt");

	din >> count;
	din.ignore(INT_MAX, '\n');
	din.clear();

	arr = new Item[count];

	for (int i = 0; i < count; i++)
	{
		din >> arr[i];
	}

	din.close();

	dout.open("item_output.txt");

	dout << fixed << setprecision(2);

	cout << count << endl;
	dout << count << endl;
	for (int i = 0; i < count; i++)
	{
		cout << arr[i];
		dout << arr[i];
	}

	dout.close();
	
	delete[] arr;
}


void testSnack()
{
	ifstream din;
	ofstream dout;

	int count;

	Snack test1;

	test1.setCode("123");
	test1.setPrice(2.99);
	test1.setStock(15);
	test1.setName("Chocolate Bar");

	cout << fixed << setprecision(2);

	cout
		<< test1.getCode() << endl
		<< test1.getPrice() << endl
		<< test1.getStock() << endl
		<< test1.getName() << endl << endl;

	Snack test2("123", 2.99, 15, "Chocolate Bar");
	cout << test2 << endl;

	if ("123" == test1)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	if (test1 == test2)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	Snack* arr;

	din.open("snack_input.txt");

	din >> count;
	din.ignore(INT_MAX, '\n');
	din.clear();

	arr = new Snack[count];

	for (int i = 0; i < count; i++)
	{
		din >> arr[i];
	}

	din.close();

	dout.open("snack_output.txt");

	dout << fixed << setprecision(2);

	cout << count << endl;
	dout << count << endl;

	for (int i = 0; i < count; i++)
	{
		cout << arr[i];
		dout << arr[i];
	}

	dout.close();

	delete[] arr;
}


void testBook()
{
	ifstream din;
	ofstream dout;

	int count;

	Book test1;

	test1.setCode("123");
	test1.setPrice(8.99);
	test1.setStock(5);
	test1.setISBN("978-1591169208");
	test1.setTitle("Fullmetal Alchemist Vol. 1");
	test1.setAuthor("Hiromu Arakawa");

	cout << fixed << setprecision(2);

	cout
		<< test1.getCode() << endl
		<< test1.getPrice() << endl
		<< test1.getStock() << endl
		<< test1.getISBN() << endl
		<< test1.getTitle() << endl
		<< test1.getAuthor() << endl << endl;

	Book test2("123", 0.0, 0, "", "", "");

	if (test1 == test2)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	if (test1 == "123")
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	if ("123" == test1)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	din.open("book_input.txt");

	din >> count;
	din.ignore(INT_MAX, '\n');
	din.clear();

	Book* arr = new Book[count];

	for (int i = 0; i < count; i++)
	{
		din >> arr[i];
	}

	din.close();

	dout.open("book_output.txt");

	dout << fixed << setprecision(2);
	
	cout << count << endl;
	dout << count << endl;

	for (int i = 0; i < count; i++)
	{
		cout << arr[i];
		dout << arr[i];
	}

	dout.close();

	delete[] arr;
}


int main()
{
	testItem();
	testSnack();
	testBook();

	return 0;
}
