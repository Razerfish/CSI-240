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

#include "mainFunctions.h"

/*	Function: void addToCart(Store& database, Summary* &cart, int& length, double& total);
*	Pre: References of the variables to work with.
*	Post: The user will be prompted for an item and that item
*	will be added to the cart and related values will be updated.
*	Purpose: Add an item to the cart.
*********************************************************/
void addToCart(Store& database, Summary* &cart, int& length, double& total)
{
	string code;
	Summary* temp;
	Summary newItem;

	int i;
	cout << "Enter the code of the item to add: ";
	getline(cin, code);

	if (!database.itemAvailable(code))
	{
		cout << "Item not available.\n";
		systemPause();
	}
	else
	{
		newItem = database.getSummary(code);
		database.decrementStock(code);

		if (cart == nullptr)
		{
			cart = new Summary[1];
			cart[0] = newItem;
			length = 1;
			total = newItem.price;
		}
		else
		{
			temp = new Summary[length + 1];
			for (i = 0; i < length; i++)
			{
				temp[i] = cart[i];
			}
			temp[i] = newItem; // Pretty sure the C6385 here is a false positive.

			delete[] cart;
			cart = temp;

			length++;
			total += newItem.price;
		}
	}
}


/*	Function: void cashierLoop(Store& database, Account& user);
*	Pre: The Store and Account objects to work with.
*	Post: The function exits when the cashier logs out.
*	Purpose: Display the cashier menu on loop until the
*	user logs out.
*********************************************************/
void cashierLoop(Store& database, Account& user)
{
	int choice;

	Summary* cart = nullptr;
	int length = 0;
	double total = 0.0;

	while (true) // Loop until the user logs out.
	{
		clearScreen();

		if (length != 0)
		{
			cout << "Cart:\n";

			for (int i = 0; i < length; i++)
			{
				cout
					<< string(FILL_WIDTH, '*') << endl
					<< "Item: " << cart[i].note << endl
					<< "Code: " << cart[i].code << endl
					<< "Price: $" << cart[i].price << endl;
			}
			cout << string(FILL_WIDTH, '*') << endl;
			cout << "Total: $" << total << endl << endl;
		}

		choice = cashierMenu(user);

		switch (choice)
		{
		case 1: // Add item to cart
			addToCart(database, cart, length, total);
			break;
		
		case 2: // Remove from cart.
			removeFromCart(database, cart, length, total);
			break;

		case 3: // Search items
			searchItems(database);
			break;

		case 4: // Checkout
			checkout(database, cart, length, total);
			break;

		case 5: // Cancel transaction
			emptyCart(database, cart, length, total);
			break;

		case 6: // Logout
			if (cart != nullptr)
			{
				emptyCart(database, cart, length, total);
			}
			else
			{
				cout << "Goodbye!\n";
				systemPause();
			}
			return;
		}
	}
}


/*	Function: int cashierMenu(Account& cashier);
*	Pre: The account of the cashier to greet.
*	Post: The cashier will be presented with the actions
*	they can perform and input will be prompted.
*	Purpose: Prompt the cashier for an action.
*********************************************************/
int cashierMenu(Account& cashier)
{
	int choice = 0;

	cout
		<< "\nHello " << cashier.getName() << "!\n"
		<< "Please enter your desired action:\n\n"
		<< "1. Add item to cart\n"
		<< "2. Remove item from cart\n"
		<< "3. Search items\n"
		<< "4. Checkout\n"
		<< "5. Cancel transaction\n"
		<< "6. Logout\n\n"
		<< "Enter your selection: ";

	cin >> choice;

	while (choice < 1 || choice > 6 || cin.fail())
	{
		clearScreen();
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout
			<< "Invalid selection!\n"
			<< "Please enter your desired action:\n\n"
			<< "1. Add item to cart\n"
			<< "2. Remove item from cart\n"
			<< "3. Search items\n"
			<< "4. Checkout\n"
			<< "5. Cancel transaction\n"
			<< "6. Logout\n\n"
			<< "Enter your selection: ";

		cin >> choice;
	}

	// Cleanup for possible future getlines
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return choice;
}


/*	Function: void checkout(Store& database, Summary*& cart, int& length, double& total);
*	Pre: A cart with items in it.
*	Post: A transaction will be recorded and the cart will be emptied.
*	Purpose: Checkout a customer.
*********************************************************/
void checkout(Store& database, Summary*& cart, int& length, double& total)
{
	if (cart == nullptr)
	{
		cout << "Cart is empty!\n";
		systemPause();
	}
	else
	{
		database.addTransaction(total);
		delete[] cart;
		cart = nullptr;
		length = 0;
		total = 0.0;

		cout << "Thank you!\n";
		systemPause();
	}
}


/*	Function: void emptyCart(Store& database, Summary*& cart, int& length, double& total);
*	Pre: The variables to work with.
*	Post: All items will be removed from the cart.
*	Purpose: Abort a transaction.
*********************************************************/
void emptyCart(Store& database, Summary*& cart, int& length, double& total)
{
	if (cart != nullptr)
	{
		for (int i = 0; i < length; i++)
		{
			database.incrementStock(cart[i].code);
		}

		delete[] cart;
		cart = nullptr;
		length = 0;
		total = 0.0;
		cout << "Goodbye...\n";
		systemPause();
	}
	else
	{
		cout << "Cart is already empty!\n";
		// Reset things just to be sure.
		length = 0;
		total = 0.0;
		systemPause();
	}
}


