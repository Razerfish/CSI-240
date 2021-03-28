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


/*********************************************************
*						Other							 *
*********************************************************/

/*	bool Customer::loadData();
*	Pre: The filename should be set before running this.
*	Post: The Account array will be populated from the contents
*	of the file
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
