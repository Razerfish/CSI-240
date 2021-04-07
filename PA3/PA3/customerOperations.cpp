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

/*	Function: void addAccount(Customer& database);
*	Pre: Provide an initialized database to add to.
*	Post: A new customer will be added to the provided
*	database.
*	Purpose: Add a new customer.
*********************************************************/
void addAccount(Customer& database)
{
	const string message = "Enter the number for the new account: ";
	string
		name,
		address,
		accountNumber;

	Account acc;

	accountNumber = promptAccountNumber(message);
	while (database.accountExists(accountNumber))
	{
		displayMessage(ACCOUNT_ALREADY_EXIST);
		accountNumber = promptAccountNumber(message);
	}

	cout << "Enter the name of the account holder: ";
	getline(cin, name);

	cout << "Enter the address of the account holder: ";
	getline(cin, address);

	acc.setAccountNumber(accountNumber);
	acc.setName(name);
	acc.setAddress(address);
	acc.setPhoneNumber(promptPhoneNumber());
	acc.setSSN(promptSSN());

	database.addCustomer(accountNumber, acc);
}


/*	Function: void deleteAccount(Customer& database);
*	Pre: Provide an initialized database to remove from.
*	Post: The selected customer will be removed from the
*	database.
*	Purpose: Remove a customer from the database.
*********************************************************/
void deleteAccount(Customer& database)
{
	const string message = "Enter the account number of the account to remove: ";
	string accountNumber = promptAccountNumber(message);

	while (!database.accountExists(accountNumber))
	{
		displayMessage(ACCOUNT_NOT_FOUND);
		accountNumber = promptAccountNumber(message);
	}

	database.deleteCustomer(accountNumber);

	remove((accountNumber + ".sav").c_str());
	remove((accountNumber + ".chk").c_str());
}


/*	Function: void deposit(Customer& database);
*	Pre: Provide the initialized database containing the
*	account to deposit to.
*	Post: The user will be prompted for an amount and that
*	amount will be deposited into the target checking account.
*	Purpose: Deposit funds into an account.
*********************************************************/
void deposit(Customer& database)
{
	const string amountMessage = "Enter the amount to deposit: ";
	const string accountMessage = "Enter the account number of the account to deposit to: ";
	string accountNumber;
	
	double amount;

	Account acc;

	accountNumber = promptAccountNumber(accountMessage);
	while (!database.accountExists(accountNumber))
	{
		displayMessage(ACCOUNT_NOT_FOUND);
		accountNumber = promptAccountNumber(accountMessage);
	}

	amount = promptAmount(amountMessage);

	acc = database.getCustomer(accountNumber);
	acc.setChecking(acc.getChecking() + amount);

	database.modifyAccount(accountNumber, acc);

	cout << "Thank you! Your new balance is: $" << acc.getChecking() << endl;
}


/*	Function: void displayBalance(Customer& database);
*	Pre: An initialized customer database
*	Post: The user will be prompted for an account number
*	and the account matching that number will have it's
*	balance displayed.
*	Purpose: Display the balance of an account.
*********************************************************/
void displayBalance(Customer& database)
{
	const string message = "Enter the account number for the account to display: ";
	string accountNumber;

	Account acc;

	accountNumber = promptAccountNumber(message);
	while (!database.accountExists(accountNumber))
	{
		displayMessage(ACCOUNT_NOT_FOUND);
		accountNumber = promptAccountNumber(message);
	}

	acc = database.getCustomer(accountNumber);
	
	cout
		<< "Balance of account " << acc.getAccountNumber() << endl
		<< "Savings: $" << acc.getSaving() << endl
		<< "Checking: $" << acc.getChecking() << endl
		<< "Total: $" << acc.getSaving() + acc.getChecking() << endl;
}


