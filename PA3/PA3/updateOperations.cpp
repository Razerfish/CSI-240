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

/*	Function: string promptPhoneNumber();
*	Pre: None
*	Post: A valid phone number will be returned.
*	Purpose: Prompt the user until they enter a phone number
*	in the correct format.
*********************************************************/
string promptPhoneNumber(bool allowBlank)
{
	string number;

	cout << "Please enter a phone number in the format (xxx) xxx-xxxx: ";
	getline(cin, number);

	while (!isValidPhoneNumber(number, allowBlank))
	{
		displayMessage(INVALID_INPUT);
		cout << "Please enter a phone number in the format (xxx) xxx-xxxx: ";
		getline(cin, number);
	}

	// Cleanup after getline
	cin.clear();

	return number;
}


/*	Function: string promptSSN();
*	Pre: None
*	Post: A valid SSN will be returned.
*	Purpose: Prompt the user until they enter an SSN
*	in the correct format.
*********************************************************/
string promptSSN(bool allowBlank)
{
	string ssn;

	cout << "Please enter an SSN in the format xxx-xx-xxxx: ";
	getline(cin, ssn);

	while (!isValidSSN(ssn, allowBlank))
	{
		displayMessage(INVALID_INPUT);
		cout << "Please enter an ssn in the format xxx-xx-xxxx: ";
		getline(cin, ssn);
	}

	// Cleanup after getline
	cin.clear();

	return ssn;
}


/*	Function: bool isValidPhoneNumber(string number);
*	Pre: The number to test.
*	Post: Returns whether or not the number is valid.
*	Purpose: Check if a phone number if formatted properly.
*********************************************************/
bool isValidPhoneNumber(string number, bool allowBlank)
{
	// Check length
	if (number.length() != 14 && !(allowBlank && number.length() == 0)) // 9 digit phone number + open and close paratheses and a space
	{
		return false;
	}
	else if (allowBlank && number.length() == 0)
	{
		return true;
	}

	for (int i = 0; i < 14; i++) // We already know that it's exactly 14 chars long
	{
		switch (i)
		{
		case 0: // First character should be '('
			if (number[0] != '(')
			{
				return false;
			}
			break;
		case 4: // 5th character should be ')'
			if (number[4] != ')')
			{
				return false;
			}
			break;
		case 5: // 6th character should be ' '
			if (number[5] != ' ')
			{
				return false;
			}
			break;
		case 9: // 10th character should be '-'
			if (number[9] != '-')
			{
				return false;
			}
			break;
		default: // Everything else should be a digit
			if (!isdigit(number[i]))
			{
				return false;
			}
		}
	}

	return true;
}


/*	Function: bool isValidSSN(string ssn);
*	Pre: The string to test
*	Post: Returns whether or not the ssn is valid.
*	Purpose: Check if an ssn is formatted properly.
*********************************************************/
bool isValidSSN(string ssn, bool allowBlank)
{
	// Check length
	if (ssn.length() != 11 && !(allowBlank && ssn.length() == 0)) // 3 digits + dash + 2 digits + dash + 4 digits = 11
	{
		return false;
	}
	else if (allowBlank && ssn.length() == 0)
	{
		return true;
	}

	for (int i = 0; i < 11; i++)
	{
		switch (i)
		{
		case 3: // 4th character should be '-'
			if (ssn[3] != '-')
			{
				return false;
			}
			break;
		case 6: // 7th character should also be '-'
			if (ssn[6] != '-')
			{
				return false;
			}
			break;
		default: // Everything else should be a digit
			if (!isdigit(ssn[i]))
			{
				return false;
			}
		}
	}

	return true;
}
