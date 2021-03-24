/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: PA3 - Part 1
Date Assigned: March 17 2021
Due Date: March 25 2021
Description: Create a class and a struct and write stub drivers for both of them.
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
#include <string>

#include "teller.h"

using namespace std;

int main()
{
	// Probably went a bit overboard with this...

	const int TEST_COUNT = 12;

	string testIDs[TEST_COUNT] =
	{
		"e-elric",
		"a-elric",
		"w-rockbell",
		"r-hawkeye",
		"r-mustang",
		"a-armstrong",
		"o-armstrong",
		"v-hohenheim",
		"i-curtis",
		"r-thomas",
		"k-bradley",
		"e-elric"
	};

	string testPasswords[TEST_COUNT] =
	{
		"october3",
		"cats",
		"gearhead",
		"mustang",
		"hawkeye",
		"generations",
		"briggs",
		"trisha",
		"sig",
		"reole",
		"father",
		"gearhead"
	};

	bool testExpected[TEST_COUNT] =
	{
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		false,
		false
	};

	Teller test;

	cout << "Attempting to load data from fake.txt...";
	if (test.loadData("fake.txt"))
	{
		cout << " Success! (That's not supposed to happen)";
	}
	else
	{
		cout << " Failed (That's expected)";
	}

	cout << "\n\nAttempting to load data from input.txt...";
	if (test.loadData("input.txt"))
	{
		cout << " Success!";
	}
	else
	{
		cout << " Failed";
	}

	cout << "\n\nTesting tellers...\n\n";

	bool result;
	for (int i = 0; i < TEST_COUNT; i++)
	{
		cout << "Testing ID: " << testIDs[i] << " Password: " << testPasswords[i] << "...\n";

		result = test.verifyTeller(testIDs[i], testPasswords[i]);

		cout << "Expected ";

		if (testExpected[i])
		{
			cout << "true";
		}
		else
		{
			cout << "false";
		}

		cout << ", got ";

		if (result)
		{
			cout << "true";
		}
		else
		{
			cout << "false";
		}

		if (result == testExpected[i])
		{
			cout << " PASSED\n\n";
		}
		else
		{
			cout << " FAILED\n\n";
		}
	}
}
