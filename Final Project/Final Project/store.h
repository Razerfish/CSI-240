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

#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

#include "account.h"
#include "linkedList.h"
#include "book.h"
#include "snack.h"
#include "commonFunctions.h"

using namespace std;

const string REPORT_FILE = "report.txt";
const string EMPLOYEE_FILE = "employees.dat";
const string SNACK_FILE = "snacks.dat";
const string BOOK_FILE = "books.dat";
const int FILL_WIDTH = 30;

struct Summary
{
	string note;
	string code;
	double price;
};


class Store
{
private:
	Account* mEmployees;
	int mEmployeeCount;

	Book* mBooks;
	int mBookCount;

	Snack* mSnacks;
	int mSnackCount;

	LinkedList mTransactions;

public:
	// Constructor
	Store();

	// Destructor
	~Store();

	// Other
	void addCashier();

	void checkout(double total);

	void deleteCashier();

	void generateReport();
	Summary getSummary(string code);

	Account& login();
	bool loadData();

	void modifyCashier();

	void searchBooks();
	void searchCashiers();
	void searchSnacks();
};

#endif
