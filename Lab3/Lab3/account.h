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

#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <string>

using namespace std;
class Account
{
private:
	string ssn;
	string name;
	double checkingAmt;
	double savingAmt;
	double total;

public:
	// Default constructor.
	Account();

	// Non-default constructer.
	Account(string ssn, string name, double checkingAmt, double savingAmt);

	// Destructer.
	~Account();

	// Accessors
	double getChecking();
	string getName();
	double getSaving();
	string getSSN();
	double getTotal();

	// Mutators.
	void setChecking(double checking);
	void setName(string name);
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
	freind bool operator !=(const string& lhs, const Account& rhs);
};

#endif
