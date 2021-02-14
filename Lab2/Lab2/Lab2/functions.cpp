/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: Lab 2
Date Assigned: February 8 2021
Due Date: February 15 2021
Description: An updated version of the PA1 COVID data parser
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

#include "header.h"

/*	Function: bool fileAvailable(string file)
*	Pre: A string containing the relative path to file that you want to check the existance of.
*	Post: Returns a bool representing whether or not the file exists.
*	Purpose: Check whether or not a file exists before attempting to read it or possibly overwrite it.
*	This is accomplished by checking if the file can be opened for reading, which in most cases serves as a good
*	enough proxy for a files existance, although it may run into problems for files that can be read from normally but
*	require elevated privileges to write to, so don't do that.
*********************************************************/
bool fileAvailable(string file)
{
	ifstream fileIN;
	bool exists = true;

	fileIN.open(file.c_str());

	if (fileIN.fail() || fileIN.bad())
	{
		exists = false;
	}

	fileIN.close();

	return exists;
}


/*	Function: void initializeArray(covid arr[], int length)
*	Pre: An empty covid array of length "length".
*	Post: The supplied array will be filled with default entries.
*	Purpose: Initialize the supplied array.
*********************************************************/
void initializeArray(covid arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		covid entry =
		{
			"",
			"",
			"",
			{ 0, 0, 0},
			0,
			0,
			0,
			0.0,
			0.0
		};

		arr[i] = entry;
	}
}


/*	Function: parseDate(string line)
*	Pre: A date string formatted as YYYY-MM-DD
*	Post: Returns a date_s struct containing the parsed data.
*	Purpose: Parse dates into date_s structs.
*********************************************************/
date_s parseDate(string line)
{
	istringstream input(line);

	string token;

	date_s output;

	// There should only be 3 entries to parse so we'll only do this 3 times.
	getline(input, token, '-'); // Get year.
	output.year = stoi(token);

	getline(input, token, '-'); // Get month.
	output.month = stoi(token);

	getline(input, token, '-'); // Get day.
	output.day = stoi(token);

	return output;
}


/*	Function: covid parseLine(string line)
*	Pre: A line containing comma seperated values to parse.
*	Post: Returns a covid struct containing that parsed data.
*	Purpose: Parse the supplied line into a covid struct.
*********************************************************/
covid parseLine(string line)
{
	istringstream input(line);

	string token;

	covid output;

	// We only need to get the first 7 entries.

	getline(input, token, ','); // Get ISO country code.
	output.code = token;

	getline(input, token, ','); // Get continent.
	output.continent = token;

	getline(input, token, ','); // Get country name.
	output.name = token;

	getline(input, token, ','); // Get date.
	output.date = parseDate(token);

	getline(input, token, ','); // Get total cases.
	output.tCases = stoi(token);

	getline(input, token, ','); // Get total deaths.
	output.tDeaths = stoi(token);

	getline(input, token, ','); // Get population.
	output.population = stoi(token);

	// Set pctCases and pctDeaths to 0.0 for now.
	output.pctCases = 0.0;
	output.pctDeaths = 0.0;

	return output;
}


/*	Function: populateArray(covid arr[], int length, string file)
*	Pre: An initialized covid array of length "length and a
*	string pointing to the file to read from.
*	Post: The array will be populated with the data from the file.
*	Post: Populate a covid array with data from the specified file.
*********************************************************/
void populateArray(covid arr[], int length, string file)
{
	ifstream dataIN;

	string line;

	dataIN.open(file.c_str());

	//	Only read enough to fill the array.
	for (int i = 0; i < length && getline(dataIN, line); i++)
	{
		arr[i] = parseLine(line);
	}
}