/*	Function: bool load(Store& database);
*	Pre: The store to load data into.
*	Post: Returns true if data was successfully loaded,
*	returns false if loading was aborted.
*	Purpose: Attempt to load data until success, or the
*	user chooses to abort.
*********************************************************/
bool load(Store& database)
{
	char choice;
	bool success;

	success = database.loadData();

	while (!success)
	{
		cout << "Database loading failed.\nTry again? (y/n): ";
		cin >> choice;

		if (cin.fail() || (choice != 'y' && choice != 'Y'))
		{
			cout << "Shutting down...\n";
			systemPause();
			return false;
		}
	}

	cout << "Database loaded successfully!\n";
	systemPause();
	return true;
}


/*	Function: bool managerLoop(Store& database, Account& user);
*	Pre: The database and user to work with.
*	Post: Returns true if logged out normally, returns false
*	if shutdown was triggered.
*	Purpose: Run the manager menu on a loop.
*********************************************************/
bool managerLoop(Store& database, Account& user)
{
	int choice;

	while (true) // Loop until return is called
	{
		clearScreen();
		choice = managerMenu(user);

		switch (choice)
		{
		case 1: // Generate report
			database.generateReport();
			systemPause();
			break;

		case 2: // Search cashiers
			database.searchCashiers();
			systemPause();
			break;

		case 3: // Update cashier info
			database.modifyCashier();
			systemPause();
			break;

		case 4: // Hire cashier
			database.addCashier();
			systemPause();
			break;

		case 5: // Fire cashier
			database.deleteCashier();
			systemPause();
			break;

		case 6: // Logout
			cout << "\nGoodbye!\n\n";
			return false; // Exit without triggering shutdown

		case 7:
			cout << "\nGoodnight!\n\n";
			return true; // Trigger shutdown
		}
	}
}


/*	Function: int managerMenu(Account& manager);
*	Pre: The manager to greet.
*	Post: The user will be prompted for an action.
*	Purpose: Get the user to choose an action.
*********************************************************/
int managerMenu(Account& manager)
{
	int choice = 0;

	cout
		<< "Hello " << manager.getName() << "!\n"
		<< "Please enter your desired action:\n\n"
		<< "1. Generate daily report\n"
		<< "2. Search cashiers\n"
		<< "3. Update cashier information\n"
		<< "4. Hire cashier\n"
		<< "5. Fire cashier\n"
		<< "6. Logout\n"
		<< "7. Shutdown system\n\n"
		<< "Enter your selection: ";

	cin >> choice;

	while (choice < 1 || choice > 7 || cin.fail())
	{
		clearScreen();
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout
			<< "Invalid selection!\n"
			<< "Please enter your desired action:\n\n"
			<< "1. Generate daily report\n"
			<< "2. Search cashiers\n"
			<< "3. Update cashier information\n"
			<< "4. Hire cashier\n"
			<< "5. Fire cashier\n"
			<< "6. Logout\n"
			<< "7. Shutdown system\n\n"
			<< "Enter your selection: ";

		cin >> choice;
	}

	// Cleanup after cin extraction
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return choice;
}


/*	Function: int promptSearchType();
*	Pre: A cashier should be logged in.
*	Post: Prompts the user for the type of search
*	to perform.
*	Purpose: Prompt search type.
*********************************************************/
int promptSearchType()
{
	int choice;

	cout
		<< "What type of search should be performed?\n\n"
		<< "1. Book search\n"
		<< "2. Snack search\n"
		<< "3. Abort\n\n"
		<< "Enter your selection: ";

	cin >> choice;

	while (choice < 1 || choice > 3 || cin.fail())
	{
		clearScreen();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout
			<< "Invalid selection!\n"
			<< "What type of search should be performed?\n\n"
			<< "1. Book search\n"
			<< "2. Snack search\n"
			<< "3. Abort\n\n"
			<< "Enter your selection: ";

		cin >> choice;
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return choice;
}


/*	Function: void removeFromCart(Store& database, Summary*& cart, int& length, double& total);
*	Pre: The variables to work with.
*	Post: The user will be prompted for the item to remove,
*	if that item exists in the cart it will be removed,
*	otherwise the function will abort.
*	Purpose: Remove an item from the cart.
*********************************************************/
void removeFromCart(Store& database, Summary*& cart, int& length, double& total)
{
	string code;
	Summary* temp;
	Summary toRemove;

	int i;
	int foundAt = -1;

	if (cart == nullptr)
	{
		cout << "Cart is empty!\n";
		systemPause();
	}
	else
	{
		cout << "Enter the code of the item to remove: ";
		getline(cin, code);

		for (i = 0; i < length; i++)
		{
			if (cart[i].code == code)
			{
				foundAt = i;
				toRemove = cart[i];
				break;
			}
		}

		database.incrementStock(code);

		if (foundAt == -1)
		{
			cout << "No item with the specified code is in the cart.\n";
			systemPause();
		}
		else if (length == 1)
		{
			delete[] cart;
			cart = nullptr;
			length = 0;
			total = 0.0;
		}
		else
		{
			temp = new Summary[length - 1];
			for (i = 0; i < length; i++)
			{
				if (i < foundAt)
				{
					temp[i] = cart[i];
				}
				else if (i > foundAt)
				{
					temp[i - 1] = cart[i];
				}
			}

			length--;
			delete[] cart;
			cart = temp;
			total -= toRemove.price;
		}
	}
}


/*	Function: void searchItems(Store& database);
*	Pre: A reference to the store database.
*	Post: The user will be prompted for search terms
*	and the result will be printed to the screen.
*	Purpose: Search through inventory and display the results.
*********************************************************/
void searchItems(Store& database)
{
	int choice = promptSearchType();

	switch (choice)
	{
	case 1: // Book search
		database.searchBooks();
		break;

	case 2: // Snack search
		database.searchSnacks();
		break;

	case 3: // Abort
		cout << "Aborting...\n";
		break;
	}

	systemPause();
}
