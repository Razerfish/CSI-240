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

#ifndef _BANKING_H
#define _BANKING_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

#include "account.h"
#include "customer.h"
#include "employee.h"
#include "teller.h"

using namespace std;

// Data files
#define TELLER_DATAFILE "tellers.dat"
#define ACCOUNT_DATAFILE "accounts.dat"

// Error codes
#define ACCOUNT_ALREADY_EXIST 5
#define	ACCOUNT_NOT_FOUND 10
#define INSUFFICIENT_FUNDS 15
#define INVALID_AMOUNT 20
#define INVALID_INPUT 25
#define INVALID_CREDS 30
#define INVALID_SELECTION 35
#define ACCOUNT_DB_NOT_AVAILABLE 40
#define TELLER_DB_NOT_AVAILABLE 45

// commonFunctions.cpp

void clearScreen();
void displayLogo();
void displayMessage(int errorCode);
int mainMenu();
void systemPause();

// tellerOperations.cpp

void getIdPassword(string& id, string& password);
void login();
bool validateLogin(string id, string password);

// customerOperations.cpp

void addAccount(Customer& database);
void deleteAccount(Customer& database);
void deposit(Customer& database);
void displayBalance(Customer& database);
string promptAccountNumber(string message);
double promptAmount(string message);
void updateAccount(Customer& database);
void withdraw(Customer& database);

// updateOperations.cpp

string promptPhoneNumber(bool allowBlank = false);
string promptSSN(bool allowBlank = false);

bool isValidPhoneNumber(string number, bool allowBlank);
bool isValidSSN(string ssn, bool allowBlank);

// searchOperations.cpp

void customerSearch(Customer& database);
int searchMenu();
#endif
