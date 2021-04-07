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
	mAccountNumber = "";

	mSSN = "";
	mName = "";
	mAddress = "";
	mPhoneNumber = "";

	mChecking = 0.0;
	mSaving = 0.0;
	mTotal = 0.0;
}


/*	Function: Account::Account(string accountNumber, string ssn, string name, string address, string phoneNumber double checking, double saving);
*	Pre: The values to initialize the Account object with.
*	Post: The Account object will be initialized with the provided values.
*	Purpose: Non-default constructor.
*********************************************************/
Account::Account(string accountNumber, string ssn, string name, string address, string phoneNumber, double checking, double saving)
{
	mAccountNumber = accountNumber;

	mSSN = ssn;
	mName = name;
	mAddress = address;
	mPhoneNumber = phoneNumber;

	mChecking = checking;
	mSaving = saving;
	mTotal = checking + saving;
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

/*	Function: string Account::getAccountNumber();
*	Pre: None
*	Post: The account number will be returned.
*	Purpose: Return the account number of the account.
*********************************************************/
string Account::getAccountNumber()
{
	return mAccountNumber;
}


/*	Function: string Account::getAddress();
*	Pre: None
*	Post: The address will be returned.
*	Purpose: Return the address of the account holder.
*********************************************************/
string Account::getAddress()
{
	return mAddress;
}


/*	Function: double Account::getChecking();
*	Pre: None.
*	Post: The checking balance will be returned.
*	Purpose: Return the checking balance of the account.
*********************************************************/
double Account::getChecking()
{
	return mChecking;
}


/*	Function: string Account::getName();
*	Pre: None.
*	Post: The name of the acount holder will be returned.
*	Purpose: Return the name of the account holder.
*********************************************************/
string Account::getName()
{
	return mName;
}


/*	Function: string Account::getPhoneNumber();
*	Pre: None
*	Post: The phone number of the account holder will be returned.
*	Purpose: Get the phone number of the account holder.
*********************************************************/
string Account::getPhoneNumber()
{
	return mPhoneNumber;
}


/*	Function: double Account::getSaving();
*	Pre: None.
*	Post: The saving balance will be returned.
*	Purpose: Return the saving balance of the account.
*********************************************************/
double Account::getSaving()
{
	return mSaving;
}


/*	Function: string Account::getSSN();
*	Pre: None.
*	Post: Returns the SSN of the account holder.
*	Purpose: Return the SSN of the account holder.
*********************************************************/
string Account::getSSN()
{
	return mSSN;
}


/*	Function: double Account::getTotal();
*	Pre: None.
*	Post: Returns the total balance of the account.
*	Purpose: Return the total balance of the account.
*********************************************************/
double Account::getTotal()
{
	return mChecking + mSaving;
}


/*********************************************************
*						Mutators						 *
*********************************************************/

/*	Function: void Account::setAccountNumber();
*	Pre: The new value to set the account number to.
*	Post: The account number will be set to the new value.
*	Purpose: Modify an accounts account number.
*********************************************************/
void Account::setAccountNumber(string accountNumber)
{
	mAccountNumber = accountNumber;
}


/*	Function: void Account::setAddress(string address);
*	Pre: The new value to set the address to.
*	Post: The address of the account holder will be set to the new value.
*	Purpose: Modify the address of the account holder.
*********************************************************/
void Account::setAddress(string address)
{
	mAddress = address;
}


/*	Function: void Account::setChecking(double checkingAmt);
*	Pre: The new value to set the checking balance to.
*	Post: The checking balance will be set to the provided
*	value and the total balance will be updated to reflect that.
*	Purpose: Update the checking balance.
*********************************************************/
void Account::setChecking(double checking)
{
	mChecking = checking;
	mTotal = checking + mSaving;
}


/*	Function: void Account::setName(string name);
*	Pre: The new value to set the name of the account holder to.
*	Post: The account holder's name will be set to the provided value.
*	Purpose: Update the name of the account holder.
*********************************************************/
void Account::setName(string name)
{
	mName = name;
}


/*	Function: void Account::setPhoneNumber();
*	Pre: The new value to set the phone number of the account holder to.
*	Post: The account holders phone number will be updated to the new value.
*	Purpose: Modify the account holders phone number.
*********************************************************/
void Account::setPhoneNumber(string phoneNumber)
{
	mPhoneNumber = phoneNumber;
}


/*	Function: void Account::setSaving(double savingAmt);
*	Pre: The new value to set the saving balance to.
*	Post: The saving balance will be set to the provided
*	value and the total balance will be updated to reflect that.
*	Purpose: Update the saving balance.
*********************************************************/
void Account::setSaving(double saving)
{
	mSaving = saving;
	mTotal = saving + mChecking;
}


/*	Function: void Account::setSSN(string ssn);
*	Pre: The new value to set the ssn of the account holder to.
*	Post: The account holder's ssn will be set to the provided value.
*	Purpose: Update the ssn of the account holder.
*********************************************************/
void Account::setSSN(string ssn)
{
	mSSN = ssn;
}


/*********************************************************
*						Operators						 *
*********************************************************/


/*	Function: bool Account::operator ==(const Account& rhs);
*	Pre: None.
*	Post: Returns whether or not the account number for both accounts match.
*	Purpose: Check if the account numbers of two accounts match.
*********************************************************/
bool Account::operator ==(const Account& rhs)
{
	return mAccountNumber == rhs.mAccountNumber;
}


/*	Function: bool Account::operator ==(const string& rhs);
*	Pre: None.
*	Post: Returns whether or not the contents of the string match
*	the account number.
*	Purpose: Check if a string matches the account number.
*********************************************************/
bool Account::operator ==(const string& rhs)
{
	return mAccountNumber == rhs;
}


/*	Function: bool Account::operator !=(const Account& rhs);
*	Pre: None.
*	Post: Returns whether or not the account number for both accounts don't match.
*	Purpose: Check if the account numbers of two accounts don't match.
*********************************************************/
bool Account::operator !=(const Account& rhs)
{
	return mAccountNumber != rhs.mAccountNumber;
}


/*	Function: bool Account::operator !=(const string& rhs);
*	Pre: None.
*	Post: Returns whether or not the contents of the string don't 
*	match the account number.
*	Purpose: Check if a string doesn't match the account number.
*********************************************************/
bool Account::operator !=(const string& rhs)
{
	return mAccountNumber != rhs;
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
	return mTotal > rhs.mTotal;
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
	return mTotal < rhs.mTotal;
}


/*********************************************************
*						Friend Functions				 *
*********************************************************/

/*	Function: ostream& operator <<(ostream& output, const Account& obj);
*	Pre: None.
*	Post: Account number, SSN, name, address, phone number,
*	checking balance and saving balance will be outputted to the stream.
*	Purpose: Output the current account state to the stream.
*********************************************************/
ostream& operator <<(ostream& output, const Account& obj)
{
	// Set precision
	output << fixed << setprecision(2);

	output
		<< setw(LABEL_WIDTH) << left << "Account Number:"
		<< obj.mAccountNumber << endl;

	output
		<< setw(LABEL_WIDTH) << left << "SSN:"
		<< obj.mSSN << endl;

	output
		<< setw(LABEL_WIDTH) << left << "Name:"
		<< obj.mName << endl;

	output
		<< setw(LABEL_WIDTH) << left << "Address:"
		<< obj.mAddress << endl;

	output
		<< setw(LABEL_WIDTH) << left << "Phone Number:"
		<< obj.mPhoneNumber << endl;

	output
		<< setw(LABEL_WIDTH) << left << "Saving Amount:"
		<< '$' << obj.mSaving << endl;

	output << setw(LABEL_WIDTH) << left << "Checking Amount:"
		<< '$' << obj.mChecking << endl;

	return output;
}


/*	Function: ofstream& operator <<(ofstream& output, const Account& obj);
*	Pre: None.
*	Post: Account number, SSN, name, addres and phone number will be outputted
*	to the specified file. Savings amount will be saved to {account number}.sav
*	and checking amount will be saved to {account number}.chk
*	Purpose: Output the current account state to a file stream.
*********************************************************/
ofstream& operator <<(ofstream& output, const Account& obj)
{
	ofstream sout; // Savings file
	ofstream chout; // Checking file

	// Save non-balance data.
	output
		<< setw(LABEL_WIDTH) << left << "Account Number"
		<< obj.mAccountNumber << endl;

	output
		<< setw(LABEL_WIDTH) << left << "SSN"
		<< obj.mSSN << endl;

	output
		<< setw(LABEL_WIDTH) << left << "Name"
		<< obj.mName << endl;

	output
		<< setw(LABEL_WIDTH) << left << "Address"
		<< obj.mAddress << endl;

	output
		<< setw(LABEL_WIDTH) << left << "Phone Number"
		<< obj.mPhoneNumber << endl;

	// Write savings balance
	sout.open((obj.mAccountNumber + ".sav").c_str(), ios::out | ios::trunc);

	if (sout.good())
	{
		sout << fixed << setprecision(2);
		sout << obj.mSaving << endl;
	}
	sout.close();

	// Write checking balance
	chout.open((obj.mAccountNumber + ".chk").c_str(), ios::out | ios::trunc);

	if (chout.good())
	{
		chout << fixed << setprecision(2);
		chout << obj.mChecking << endl;
	}
	chout.close();

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
	string line;

	// We know the width of the label, so we can just throw away that many
	// characters to get the data we want.
	getline(input, line);
	line.erase(0, LABEL_WIDTH);
	obj.mAccountNumber = line;

	getline(input, line);
	line.erase(0, LABEL_WIDTH);
	obj.mSSN = line;

	getline(input, line);
	line.erase(0, LABEL_WIDTH);
	obj.mName = line;

	getline(input, line);
	line.erase(0, LABEL_WIDTH);
	obj.mAddress = line;

	getline(input, line);
	line.erase(0, LABEL_WIDTH);
	obj.mPhoneNumber = line;

	// In the case of the checking and savings data we need to ignore one more character
	// to get rid of the dollar sign.
	getline(input, line);
	line.erase(0, LABEL_WIDTH + 1);
	obj.mChecking = stod(line);

	getline(input, line);
	line.erase(0, LABEL_WIDTH + 1);
	obj.mSaving = stod(line);

	obj.mTotal = obj.mChecking + obj.mSaving;

	input.ignore(INT_MAX, '\n');

	return input;
}


/*	Function: ifstream& operator >>(ifstream& input, Account& obj);
*	Pre: None.
*	Post: The values of the account object will be set using the
*	contents of the file stream and the contents of the appropriate
*	.sav and .chk files.
*	Purpose: Populate an account object from a file stream.
*********************************************************/
ifstream& operator >>(ifstream& input, Account& obj)
{
	string line;

	// Balance files
	ifstream sin;
	ifstream chin;

	// Get non-balance data using the methodology as the istream extraction operator
	getline(input, line);
	line.erase(0, LABEL_WIDTH);
	obj.mAccountNumber = line;

	getline(input, line);
	line.erase(0, LABEL_WIDTH);
	obj.mSSN = line;

	getline(input, line);
	line.erase(0, LABEL_WIDTH);
	obj.mName = line;

	getline(input, line);
	line.erase(0, LABEL_WIDTH);
	obj.mAddress = line;

	getline(input, line);
	line.erase(0, LABEL_WIDTH);
	obj.mPhoneNumber = line;

	// Get balance data
	sin.open((obj.mAccountNumber + ".sav").c_str());
	
	if (sin.good())
	{
		sin >> obj.mSaving;
	}
	sin.close();

	chin.open((obj.mAccountNumber + ".chk").c_str());

	if (chin.good())
	{
		chin >> obj.mChecking;
	}
	chin.close();

	obj.mTotal = obj.mSaving + obj.mChecking;

	return input;
}


/*	Function: bool operator ==(const string& lhs, const Account& rhs);
*	Pre: None.
*	Post: Return whether or not the string is equal to the accounts
*	account number.
*	Purpose: Check if the objects account number matches the value of the string.
*********************************************************/
bool operator ==(const string& lhs, const Account& rhs)
{
	return lhs == rhs.mAccountNumber;
}


/*	Function: bool operator !=(const string& lhs, const Account& rhs);
*	Pre: None.
*	Post: Return whether or not the string is equal to the accounts
*	account number.
*	Purpose: Check if the objects account number matches a string
*	and returns false if it does.
*********************************************************/
bool operator !=(const string& lhs, const Account& rhs)
{
	return lhs != rhs.mAccountNumber;
}
