// Author: Fiona Wilson
// Class: CSI-240-03
// Assignment: PA3 - Part 2
// Date Assigned: March 22 2021
// Due Date: March 30 2021
// Description: Create an account class and make a stub driver to demonstrate it.
// Certification of Authenticity:
// I certify that this is entirely my own work, except where I have given fully documented references to the work of others. I understand the definition and
// consequences of plagiarism and acknowledge that the assessor of this assignment
// may, for the purpose of assessing this assignment:
// - Reproduce this assignment and provide a copy to another member of
// academic staff; and/or
// - Communicate a copy of this assignment to a plagiarism checking service
// (which may then retain a copy of this assignment on its database for
// the purpose of future plagiarism checking)

#include <iostream>

#include "customer.h"

using namespace std;

int main()
{
	Customer test;

	// Expected value: false
	cout << "Test 1: ";
	if (test.loadData())
	{
		cout << "FAILED\n";
	}
	else
	{
		cout << "PASSED\n";
	}

	test.setFilename("customer_input.txt");

	// Expected value: "customer_input.txt"
	cout << "Test 2: ";
	if (test.getFilename() == "customer_input.txt")
	{
		cout << "PASSED\n";
	}
	else
	{
		cout << "FAILED\n";
	}

	// Expected value: true
	cout << "Test 3: ";
	if (test.loadData())
	{
		cout << "PASSED\n";
	}
	else
	{
		cout << "FAILED\n";
	}

	// Expected value: 2
	cout << "Test 3: ";
	if (test.getCount() == 2)
	{
		cout << "PASSED\n";
	}
	else
	{
		cout << "FAILED\n";
	}

	cout << endl;

	cout << test.getCustomer("1234") << endl << endl;

	test.setFilename("customer_output.txt");
	test.storeData();

	return 0;
}
