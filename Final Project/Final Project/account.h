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

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <fstream>
#include <string>

using namespace std;

class Account
{
private:
	string mUsername;
	string mPassword;
	string mName;

	bool mManager;

public:
	// Constructors
	Account();
	Account(string username, string password, string name);

	// Destructor
	~Account();

	// Accessors
	string getName();
	string getUsername();

	// Mutators
	void setName(string name);
	void setPassword(string password);
	void setUsername(string username);

	// Other
	bool isManager();
	bool validateLogin(string username, string password);

	// Friend functions
	friend ifstream& operator >>(ifstream& in, Account& obj);
	friend ofstream& operator <<(ofstream& out, const Account& obj);
};

#endif
