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


/*********************************************************
*						Mutators						 *
*********************************************************/

/*	Function: void Account::setChecking(double checkingAmt);
*	Pre: The new value to set the checking balance to.
*	Post: The checking balance will be set to the provided
*	value and the total balance will be updated to reflect that.
*	Purpose: Update the checking balance.
*********************************************************/
void Account::setChecking(double checkingAmt)
{
	_checking = checkingAmt;
	_total = checkingAmt + _saving;
}


/*	Function: void Account::setName(string name);
*	Pre: The new value to set the name of the account holder to.
*	Post: The account holder's name will be set to the provided value.
*	Purpose: Update the name of the account holder.
*********************************************************/
void Account::setName(string name)
{
	_name = name;
}


/*	Function: void Account::setSaving(double savingAmt);
*	Pre: The new value to set the saving balance to.
*	Post: The saving balance will be set to the provided
*	value and the total balance will be updated to reflect that.
*	Purpose: Update the saving balance.
*********************************************************/
void Account::setSaving(double savingAmt)
{
	_saving = savingAmt;
	_total = savingAmt + _checking;
}


/*	Function: void Account::setSSN(string ssn);
*	Pre: The new value to set the ssn of the account holder to.
*	Post: The account holder's ssn will be set to the provided value.
*	Purpose: Update the ssn of the account holder.
*********************************************************/
void Account::setSSN(string ssn)
{
	_ssn = ssn;
}


/*********************************************************
*						Operators						 *
*********************************************************/


/*	Function: bool Account::operator ==(const Account& rhs);
*	Pre: None.
*	Post: Returns whether or not the SSN's both accounts match.
*	Purpose: Check if the SSN's of two accounts match.
*********************************************************/
bool Account::operator ==(const Account& rhs)
{
	return _ssn == rhs._ssn;
}


/*	Function: bool Account::operator ==(const string& rhs);
*	Pre: None.
*	Post: Returns whether or not the contents of the string match
*	the account holders ssn.
*	Purpose: Check if a string matches the account holders ssn.
*********************************************************/
bool Account::operator ==(const string& rhs)
{
	return _ssn == rhs;
}


/*	Function: bool Account::operator !=(const Account& rhs);
*	Pre: None.
*	Post: Returns whether or not the SSN's both accounts don't match.
*	Purpose: Check if the SSN's of two accounts don't match.
*********************************************************/
bool Account::operator !=(const Account& rhs)
{
	return _ssn != rhs._ssn;
}


/*	Function: bool Account::operator !=(const string& rhs);
*	Pre: None.
*	Post: Returns whether or not the contents of the string don't 
*	match the account holders ssn.
*	Purpose: Check if a string doesn't match the account holders ssn.
*********************************************************/
bool Account::operator !=(const string& rhs)
{
	return _ssn != rhs;
}


/*	Function: bool Account::operator >(const Account& rhs);
*	Pre: None.
*	Post: Returns whether or not the total balance of this account
*	is larger than the total balance of another account.
*	Purpose: Compare the total balances of two account and return whether
*	or not we are larger.
*********************************************************/
bool Account::operator >(const Account& rhs)
{
	return _total > rhs._total;
}


/*	Function: bool Account::operator <(const Account& rhs);
*	Pre: None.
*	Post: Returns whether or not the total balance is smaller
*	than the total balance of another account.
*	Purpose: Compare the total balances of two accounts and return whether
*	or not we are smaller.
*********************************************************/
bool Account::operator <(const Account& rhs)
{
	return _total < rhs._total;
}


/*********************************************************
*						Friend Functions				 *
*********************************************************/

/*	Function: ostream& operator <<(ostream& output, const Account& obj);
*	Pre: None.
*	Post: SSN, name, checking balance and saving balance will be outputted
*	to the stream.
*	Purpose: Output the current account state to the stream.
*********************************************************/
ostream& operator <<(ostream& output, const Account& obj)
{
	// Set precision
	output << fixed << setprecision(2);

	output
		<< setw(30) << left << "SSN"
		<< obj._ssn << endl;

	output
		<< setw(30) << left << "Name"
		<< obj._name << endl;

	output
		<< setw(30) << left << "Saving Checking"
		<< obj._saving << " " << obj._checking << endl;

	return output;
}


