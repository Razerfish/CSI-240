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

#include "account.h"


/*********************************************************
*						Constructors					 *
*********************************************************/

/*	Function: Account::Account();
*	Pre: None
*	Post: All member variable will be set to default values.
*	Purpose: Default constructor.
*********************************************************/
Account::Account()
{
	mName = "";
	mPassword = "";
	mName = "";

	mManager = false;
}


/*	Function: Account::Account(string username, string password, string name);
*	Pre: The username, password and name to use.
*	Post: The object will be initialized using the values provided.
*	Purpose: Non-default constructor. Note: mManager will always be set to false
*	and can only be changed by reading an entry from a database.
*********************************************************/
Account::Account(string username, string password, string name)
{
	mUsername = username;
	mPassword = password;
	mName = name;

	mManager = false;
}


/*********************************************************
*						Destructor						 *
*********************************************************/

/*	Function: Account::~Account();
*	Pre: None
*	Post: None
*	Purpose: Destructor
*********************************************************/
Account::~Account()
{

}


/*********************************************************
*						Accessors						 *
*********************************************************/


/*	Function: string Account::getName();
*	Pre: None
*	Post: Returns the name of the account holder.
*	Purpose: Get the name of the account holder.
*********************************************************/
string Account::getName()
{
	return mName;
}


/*	Function: string Account::getUsername();
*	Pre: None
*	Post: Returns the username of the account.
*	Purpose: Get the username of an account.
*********************************************************/
string Account::getUsername()
{
	return mUsername;
}


/*********************************************************
*						Mutators						 *
*********************************************************/

/*	Function: void Account::setName(string name);
*	Pre: The new name for the account.
*	Post: The name of the account will be set to the
*	supplied value.
*	Purpose: Change the name of the account holder.
*********************************************************/
void Account::setName(string name)
{
	mName = name;
}


/*	Function: void Account::setPassword(string password);
*	Pre: The new password.
*	Post: The password of the account will be changed to the
*	supplied value.
*	Purpose: Change the password of an account.
*********************************************************/
void Account::setPassword(string password)
{
	mPassword = password;
}


/*	Function: void Account::setUsername(string username);
*	Pre: The new username.
*	Post: The username of the account will be updated to the
*	supplied value.
*	Purpose: Change the username of an account.
*********************************************************/
void Account::setUsername(string username)
{
	mUsername = username;
}


/*********************************************************
*						Other							 *
*********************************************************/


/*	Function: bool Account::isManager();
*	Pre: None
*	Post: Returns whether or not the account has manager
*	privileges.
*	Purpose: Check the manager status of an account.
*********************************************************/
bool Account::isManager()
{
	return mManager;
}


/*	Function: bool Account::validateLogin(string username, string password);
*	Pre: The username and password to check.
*	Post: Returns true if the login credentials are valid,
*	otherwise returns false.
*	Purpose: Validate login credentials.
*********************************************************/
bool Account::validateLogin(string username, string password)
{
	if (username == mUsername && password == mPassword)
	{
		return true;
	}

	return false;
}


/*********************************************************
*						Friend Functions				 *
*********************************************************/

/*	Function: ifstream& operator >>(ifstream& in, Account& obj);
*	Pre: References to the ifstream and account objects to use.
*	Post: The account object will be initialized using data from
*	the ifstream.
*	Purpose: Read an account from a file stream.
*********************************************************/
ifstream& operator >>(ifstream& in, Account& obj)
{
	getline(in, obj.mUsername);
	getline(in, obj.mPassword);
	getline(in, obj.mName);

	in >> obj.mManager;

	in.ignore(INT_MAX, '\n');
	in.clear();

	return in;
}


/*	Function: ofstream& operator <<(ofstream& out, Account& obj);
*	Pre: References to the ofstream and account objects to use.
*	Post: The state of the account object will be output into the stream.
*	Purpose: Save an account to a file.
*********************************************************/
ofstream& operator <<(ofstream& out, Account& obj)
{
	out
		<< obj.mUsername << endl
		<< obj.mPassword << endl
		<< obj.mName << endl
		<< obj.mManager << endl;

	return out;
}
