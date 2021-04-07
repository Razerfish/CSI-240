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

#include "customer.h"

/*********************************************************
*						Constructor						 *
*********************************************************/

/*	Function: Customer::Customer();
*	Pre: None
*	Post: All member variables will be initialized to default values.
*	Purpose: Default Constructor
*********************************************************/
Customer::Customer()
{
	mCount = 0;
	mAccounts = nullptr;
	mFilename = "";
}


/*********************************************************
*						Destructor						 *
*********************************************************/

/*	Function: Customer::~Customer();
*	Pre: None
*	Post: mCount is set to 0, mFilename is set to "",
*	memory allocated to mAccounts is freed and mAccounts
*	is set to NULL
*	Purpose: Deconstructor
*********************************************************/
Customer::~Customer()
{
	mCount = 0;
	mFilename = "";

	if (mAccounts != nullptr)
	{
		delete[] mAccounts;
	}
	mAccounts = nullptr;
}


/*********************************************************
*						Accessors						 *
*********************************************************/

/*	Function: int Customer::getCount();
*	Pre: None
*	Post: Returns the length of the Account array.
*	Purpose: Get the length of the Account array.
*********************************************************/
int Customer::getCount()
{
	return mCount;
}


/*	Function: Account Customer::getCustomer(string accountNumber);
*	Pre: A string containing the account number to look for.
*	Post: If the specifed account number exists in the array
*	the account with that number is returned, otherwise an
*	empty account object is returned.
*	Purpose: Get an account by account number.
*********************************************************/
Account Customer::getCustomer(string accountNumber)
{
	Account customer;

	for (int i = 0; i < mCount; i++)
	{
		if (accountNumber == mAccounts[i])
		{
			customer = mAccounts[i];
			break;
		}
	}

	return customer;
}


/*	string Customer::getFilename();
*	Pre: None
*	Post: Returns the current filename for the object.
*	Purpose: Get the filename of a customer object.
*********************************************************/
string Customer::getFilename()
{
	return mFilename;
}


/*********************************************************
*						Mutators						 *
*********************************************************/

/*	Function: void Customer::setFilename(string filename);
*	Pre: None
*	Post: The filename will be set to the new value.
*	Purpose: Modifiy the filename of a customer object.
*********************************************************/
void Customer::setFilename(string filename)
{
	mFilename = filename;
}


/*	Function: void Customer::modifyAccount(string accountNumber, Account modified);
*	Pre: The number of the account to update and an Account object containing the
*	new values. The account number must exist and the database and must match
*	the account number of the updated Account object or else nothing will be done.
*	Post: Assuming that all requirements are met the existing account object
*	will be replaced with the provided object and the database on disk will
*	be refreshed.
*	Purpose: Modify the parameters of an account in the database.
*********************************************************/
void Customer::modifyAccount(string accountNumber, Account modified)
{
	int fountAt = -1;

	// Abort if account numbers don't match
	if (accountNumber != modified)
	{
		return;
	}

	// Find the index of the target account
	for (int i = 0; i < mCount; i++)
	{
		if (accountNumber == mAccounts[i])
		{
			fountAt = i;
			break;
		}
	}

	// Abort if the requested account doesn't exist
	if (fountAt == -1)
	{
		return;
	}

	// Update account
	mAccounts[fountAt] = modified;

	// Refresh database on disk
	if (mFilename != "")
	{
		storeData();
	}
}


/*********************************************************
*						Other							 *
*********************************************************/

/*	Function: bool Customer::accountExists(string accountNumber);
*	Pre: Provide the account number to look up.
*	Post: Returns true if an account with the matching account number
*	exists in the database, otherwise returns false.
*	Purpose: Check if an account is present in the database.
*********************************************************/
bool Customer::accountExists(string accountNumber)
{
	for (int i = 0; i < mCount; i++)
	{
		if (accountNumber == mAccounts[i])
		{
			return true;
		}
	}

	return false;
}


