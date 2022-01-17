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

#include "linkedList.h"

using namespace std;

int main()
{
	LinkedList test;

	test.append(4.20);
	test.append(6.9);
	test.append(2.1);

	cout << test[0] << endl;
	cout << test[1] << endl;
	cout << test[2] << endl;

	try
	{
		cout << test[3] << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		cout << test[-1] << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
