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


/*	Function: Account::Account(string ssn, string name, double checkingAmt, double savingAmt);
*	Pre: The values to initialize the Account object with.
*	Post: The Account object will be initialized with the provided values.
*	Purpose: Non-default constructor.
*********************************************************/
Account::Account(string ssn, string name, double checkingAmt, double savingAmt)
{
	_ssn = ssn;
	_name = name;

	_checking = checkingAmt;
	_saving = savingAmt;
	_total = checkingAmt + savingAmt;
}


/*********************************************************
*						Destructor						 *
*********************************************************/

/*	Function: Account::~Account();
*	Pre: None.
*	Post: Object is deleted.
*	Purpose: Destructor.
*********************************************************/
Account::~Account()
{

}


/*********************************************************
*						Accessors						 *
*********************************************************/


/*	Function: double Account::getChecking();
*	Pre: None.
*	Post: The checking balance will be returned.
*	Purpose: Return the checking balance of the account.
*********************************************************/
double Account::getChecking()
{
	return _checking;
}


/*	Function: string Account::getName();
*	Pre: None.
*	Post: The name of the acount holder will be returned.
*	Purpose: Return the name of the account holder.
*********************************************************/
string Account::getName()
{
	return _name;
}


/*	Function: double Account::getSaving();
*	Pre: None.
*	Post: The saving balance will be returned.
*	Purpose: Return the saving balance of the account.
*********************************************************/
double Account::getSaving()
{
	return _saving;
}


/*	Function: string Account::getSSN();
*	Pre: None.
*	Post: Returns the SSN of the account holder.
*	Purpose: Return the SSN of the account holder.
*********************************************************/
string Account::getSSN()
{
	return _ssn;
}


/*	Function: double Account::getTotal();
*	Pre: None.
*	Post: Returns the total balance of the account.
*	Purpose: Return the total balance of the account.
*********************************************************/
double Account::getTotal()
{
	return _checking + _saving;
}
