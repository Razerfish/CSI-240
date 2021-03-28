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
#include <fstream>
#include <sstream>

#include "account.h"

using namespace std;

int main()
{
	const string TEST_STRING = "Account Number:               8295\nSSN:                          123-45-6789\nName:                         Jane Doe\nAddress:                      17 Real Road\nPhone Number:                 555-555-5559\nSaving Amount:                $250.00\nChecking Amount:              $100.00\n";

	Account acc1("1234", "123-45-6789", "Edward Elric", "15 Real Road", "555-555-5555", 100.0, 250.0);
	Account acc2("5678", "987-65-4321", "Alphonse Elric", "16 Real Road", "555-555-5556", 100.0, 250.0);

	// Expected value: false
	cout << "Test 1: ";
	if (acc1 == acc2)
	{
		cout << "FAILED\n";
	}
	else
	{
		cout << "PASSED\n";
	}

	// Expected value: true
	cout << "Test 2: ";
	if (acc1 != acc2)
	{
		cout << "PASSED\n";
	}
	else
	{
		cout << "FAILED\n";
	}

	Account acc3;
	Account acc4;

	istringstream input(TEST_STRING);
	ifstream fin;

	input >> acc3;

	fin.open("input.txt");
	if (fin.good())
	{
		fin >> acc4;
	}
	fin.close();

	// Expected value: false
	cout << "Test 3: ";
	if (acc3 > acc4)
	{
		cout << "FAILED\n";
	}
	else
	{
		cout << "PASSED\n";
	}

	// Expected value: true
	cout << "Test 4: ";
	if (acc3 < acc4)
	{
		cout << "PASSED\n";
	}
	else
	{
		cout << "FAILED\n";
	}

	cout << endl << endl;

	cout << acc3 << endl;

	ofstream fout;

	fout.open("output.txt", ios::out | ios::trunc);
	if (fout.good())
	{
		fout << acc3;
	}
	fout.close();
}