/*	Function: ofstream& operator <<(ofstream& output, const Account& obj);
*	Pre: None.
*	Post: SSN, name, checking balance and saving balance will be outputted
*	to the file.
*	Purpose: Output the current account state to a file stream.
*********************************************************/
ofstream& operator <<(ofstream& output, const Account& obj)
{
	// Set precision
	output << fixed << setprecision(2);

	output
		<< setw(30) << left << "SSN"
		<< obj._ssn << endl;

	output
		<< setw(30) << left << "Name"
		<< obj._name << endl;

	output
		<< setw(30) << left << "Saving Checking"
		<< obj._saving << " " << obj._checking << endl;

	return output;
}


/*	Function: istream& operator >>(istream& input, Account& obj);
*	Pre: None.
*	Post: The values of the account object will be set using the
*	contents of the stream.
*	Purpose: Populate an account object from a stream.
*********************************************************/
istream& operator >>(istream& input, Account& obj)
{
	string
		tmp,
		firstName,
		lastName;

	// Always discard the value label.
	input >> tmp;

	// Get SSN.
	input >> obj._ssn;

	// Advance to next line.
	input.ignore(INT_MAX, '\n');

	input >> tmp;
	input >> firstName;
	input >> lastName;
	obj._name = firstName + " " + lastName;

	input.ignore(INT_MAX, '\n');

	input >> tmp;
	input >> tmp;
	input >> obj._saving;
	input >> obj._checking;
	obj._total = obj._saving + obj._checking;

	input.ignore(INT_MAX, '\n');

	return input;
}


/*	Function: ifstream& operator >>(ifstream& input, Account& obj);
*	Pre: None.
*	Post: The values of the account object will be set using the
*	contents of the file stream.
*	Purpose: Populate an account object from a file stream.
*********************************************************/
ifstream& operator >>(ifstream& input, Account& obj)
{
	string
		tmp,
		firstName,
		lastName;

	// Always discard the value label.
	input >> tmp;

	// Get SSN.
	input >> obj._ssn;

	// Advance to next line.
	input.ignore(INT_MAX, '\n');

	input >> tmp;
	input >> firstName;
	input >> lastName;
	obj._name = firstName + " " + lastName;

	input.ignore(INT_MAX, '\n');

	input >> tmp;
	input >> tmp;
	input >> obj._saving;
	input >> obj._checking;
	obj._total = obj._saving + obj._checking;

	input.ignore(INT_MAX, '\n');

	return input;
}


/*	Function: bool operator ==(const string& lhs, const Account& rhs);
*	Pre: None.
*	Post: Return whether or not the string is equal to the account
*	objects SSN.
*	Purpose: Check if the objects SSN matches a string and return true
*	if it does.
*********************************************************/
bool operator ==(const string& lhs, const Account& rhs)
{
	return lhs == rhs._ssn;
}


/*	Function: bool operator !=(const string& lhs, const Account& rhs);
*	Pre: None.
*	Post: Return whether or not the string is equal to the account
*	objects SSN.
*	Purpose: Check if the objects SSN matches a string and return false
*	if it does.
*********************************************************/
bool operator !=(const string& lhs, const Account& rhs)
{
	return lhs != rhs._ssn;
}


/*	Function: string boolToString(bool input);
*	Pre: A bool to convert to a string.
*	Post: If the provided bool is false the word "false"
*	will be returned, if the proved bool is true the word
*	"true" will be returned.
*	Purpose: Make stub output more human readible without
*	including a ton of if statements.
*********************************************************/
string boolToString(bool input)
{
	if (input)
	{
		return "true";
	}
	else
	{
		return "false";
	}
}
