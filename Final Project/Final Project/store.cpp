/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: Final Project
Date Assigned: April 5 2021
Due Date: April 29 2021
Description: Create a management system for the Champlain bookstore.
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

#include "store.h"


/*********************************************************
*						Constructor						 *
*********************************************************/

/*	Function: Store::Store();
*	Pre: None
*	Post: All members will be initialized.
*	Purpose: Default constructor.
*********************************************************/
Store::Store()
{
	mEmployees = nullptr;
	mEmployeeCount = 0;

	mBooks = nullptr;
	mBookCount = 0;

	mSnacks = nullptr;
	mSnackCount = 0;
}


/*********************************************************
*						Destructor						 *
*********************************************************/

/*	Function: Store::~Store();
*	Pre: None
*	Post: All dynamic arrays will be freed.
*	Purpose: Destructor
*********************************************************/
Store::~Store()
{
	if (mEmployees != nullptr)
	{
		delete[] mEmployees;
	}
	mEmployees = nullptr;

	if (mBooks != nullptr)
	{
		delete[] mBooks;
	}
	mBooks = nullptr;

	if (mSnacks != nullptr)
	{
		delete[] mSnacks;
	}
	mSnacks = nullptr;
}


/*********************************************************
*						Other							 *
*********************************************************/

/*	Function: void Store::addCashier();
*	Pre: A manager should be logged in.
*	Post: If the specified username is not already taken a
*	new cashier account will be created.
*	Purpose: Create a new cashier.
*********************************************************/
void Store::addCashier()
{
	bool exists = false;
	Account cashier;
	Account* temp;

	string
		name,
		username,
		password;

	int i;

	name = promptName("Name of the new cashier: ");
	username = promptUsername("Username for the new cashier: ");
	password = promptPassword("Password for the new cashier: ");

	cashier.setName(name);
	cashier.setUsername(username);
	cashier.setPassword(password);

	for (i = 0; i < mEmployeeCount; i++)
	{
		if (username == mEmployees[i].getUsername())
		{
			exists = true;
			break;
		}
	}

	if (exists)
	{
		cout << "Account already exists!\nAborting...\n";
		systemPause();
	}
	else
	{
		temp = new Account[mEmployeeCount + 1];
		for (i = 0; i < mEmployeeCount; i++)
		{
			temp[i] = mEmployees[i];
		}
		temp[i] = cashier;

		delete[] mEmployees;
		mEmployees = temp;

		mEmployeeCount++;

		cout << "Cashier added!\n";
		systemPause();
	}
}


/*	Function: void Store::checkout(double total);
*	Pre: The total of the transaction.
*	Post: The total is added to the daily record.
*	Purpose: Checkout a customer and add a record of the
*	transaction to the database.
*********************************************************/
void Store::checkout(double total)
{
	mTransactions.append(total);

	cout << "Transaction of: $" << total << " recorded.\n";
}


/*	Function: void deleteCashier();
*	Pre: A manager should be logged in.
*	Post: The user will be prompted for a cashier to delete.
*	Purpose: Delete a cashier.
*********************************************************/
void Store::deleteCashier()
{
	string username;
	char confirm;

	Account cashier;
	Account* temp;

	bool exists = false;

	int i;
	int foundAt;

	username = promptUsername("Username of the cashier to fire: ");

	// Ensure that cashier exists.
	for (i = 0; i < mEmployeeCount; i++)
	{
		if (mEmployees[i].getUsername() == username)
		{
			exists = true;
			foundAt = i;
			break;
		}
	}

	// Ensure that account is not a manager.
	if (mEmployees[foundAt].isManager())
	{
		cout << "Account is a manager, you do not have permission to fire this employee.\n";
		cout << "Aborting...\n";
		systemPause();
		return;
	}

	cout << "Are you sure you want to fire this cashier? This action cannot be undone (y/n): ";
	cin >> confirm;

	if (cin.fail() || (confirm != 'y' && confirm != 'Y'))
	{
		cin.ignore(INT_MAX, '\n');
		cin.clear();

		cout << "Operation cancelled\n";
		systemPause();
		return;
	}

	cin.ignore(INT_MAX, '\n');
	cin.clear();

	if (exists)
	{
		temp = new Account[mEmployeeCount - 1];
		for (i = 0; i < mEmployeeCount; i++)
		{
			if (i < foundAt)
			{
				temp[i] = mEmployees[i];
			}
			else if (i > foundAt)
			{
				temp[i - 1] = mEmployees[i];
			}
		}

		mEmployeeCount--;
		delete[] mEmployees;
		mEmployees = temp;

		cout << "Cashier deleted!\n";
		systemPause();
	}
	else
	{
		cout << "No account with the username: " << username << " exists!\n";
		cout << "Aborting...\n";
		systemPause();
	}
}


