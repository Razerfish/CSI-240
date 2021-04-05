/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: PA3 - Part 3
Date Assigned: March 26 2021
Due Date: April 5 2021
Description: Make a banking system
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking)
*/

#include "banking.h"

/*	Function: void addAccount();
*	Pre: None
*	Post: The user will be prompted for information and an account will
*	attempted to be created.
*	Purpose: Create a new account and add it to the database.
*********************************************************/
void addAccount()
{
	string data = "";
	string number = getAccountNumber();
	string
		ssn,
		name,
		line,
		address,
		phoneNumber;

	double checking;

	int entries;

	ifstream din;
	ofstream dout;

	while (isAccountExists(number))
	{
		displayMessage(ACCOUNT_ALREADY_EXIST);
		number = getAccountNumber();
	}

	ssn = getSSN();
	phoneNumber = getPhoneNumber();
	
	cout << "Enter the applicants name: ";
	getline(cin, name);

	cout << "Enter the applicants address: ";
	getline(cin, address);

	checking = getAmount("Enter initial deposit: ");

	Account acc(number, ssn, name, address, phoneNumber, checking, 0.0);

	// Get current length of database.
	din.open(ACCOUNT_DATAFILE);
	
	if (!din.good())
	{
		displayMessage(ACCOUNT_DB_NOT_AVAILABLE);
		return;
	}

	din >> entries;

	// Read database into memory
	while (!din.eof())
	{
		getline(din, line);
		data += line + "\n";
	}

	din.close();

	// Increment database length
	entries++;

	// Check if we have a trailing newline and if so discard the last newline
	if (data[data.length() - 1] == '\n' && data[data.length() - 2] == '\n')
	{
		data = data.substr(0, data.length() - 1);
	}

	// Output updated database
	dout.open(ACCOUNT_DATAFILE, ios::out);

	if (!dout.good())
	{
		displayMessage(ACCOUNT_DB_NOT_AVAILABLE);
		return;
	}

	dout
		<< entries
		<< data
		<< acc;

	dout.close();
}


/*	Function: void checkBalance(string accountNumber);
*	Pre: The account number of which to check the balance of.
*	Post: The accounts balance will be displayed in the console.
*	Purpose: Display an accounts balance.
*********************************************************/
void checkBalance(string accountNumber)
{
	Customer database;
	database.setFilename(ACCOUNT_DATAFILE);
	if (!database.loadData())
	{
		displayMessage(ACCOUNT_DB_NOT_AVAILABLE);
		return;
	}

	Account acc = database.getCustomer(accountNumber);

	cout << "Checking: $" << acc.getChecking() << endl;
	cout << "Savings: $" << acc.getSaving() << endl;
	cout << "Total: $" << acc.getTotal();
}


/*	Function: void deleteAccount();
*	Pre: None
*	Post: The specified account will be deleted
*	Purpose: Delete an account
*********************************************************/
void deleteAccount()
{
	string data = "";
	string accountNumber;
	string line;

	istringstream dataStream;

	int entries;

	ifstream din;
	ofstream dout;

	accountNumber = getAccountNumber(false);

	// Get entries
	din.open(ACCOUNT_DATAFILE);

	if (!din.good())
	{
		displayMessage(ACCOUNT_DB_NOT_AVAILABLE);
		return;
	}

	din >> entries;

	while (!din.eof())
	{
		getline(din, line);
		data += line + '\n';
	}

	din.close();

	// Reduce entry count
	entries--;

	// Check if we have a trailing newline and if so discard the last newline
	if (data[data.length() - 1] == '\n' && data[data.length() - 2] == '\n')
	{
		data = data.substr(0, data.length() - 1);
	}

	// Remove the target entry from the loaded database
	dataStream.str(data);
	data = "";
	// Check each account number line for the target account number
	int i = 0;
	while (!dataStream.eof())
	{
		getline(dataStream, line);
		if (i % 4 == 0)
		{
			if (line.substr(LABEL_WIDTH, (line.length() - LABEL_WIDTH) - 1) == accountNumber)
			{
				// Discard next 3 lines
				getline(dataStream, line);
				getline(dataStream, line);
				getline(dataStream, line);
				i += 3;
			}
			else
			{
				data += line + '\n';
			}
		}
		else
		{
			data += line + '\n';
		}
		i++;
	}

	// Output updated database
	dout.open(ACCOUNT_DATAFILE, ios::out);

	if (!dout.good())
	{
		displayMessage(ACCOUNT_DB_NOT_AVAILABLE);
		return;
	}

	dout
		<< entries
		<< data;

	dout.close();

	// Delete balance files
	remove((accountNumber + ".sav").c_str());
	remove((accountNumber + ".chk").c_str());
}


