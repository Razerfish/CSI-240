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

#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

#include "account.h"

using namespace std;

class Customer
{
private:
	int mCount;
	Account* mAccounts;
	string mFilename;

	string parseCustomer(int index); // Deals directly with the index of account so access should be restricted to other members

public:
	// Default constructor
	Customer();

	// Destructor
	~Customer();

	// Accessors
	int getCount();
	Account getCustomer(string accountNumber);
	string getFilename();

	// Mutators
	void setFilename(string filename);
	void modifyAccount(string accountNumber, Account modified);

	// Other
	bool accountExists(string accountNumber);
	void addCustomer(string accountNumber, Account customer);
	void deleteCustomer(string accountNumber);
	bool loadData();
	void searchByAccountNum(string query);
	void searchByAddress(string query);
	void searchByName(string query);
	void searchByPhoneNumber(string query);
	void searchBySSN(string query);
	void storeData();
};

#endif
