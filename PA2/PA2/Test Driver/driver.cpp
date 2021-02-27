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
#include <string>

#include "vendingMachine.h"
#include "header.h"

using namespace std;
int main()
{
	VendingMachine test;

	cout
		<< test.getBalance() << endl
		<< test.getItemCount() << endl
		<< test.getName() << endl
		<< test.getPassword() << endl << endl;

	Item x;
	for (int i = 0; i < 4; i++)
	{
		x = test.getItem(i);
		cout << x.name << " " << x.quantity << " " << x.price << endl;
	}

	test.setBalance(42.00);
	test.setItem(4, { "egg", 2, 3.00 });
	test.setItemCount(5);
	test.setName("Barry");
	test.setPassword("beans");

	test.showStockerMenu();

	cout << endl << endl;

	test.showUserMenu();

	return 0;
}
