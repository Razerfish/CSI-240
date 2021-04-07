/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: PA3 - Part 1
Date Assigned: March 17 2021
Due Date: March 25 2021
Description: Create a class and a struct and write stub drivers for both of them.
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

#include "teller.h"

/*********************************************************
*						Constructor						 *
*********************************************************/

/*	Function: Teller::Teller();
*	Pre: None.
*	Post: mCount will be set to 0 and mTellers will point to NULL.
*	Purpose: Default initializer.
*********************************************************/
Teller::Teller()
{
	mCount = 0;
	mTellers = nullptr;
}


/*********************************************************
*						Destructor						 *
*********************************************************/

/*	Function: Teller::~Teller();
*	Pre: None.
*	Post: mCount is set to 0, memory allocated to mTellers
*	is freed and mTellers is set to NULL.
*	Purpose: Destructor.
*********************************************************/
Teller::~Teller()
{
	mCount = 0;

	delete[] mTellers;
	mTellers = nullptr;
}


/*********************************************************
*						Other							 *
*********************************************************/

/*	Function: bool Teller::loadData(string filename);
*	Pre: Provide the file to read data from.
*	Post: mCount and mTellers will be populated using
*	the contents of the specified file. Returns true
*	if successful, otherwise returns false.
*	Purpose: Load data from a properly formatted file.
*********************************************************/
bool Teller::loadData(string filename)
{
	ifstream fin;

	fin.open(filename.c_str());

	// Check that the file was opened properly.
	if (fin.good())
	{
		int length;
		string line;
		istringstream ss;
		
		// Attempt to get file length.
		getline(fin, line);
		try
		{
			length = stoi(line);
		}
		catch (invalid_argument)
		{
			fin.close();
			return false;
		}

		// Setup mCount and mTellers.
		mCount = length;
		mTellers = new Employee[length];

		// Loop through file until array is filled or we reach EOF
		for (int i = 0; i < length && !fin.eof(); i++)
		{
			getline(fin, line);

			// Reset ss
			ss.str(line);
			ss.clear();

			ss >> mTellers[i];
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


/*	Function: void Teller::storeData(string filename);
*	Pre: None.
*	Post: The current contents of the object will be saved
*	to the specified file. If the file already exists its
*	contents will be overwritten.
*	Purpose: Save object state to file.
*********************************************************/
void Teller::storeData(string filename)
{
	ofstream fout;

	// Open file and truncate contents
	fout.open(filename.c_str(), ios::out | ios::trunc);

	if (fout.good())
	{
		// Write length
		fout << mCount << endl;

		// Write contents
		for (int i = 0; i < mCount; i++)
		{
			fout << mTellers[i].ID << ' ' << mTellers[i].password << endl;
		}
	}

	fout.close();
}


/*	Function: bool Teller::verifyTeller(const string& id, const string& password);
*	Pre: The ID and password to test.
*	Post: Returns true if the ID and password exist and match, otherwise returns false.
*	Purpose: Check that an ID and password pair exist in the object.
*********************************************************/
bool Teller::verifyTeller(const string& id, const string& password)
{
	bool match = false;

	// Search for ID
	for (int i = 0; i < mCount; i++)
	{
		if (id == mTellers[i].ID)
		{
			if (password == mTellers[i].password)
			{
				match = true;
			}
			break;
		}
	}

	return match;
}