/*	Function: string promptAccountNumber(bool forceExist = true);
*	Pre: Whether or not to ensure that the entered account number exists,
*	defaults to true.
*	Post: A proper account number is returned
*	Purpose: Prompt the user for an account number.
*********************************************************/
string promptAccountNumber(string message)
{
	string accountNumber;
	bool isValid = true;

	unsigned int i;

	cout << message;
	getline(cin, accountNumber);

	// Only allow digits
	for (i = 0; i < accountNumber.length(); i++)
	{
		if (!isdigit(accountNumber[i]))
		{
			isValid = false;
			break;
		}
	}

	// Don't allow blank entries
	if (accountNumber.length() == 0)
	{
		isValid = false;
	}

	while (!isValid)
	{
		isValid = true;

		displayMessage(INVALID_INPUT);
		cout << message;
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


/*	Function: double promptAmount(string message);
*	Pre: The message to use to prompt the user for an amount.
*	Post: A double will be returned.
*	Purpose: Prompt the user to enter an amount
*********************************************************/
double promptAmount(string message)
{
	string line;
	bool isValid = true;

	int digitCount = 0;
	int periodCount = 0;

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
		else if (isdigit(line[i]))
		{
			digitCount++;
		}
		else if (line[i] == '.')
		{
			periodCount++;
		}
	}

	// Ensure that it's not empty, contains at least 1 digit and contains no more than 1 period
	if (line.length() == 0 || digitCount == 0 || periodCount > 1)
	{
		isValid = false;
	}

	while (!isValid)
	{
		displayMessage(INVALID_AMOUNT);

		isValid = true;
		digitCount = 0;
		periodCount = 0;

		cout << message;
		getline(cin, line);

		for (i = 0; i < line.length(); i++)
		{
			if (!isdigit(line[i]) && line[i] != '.')
			{
				isValid = false;
				break;
			}
			else if (isdigit(line[i]))
			{
				digitCount++;
			}
			else if (line[i] == '.')
			{
				periodCount++;
			}
		}


		if (line.length() == 0 || digitCount == 0 || periodCount > 1)
		{
			isValid = false;
		}
	}

	return stod(line);
}


/*	Function: void updateAccount(Customer& database);
*	Pre: An initialized database of customers
*	Post: The user will be prompted for an account number
*	and the matching account's details will be updated.
*	Purpose: Update the personal information of an account
*	holder.
*********************************************************/
void updateAccount(Customer& database)
{
	const string message = "Enter the account number of the account to modify: ";
	string
		accountNumber,
		phoneNumber,
		address,
		name,
		ssn;

	Account acc;

	accountNumber = promptAccountNumber(message);
	while (!database.accountExists(accountNumber))
	{
		displayMessage(ACCOUNT_NOT_FOUND);
		accountNumber = promptAccountNumber(message);
	}

	cout << "Enter the new phone number of the account holder (or leave blank to leave unchanged): ";
	phoneNumber = promptPhoneNumber(true);

	cout << "Enter the new ssn of the account holder (or leave blank to leave unchanged): ";
	ssn = promptSSN(true);

	cout << "Enter the new name of the account holder (or leave blank to leave unchanged): ";
	getline(cin, name);

	cout << "Enter the new address of the account holder (or leave blank to leave unchanged): ";
	getline(cin, address);

	acc = database.getCustomer(accountNumber);

	if (phoneNumber != "")
	{
		acc.setPhoneNumber(phoneNumber);
	}

	if (ssn != "")
	{
		acc.setSSN(ssn);
	}

	if (name != "")
	{
		acc.setName(name);
	}

	if (address != "")
	{
		acc.setAddress(address);
	}

	database.modifyAccount(accountNumber, acc);
}


/*	Function: void withdraw(Customer& database);
*	Pre: An initalized customer database.
*	Post: The user will be prompted for an account number
*	and an amount and that amount will be withdrawn from that
*	account.
*	Purpose: Withdraw funds from an account.
*********************************************************/
void withdraw(Customer& database)
{
	const string accountMessage = "Enter the account number of the account to withdraw from: ";
	const string amountMessage = "Enter the amount to withdraw: ";
	string accountNumber;

	double amount;

	Account acc;

	accountNumber = promptAccountNumber(accountMessage);
	while (!database.accountExists(accountNumber))
	{
		displayMessage(ACCOUNT_NOT_FOUND);
		accountNumber = promptAccountNumber(accountMessage);
	}

	amount = promptAmount(amountMessage);
	
	acc = database.getCustomer(accountNumber);

	while (acc.getChecking() < amount)
	{
		displayMessage(INSUFFICIENT_FUNDS);
		amount = promptAmount(amountMessage);
	}

	acc.setChecking(acc.getChecking() - amount);

	database.modifyAccount(accountNumber, acc);

	cout << "Thank you! Your new balance is: $" << acc.getChecking() << endl;
}