/*	Function: void Store::generateReport();
*	Pre: A manager should be logged in.
*	Post: Attempts to save a daily report to disk.
*	Purpose: Save a daily report.
*********************************************************/
void Store::generateReport()
{
	double total = 0.0;
	double average;
	int count;

	ofstream dout;

	count = mTransactions.getCount();

	for (int i = 0; i < count; i++)
	{
		total += mTransactions[i];
	}

	average = total / double(count);

	dout.open(REPORT_FILE.c_str());

	if (dout.good())
	{
		dout << fixed << setprecision(2);

		dout
			<< "Amount of transactions: " << count << endl
			<< "Total sales: $" << total << endl
			<< "Average sale amount: $" << average << endl;

		dout.close();
		
		cout << "Report successfully saved to disk.\n";
	}
	else
	{
		dout.close();

		cout << "Failed to save report.\n";
	}
}


/*	Function: Summary Store::getSummary(string code);
*	Pre: The code to search for.
*	Post: Returns a summary of the specified item
*	containing the title if it's a book or the name
*	if it's a snack, the price of the item and its code.
*	Purpose: Get the summary of an item by its code.
*********************************************************/
Summary Store::getSummary(string code)
{
	int i;

	bool found = false;

	Summary output{ "", "", 0 };
	
	// Search books first.
	for (i = 0; i < mBookCount; i++)
	{
		if (mBooks[i].getCode() == code)
		{
			found = true;
			output.code = mBooks[i].getCode();
			output.note = mBooks[i].getTitle();
			output.price = mBooks[i].getPrice();
			break;
		}
	}

	// Search snacks if not found in books
	for (i = 0; i < mSnackCount; i++)
	{
		if (mSnacks[i].getCode() == code)
		{
			output.code = mSnacks[i].getCode();
			output.note = mSnacks[i].getName();
			output.price = mSnacks[i].getPrice();
			break;
		}
	}

	return output;
}


/*	Function: Account& Store::login();
*	Pre: None
*	Post: Returns a reference to the account that
*	the user logged in to.
*	Purpose: Loop until a user provides valid login
*	credentials.
*********************************************************/
Account& Store::login()
{
	string
		username,
		password;

	bool valid = false;
	int i;

	// Don't bother enforcing formatting rules here as any valid login will already adhere to them.
	cout << "Enter your username: ";
	getline(cin, username);

	cout << "Enter your password: ";
	getline(cin, password);

	for (i = 0; i < mEmployeeCount; i++)
	{
		if (mEmployees[i].validateLogin(username, password))
		{
			valid = true;
			break;
		}
	}

	while (!valid)
	{
		cout << "\nInvalid login.\nEnter your username: ";
		getline(cin, username);

		cout << "Enter your password: ";
		getline(cin, password);

		// Don't need to reset valid, if we're here it's already false.
		for (i = 0; i < mEmployeeCount; i++)
		{
			if (mEmployees[i].validateLogin(username, password))
			{
				valid = true;
				break;
			}
		}
	}

	return mEmployees[i];
}


/*	Function: void Store::modifyCashier();
*	Pre: A manager should be logged in.
*	Post: The manager will be prompted for the new values
*	to apply to the cashier.
*	Purpose: Modify a cashier.
*********************************************************/
void Store::modifyCashier()
{
	int foundAt = -1;
	int i;

	string
		name,
		username,
		password,
		oldUsername;

	char confirm;

	bool duplicate = false;

	oldUsername = promptUsername("Enter the current username of the account to modify: ");

	for (i = 0; i < mEmployeeCount; i++)
	{
		if (mEmployees[i].getUsername() == oldUsername)
		{
			foundAt = i;
			break;
		}
	}

	if (foundAt != -1)
	{
		// Ensure that account is not a manager.
		if (mEmployees[foundAt].isManager())
		{
			cout << "Account is a manager, you do not have permission to modify this account.\n";
			cout << "Aborting...\n";
		}
		else
		{
			username = promptUsername("Enter the new username for this account: ");
			
			// Check that username isn't already taken.
			for (i = 0; i < mEmployeeCount; i++)
			{
				if (mEmployees[i].getUsername() == username)
				{
					duplicate = true;
					break;
				}
			}

			while (duplicate)
			{
				cout << "An account with that username already exists!\n";
				username = promptUsername("Enter the new username for this account: ");

				duplicate = false;
				for (i = 0; i < mEmployeeCount; i++)
				{
					if (mEmployees[i].getUsername() == username)
					{
						duplicate = true;
						break;
					}
				}
			}

			password = promptPassword("Enter the new password for this account: ");
			name = promptName("Enter the new name for this account: ");

			cout << "Are you sure that you want to modify this account? This cannot be undone (y/n): ";
			cin >> confirm;

			if (cin.fail() || (confirm != 'y' && confirm != 'Y'))
			{
				cout << "Operation cancelled...\n";
			}
			else
			{
				mEmployees[i].setUsername(username);
				mEmployees[i].setPassword(password);
				mEmployees[i].setName(name);
			}

			cin.ignore(INT_MAX, '\n');
			cin.clear();
		}
	}
	else
	{
		cout << "\nNo account with username " << oldUsername << " exists.\n";
		cout << "Aborting...\n";
	}
}