/*	Function: void deposit(string accountNumber);
*	Pre: The account number to deposit funds into.
*	Post: The user will be prompted for an amount and that amount will be deposited into the account.
*	Purpose: Deposit to an account.
*********************************************************/
void deposit(string accountNumber)
{
	double amount;
	double balance;
	Customer database;
	Account acc;

	database.setFilename(ACCOUNT_DATAFILE);
	if (!database.loadData())
	{
		displayMessage(ACCOUNT_DB_NOT_AVAILABLE);
		return;
	}

	acc = database.getCustomer(accountNumber);

	balance = acc.getChecking();

	amount = getAmount("Amount to deposit: ");

	acc.setChecking(balance + amount);

	database.storeData();
}


/*	Function: string getAccountNumber(bool forceExist = true);
*	Pre: Whether or not to ensure that the entered account number exists,
*	defaults to true.
*	Post: A proper account number is returned
*	Purpose: Prompt the user for an account number.
*********************************************************/
string getAccountNumber(bool forceExist)
{
	string accountNumber;
	bool isValid = true;

	unsigned int i;

	cout << "Enter an account number: ";
	getline(cin, accountNumber);

	for (i = 0; i < accountNumber.length(); i++)
	{
		if (!isdigit(accountNumber[i]))
		{
			isValid = false;
			break;
		}
	}

	// Don't allow blank account numbers
	if (accountNumber.length() == 0)
	{
		isValid = false;
	}

	while (!isValid || (forceExist && isAccountExists(accountNumber)))
	{
		if (!isValid)
		{
			displayMessage(INVALID_INPUT);
		}
		else
		{
			displayMessage(ACCOUNT_NOT_FOUND);
		}

		isValid = true;

		cout << "Enter an account number: ";
		getline(cin, accountNumber);

		for (i = 0; i < accountNumber.length(); i++)
		{
			if (!isdigit(accountNumber[i]))
			{
				isValid = false;
				break;
			}
		}

		if (accountNumber.length() == 0)
		{
			isValid = false;
		}
	}

	return accountNumber;
}


/*	Function: double getAmount(string message);
*	Pre: The message to use to prompt the user for an amount.
*	Post: A double will be returned.
*	Purpose: Prompt the user to enter an amount
*********************************************************/
double getAmount(string message)
{
	string line;
	bool isValid = true;

	unsigned int i;

	cout << message;
	getline(cin, line);

	for (i = 0; i < line.length(); i++)
	{
		if (!isdigit(line[i]) && line[i] != '.')
		{
			isValid = false;
			break;
		}
	}

	// Ensure that it's not empty
	if (line.length() == 0)
	{
		isValid = false;
	}

	while (!isValid)
	{
		displayMessage(INVALID_AMOUNT);

		isValid = true;

		cout << message;
		getline(cin, line);

		for (i = 0; i < line.length(); i++)
		{
			if (!isdigit(line[i]) && line[i] != '.')
			{
				isValid = false;
				break;
			}
		}

		if (line.length() == 0)
		{
			isValid = false;
		}
	}

	return stod(line);
}


/*	Function: double getCurrentBalance(string accountNumber);
*	Pre: The account number to get the balance of.
*	Post: Returns the checking balance of that account.
*	Assumes that the provided account exists.
*	Purpose: Get the balance of an account.
*********************************************************/
double getCurrentBalance(string accountNumber)
{
	Customer database;

	database.setFilename(ACCOUNT_DATAFILE);

	if (!database.loadData())
	{
		displayMessage(ACCOUNT_DB_NOT_AVAILABLE);
		return 0.0;
	}

	return database.getCustomer(accountNumber).getChecking();
}


/*	Function: bool isAccountExists(string accountNumber);
*	Pre: The account number to look up.
*	Post: Returns whether or not the account exists.
*	Purpose: Check if an account exists.
*********************************************************/
bool isAccountExists(string accountNumber)
{
	Customer database;

	database.setFilename(ACCOUNT_DATAFILE);
	if (!database.loadData())
	{
		displayMessage(ACCOUNT_DB_NOT_AVAILABLE);
		return false;
	}

	// If account does not exist database.getCustomer will return a blank account object
	if (database.getCustomer(accountNumber).getAccountNumber() == "")
	{
		return false;
	}
	else
	{
		return true;
	}
}
