// Author: Fiona Wilson
// Class: CSI-240-03
// Assignment: Lab 3
// Date Assigned: March 4 2021
// Due Date: March 8 2021
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
	// Using default constructor.
	Account acc1;

	// Using non-default constructor.
	Account acc2("123-45-6789", "John Smith", 100.0, 50.0);

	// Comparison operators.
	cout << "Comparison operators: \n";

	cout << "acc1 == acc2: " << boolToString(acc1 == acc2) << endl;
	cout << "acc2 == acc2: " << boolToString(acc2 == acc2) << endl << endl;

	cout << "\"000-00-0000\" == acc2: " << boolToString("000-00-0000" == acc2) << endl;
	cout << "\"123-45-6789\" == acc2: " << boolToString("123-45-6789" == acc2) << endl << endl;

	cout << "\"000-00-0000\" != acc2: " << boolToString("000-00-0000" != acc2) << endl;
	cout << "\"123-45-6789\" != acc2: " << boolToString("123-45-6789" != acc2) << endl << endl;

	cout << "acc1 != acc2: " << boolToString(acc1 != acc2) << endl;
	cout << "acc2 != acc2: " << boolToString(acc2 != acc2) << endl << endl;

	cout << "acc1 < acc2: " << boolToString(acc1 < acc2) << endl;
	cout << "acc1 > acc2: " << boolToString(acc1 > acc2) << endl << endl;

	// Input.
	// Stream input.
	istringstream ss(TEST_STRING);

	ss >> acc1;

	// File input
	ifstream fin;
	fin.open("input.txt");

	fin >> acc1;

	fin.close();

	// Output.
	// Stream output.
	cout << acc2;

	// File output.
	ofstream fout;
	fout.open("output.txt", ios::out | ios::trunc);

	fout << acc2;

	fout.close();

	cout << "\nCheck output.txt for file output!\n\n";

	// Mutators
	acc1.setName("Megaera Erinyes");
	acc1.setSSN("555-55-5555");
	acc1.setChecking(257.48);
	acc1.setSaving(2486.38);

	// Accessors
	cout << "acc1.getName() -> " << acc1.getName() << endl;
	cout << "acc1.getSSN() -> " << acc1.getSSN() << endl;
	cout << "acc1.getChecking() -> " << acc1.getChecking() << endl;
	cout << "acc1.getSaving() -> " << acc1.getSaving() << endl;
	cout << "acc1.getTotal() -> " << acc1.getTotal() << endl;

	return 0;
}