/*	Function: void Store::searchBooks();
*	Pre: None
*	Post: The user will be prompted for search parameters and
*	the results of that search will be printed to the screen.
*	Purpose: Search through the book inventory.
*********************************************************/
void Store::searchBooks()
{
	string
		isbn,
		title,
		author;

	bool match;
	int hits = 0;

	ostringstream results;

	results << fixed << setprecision(2);

	cout
		<< "Enter the search parameters to use, leave a field blank to allow any:\n"
		<< "ISBN: ";
	getline(cin, isbn);

	cout << "Title: ";
	getline(cin, title);

	cout << "Author: ";
	getline(cin, author);

	for (int i = 0; i < mBookCount; i++)
	{
		match = true;

		if (isbn != "")
		{
			if (mBooks[i].getISBN() != isbn)
			{
				match = false;
			}
		}

		if (title != "")
		{
			if (mBooks[i].getTitle() != title)
			{
				match = false;
			}
		}

		if (author != "")
		{
			if (mBooks[i].getAuthor() != author)
			{
				match = false;
			}
		}

		if (match)
		{
			hits++;
			results
				<< string(FILL_WIDTH, '-') << endl
				<< "ISBN: " << mBooks[i].getISBN() << endl
				<< "Title: " << mBooks[i].getTitle() << endl
				<< "Author: " << mBooks[i].getAuthor() << endl
				<< "Price: $" << mBooks[i].getPrice() << endl
				<< "Stock: " << mBooks[i].getStock() << endl
				<< "Code: " << mBooks[i].getCode() << endl;
		}
	}

	if (hits > 0)
	{
		results << string(FILL_WIDTH, '-') << endl;
		cout << "Got" << hits << " hits\n\n" << results.str();
	}
	else
	{
		cout << "Got 0 hits\n\n";
	}

}


/*	Function: void Store::searchCashiers();
*	Pre: A manager should be logged in.
*	Post: The user will be prompted for a name to search for
*	and the results of that search will be printed to the screen.
*	Purpose: Search cashiers by name.
*********************************************************/
void Store::searchCashiers()
{
	string name;

	int hits = 0;

	ostringstream results;

	name = promptName("Enter the name to search for: ");

	for (int i = 0; i < mEmployeeCount; i++)
	{
		if (mEmployees[i].getName() == name)
		{
			hits++;
			results
				<< string(FILL_WIDTH, '-') << endl
				<< "Name: " << mEmployees[i].getName() << endl
				<< "Username: " << mEmployees[i].getUsername() << endl;
		}
	}

	if (hits > 0)
	{
		results << string(FILL_WIDTH, '-') << endl;
		cout << "Got " << hits << " hits:\n" << results.str();
	}
	else
	{
		cout << "Got 0 hits\n";
	}
}


/*	Function: void Store::searchSnacks();
*	Pre: None
*	Post: The user will be prompted for the name of a snack
*	and the results of that search will be printed to the screen.
*	Purpose: Search snacks by name.
*********************************************************/
void Store::searchSnacks()
{
	string name;

	int hits = 0;

	ostringstream results;

	results << fixed << setprecision(2);

	// promptNames is meant for people names but it works just fine here so why not reuse it?
	name = promptName("Enter the snack name to search for: ");

	for (int i = 0; i < mSnackCount; i++)
	{
		if (mSnacks[i].getName() == name)
		{
			hits++;
			results
				<< string(FILL_WIDTH, '-') << endl
				<< "Name: " << mSnacks[i].getName() << endl
				<< "Price: $" << mSnacks[i].getPrice() << endl
				<< "Stock: " << mSnacks[i].getStock() << endl
				<< "Code: " << mSnacks[i].getCode() << endl;
		}
	}

	if (hits > 0)
	{
		results << string(FILL_WIDTH, '-') << endl;
		cout << "Got " << hits << " hits:\n" << results.str();
	}
	else
	{
		cout << "Got 0 hits";
	}
}