/*	Function: void Customer::addCustomer(string accountNumber);
*	Pre: Provide the account number of the account to create and
*	an Account object to add.
*	Post: If the account number is not already in use the account
*	will be added to the database, the entry count will be updated
*	and the database will be refreshed on disk.
*	Purpose: Add a new account to the database.
*********************************************************/
void Customer::addCustomer(string accountNumber, Account customer)
{
	int i;
	Account* temp;

	// Abort if account number already exists
	for (i = 0; i < mCount; i++)
	{
		if (accountNumber == mAccounts[i])
		{
			return;
		}
	}

	// Copy current database into temp array
	temp = new Account[mCount + 1];

	for (i = 0; i < mCount; i++)
	{
		temp[i] = mAccounts[i];
	}

	// Fill last position with the new account
	temp[i] = customer;

	// Copy temp to database
	delete[] mAccounts;
	mAccounts = temp;

	// Update entry count
	mCount++;

	// Refresh data on disk
	if (mFilename != "")
	{
		storeData();
	}
}


/*	Function: void Customer::deleteCustomer(string accountNumber);
*	Pre: The account number of the account to delete.
*	Post: If the account exists it will be deleted from the
*	database, the entry count will be updated and the data
*	on disk will be refreshed. If there is only one account in
*	the database the nothing will be done.
*	Purpose: Delete an existing account.
*********************************************************/
void Customer::deleteCustomer(string accountNumber)
{
	int foundAt = -1;
	int i;

	Account* temp;

	// Abort if there is only 1 account in the database
	if (mCount == 1)
	{
		return;
	}

	// Get the index of the account to delete
	for (i = 0; i < mCount; i++)
	{
		if (accountNumber == mAccounts[i])
		{
			foundAt = i;
			break;
		}
	}

	// Abort if not found
	if (foundAt == -1)
	{
		return;
	}

	temp = new Account[mCount - 1];

	// Copy all other accounts over
	for (i = 0; i < mCount; i++)
	{
		if (i < foundAt)
		{
			temp[i] = mAccounts[i];
		}
		else if (i > foundAt)
		{
			temp[i - 1] = mAccounts[i];
		}
	}

	delete[] mAccounts;
	mAccounts = temp;

	mCount--;

	if (mFilename != "")
	{
		storeData();
	}
}


/*	bool Customer::loadData();
*	Pre: The filename should be set before running this.
*	Post: The Account array will be populated from the contents
*	of the file.
*	Purpose: Load data from a file.
*********************************************************/
bool Customer::loadData()
{
	ifstream fin;

	if (mFilename == "")
	{
		return false;
	}

	fin.open(mFilename.c_str());

	if (fin.good())
	{
		fin >> mCount;

		mAccounts = new Account[mCount];

		// Advance to next line
		fin.ignore(INT_MAX, '\n');

		for (int i = 0; i < mCount && !fin.eof(); i++)
		{
			fin >> mAccounts[i];
		}

		fin.close();
		return true;
	}
	else
	{
		fin.close();
		return false;
	}
}


/*	Function: string Customer::parseCustomer(int index);
*	Pre: Provide the index of the account to generate a string from.
*	Post: Returns a string containing formatted information
*	about the provided account. If the provided index is out of range
*	a blank string is returned.
*	Purpose: Generate "pretty" output for accounts.
*********************************************************/
string Customer::parseCustomer(int index)
{
	// Return empty string if out of range
	if (index < 0 || index > mCount)
	{
		return string();
	}

	Account& acc = mAccounts[index];
	
	ostringstream output;

	output << fixed << setprecision(2);

	output
		<< string(LABEL_WIDTH * 2, '-') << endl
		<< setw(LABEL_WIDTH) << left << "Account Number:" << acc.getAccountNumber() << endl
		<< setw(LABEL_WIDTH) << left << "Name:" << acc.getName() << endl
		<< setw(LABEL_WIDTH) << left << "SSN: " << acc.getSSN() << endl
		<< setw(LABEL_WIDTH) << left << "Address:" << acc.getAddress() << endl
		<< setw(LABEL_WIDTH) << left << "Phone Number:" << acc.getPhoneNumber() << endl
		<< setw(LABEL_WIDTH) << left << "Savings:" << "$" << acc.getSaving() << endl
		<< setw(LABEL_WIDTH) << left << "Checking:" << "$" << acc.getChecking() << endl
		<< setw(LABEL_WIDTH) << left << "Total:" << "$" << acc.getTotal() << endl;

	return output.str();
}


