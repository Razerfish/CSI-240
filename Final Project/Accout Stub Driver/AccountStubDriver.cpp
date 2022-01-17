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

#include "account.h"

using namespace std;

const string INPUT_FILE = "accounts.txt";
const string OUTPUT_FILE = "out.txt";

int main()
{
	ifstream din;
	ofstream dout;

	int count;

	Account* database;

	din.open(INPUT_FILE.c_str());
	din >> count;

	database = new Account[count];

	din.ignore(INT_MAX, '\n');
	din.clear();

	for (int i = 0; i < count; i++)
	{
		din >> database[i];
	}

	din.close();

	dout.open(OUTPUT_FILE.c_str());
	dout << count << endl;

	for (int i = 0; i < count; i++)
	{
		dout << database[i];
	}
	dout.close();

	delete[] database;

	Account test;

	test.setName("Name");
	test.setPassword("password");
	test.setUsername("username");

	cout
		<< test.getName() << endl
		<< test.getUsername() << endl
		<< test.isManager() << endl;

	if (test.validateLogin("username", "password"))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	Account test2("u", "p", "n");

	cout
		<< test2.getName() << endl
		<< test2.getUsername() << endl
		<< test2.isManager() << endl;

	if (test2.validateLogin("username", "password"))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	return 0;
}
