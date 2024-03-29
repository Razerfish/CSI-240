// Author: 
// Class: CSI-240-03
// Assignment: PA2
// Date Assigned: February 22 2021
// Due Date: March 1 2021
// Description: Simulate a vending machine.
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

#include "vendingMachine.h"
#include "header.h"

using namespace std;
int main()
{
	VendingMachine machine;

	string password;

	int selection;

	double payment;

	// Does this count as direct output?
	cout << fixed << setprecision(2);

	// Check if this is the first run.
	if (machine.getItemCount() == 0)
	{
		firstTimeSetup(machine);
	}

	// Run the vend loop and return the result as our exit code.
	return vendLoop(machine);
}
