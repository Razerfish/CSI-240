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

#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int LABEL_WIDTH = 30;

class Account
{
private:
	string mAccountNumber;

	string mSSN;
	string mName;
	string mAddress;
	string mPhoneNumber;

	double mChecking;
	double mSaving;
	double mTotal;

public:
	// Default constructor.
	Account();

	// Non-default constructer.
	Account(string accountNumber, string ssn, string name, string address, string phoneNumber, double checking, double saving);

	// Destructer.
	~Account();

	// Accessors
	string getAccountNumber();
	string getAddress();
	double getChecking();
	string getName();
	string getPhoneNumber();
	double getSaving();
	string getSSN();
	double getTotal();

	// Mutators.
	void setAccountNumber(string accountNumber);
	void setAddress(string address);
	void setChecking(double checking);
	void setName(string name);
	void setPhoneNumber(string phoneNumber); // I'm assuming that the phone number mutator being named getPhoneNumber in the UML was a typo.
	void setSaving(double saving);
	void setSSN(string ssn);

	// Operators
	bool operator ==(const Account& rhs);
	bool operator ==(const string& rhs);

	bool operator !=(const Account& rhs);
	bool operator !=(const string& rhs);

	bool operator >(const Account& rhs);
	bool operator <(const Account& rhs);

	// Friend functions.
	friend ostream& operator <<(ostream& output, const Account& obj);
	friend ofstream& operator <<(ofstream& output, const Account& obj);

	friend istream& operator >>(istream& input, Account& obj);
	friend ifstream& operator >>(ifstream& input, Account& obj);

	friend bool operator ==(const string& lhs, const Account& rhs);
	friend bool operator !=(const string& lhs, const Account& rhs);
};

#endif