/*	Function: void Customer::searchByAccountNum(string query);
*	Pre: Provide the account number to search for.
*	Post: Displays all matches from the database.
*	Purpose: Search for accounts by account number.
*********************************************************/
void Customer::searchByAccountNum(string query)
{
	ostringstream results;

	int hits = 0;

	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i] == query)
		{
			results << parseCustomer(i);
			hits++;
		}
	}

	if (hits > 0)
	{
		cout
			<< "Found " << hits << " account(s) matching the query\n"
			<< results.str() << string(LABEL_WIDTH * 2, '-') << endl;
	}
	else
	{
		cout << "No accounts found matching query\n";
	}
}


/*	Function: void Customer::searchByAddress(string query);
*	Pre: The address to search for
*	Post: Any matches will be printed to the console
*	Purpose: Search accounts in the database by address
*********************************************************/
void Customer::searchByAddress(string query)
{
	ostringstream results;

	int hits = 0;

	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i].getAddress() == query)
		{
			results << parseCustomer(i);
			hits++;
		}
	}

	if (hits > 0)
	{
		cout
			<< "Found " << hits << " account(s) matching the query\n"
			<< results.str() << string(LABEL_WIDTH * 2, '-') << endl;
	}
	else
	{
		cout << "No accounts found matching query\n";
	}
}


/*	Function: void Customer::searchByPhoneNumber(string query);
*	Pre: The phone number to search for
*	Post: Any matches will be printed to the console
*	Purpose: Search accounts in the database by phone number
*********************************************************/
void Customer::searchByPhoneNumber(string query)
{
	ostringstream results;

	int hits = 0;

	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i].getPhoneNumber() == query)
		{
			results << parseCustomer(i);
			hits++;
		}
	}

	if (hits > 0)
	{
		cout
			<< "Found " << hits << " account(s) matching the query\n"
			<< results.str() << string(LABEL_WIDTH * 2, '-') << endl;
	}
	else
	{
		cout << "No accounts found matching query\n";
	}
}


/*	Function: void Customer::searchBySSN(string query);
*	Pre: The SSN to search for
*	Post: Any matches will be printed to the console
*	Purpose: Search accounts in the database by SSN
*********************************************************/
void Customer::searchBySSN(string query)
{
	ostringstream results;

	int hits = 0;

	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i].getSSN() == query)
		{
			results << parseCustomer(i);
			hits++;
		}
	}

	if (hits > 0)
	{
		cout
			<< "Found " << hits << " account(s) matching the query\n"
			<< results.str() << string(LABEL_WIDTH * 2, '-') << endl;
	}
	else
	{
		cout << "No accounts found matching query\n";
	}
}


/*	Function: void Customer::searchByName(string query);
*	Pre: The name to search for
*	Post: Any matches will be printed to the console
*	Purpose: Search accounts in the database by name
*********************************************************/
void Customer::searchByName(string query)
{
	ostringstream results;

	int hits = 0;

	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i].getName() == query)
		{
			results << parseCustomer(i);
			hits++;
		}
	}

	if (hits > 0)
	{
		cout
			<< "Found " << hits << " account(s) matching the query\n"
			<< results.str() << string(LABEL_WIDTH * 2, '-') << endl;
	}
	else
	{
		cout << "No accounts found matching query\n";
	}
}


/*	Function: void Customer::storeData();
*	Pre: The filename should be set before running this.
*	Post: The current state of the Account array will be
*	written to disk, any existing data in the output file
*	will be lost.
*	Purpose: Write the state of the Account array to disk.
*********************************************************/
void Customer::storeData()
{
	ofstream fout;

	if (mFilename == "")
	{
		return;
	}

	fout.open(mFilename.c_str(), ios::out | ios::trunc);

	if (fout.good())
	{
		fout << mCount << endl;

		for (int i = 0; i < mCount; i++)
		{
			fout << mAccounts[i];
		}
	}

	fout.close();
}
