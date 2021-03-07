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

#include "account.h"

using namespace std;

/*********************************************************
*						Constructors					 *
*********************************************************/

/*	Function: Account::Account();
*	Pre: None.
*	Post: All doubles will be initialized to 0.0 and all strings
*	will be initialized to "".
*	Purpose: Initialize the Account object with default empty values.
*********************************************************/
Account::Account()
{
	_ssn = "";
	_name = "";

	_checking = 0.0;
	_saving = 0.0;
	_total = 0.0;
}
