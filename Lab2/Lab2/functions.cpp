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

/*	Function: double getGlobalCaseRate(covid arr[], int length);
*	Pre: A populated covid array of length "length".
*	Post: Returns the percentage of the global population that has been infected.
*	Purpose: Calculate the the percentage of the global population that has been infected.
*********************************************************/
double getGlobalCaseRate(covid arr[], int length)
{
	long long
		totalPop = 0,
		totalCases = 0;

	for (int i = 0; i < length; i++)
	{
		totalPop += arr[i].population;
		totalCases += arr[i].cases;
	}

	return (double(totalCases) / double(totalPop)) * 100;
}


/*	Function: double getGlobalDeathRate(covid arr[], int length);
*	Pre: A populated covid array of length "length".
*	Post: Returns the percentage of the global population that has died of covid.
*	Purpose: Calculate the the percentage of the global population that has died of covid.
*********************************************************/
double getGlobalDeathRate(covid arr[], int length)
{
	long long
		totalPop = 0,
		totalDeaths = 0;

	for (int i = 0; i < length; i++)
	{
		totalPop += arr[i].population;
		totalDeaths += arr[i].deaths;
	}

	return (double(totalDeaths) / double(totalPop)) * 100; // Wrong, should be deaths / cases.
}


/*	Function: void getLocalCaseRate(covid &country)
*	Pre: A covid struct containing the data for a country.
*	Post: The infection rate will be written to the given country's
*	pctCases field.
*	Purpose: Calculate the percentage of the population
*	that is infected.
*********************************************************/
void getLocalCaseRate(covid &country)
{
	country.pctCases = (double(country.cases) / double(country.population)) * 100;
}


/*	Function: void getLocalDeathRate(covid &country)
*	Pre: A covid struct containing the data for a country.
*	Post: The death rate will be written to the given country's
*	pctDeaths field.
*	Purpose: Calculate the percentage of the population
*	that has died of covid.
*********************************************************/
void getLocalDeathRate(covid &country)
{
	country.pctDeaths = (double(country.deaths) / double(country.population)) * 100; // Wrong, should be deaths / cases.
}


/*	Function: void displayTotal(double gCaseRate, double gDeathRate)
*	Pre: Supply the global infection rate and the global death rate.
*	Post: The supplied values will be formatted and displayed on screen.
*	Purpose: Format and display the global infections rate and the
*	global death rate.
*********************************************************/
void displayTotal(double gCaseRate, double gDeathrate)
{
	cout << fixed << setprecision(1);

	cout << "\nGlobal infection rate: " << gCaseRate << "%\n";
	cout << "Global death rate: " << gDeathrate << "%\n\n";
}


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
	output.date = token;

	getline(input, token, ','); // Get total cases.
	output.cases = stoi(token);

	getline(input, token, ','); // Get total deaths.
	output.deaths = stoi(token);

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


/*	Function: string promptInputFile()
*	Pre: None
*	Post: Either the name of the input file will be returned or a string containing NUL
*	if the user chose to terminate the program.
*	Purpose: Get the location of the input file from the user.
*********************************************************/
string promptInputFile()
{
	string inputFile;

	cout << "Enter the name of the input file: ";
	cin >> inputFile;

	while (!fileAvailable(inputFile))
	{
		int choice;

		cout << "\nCould not access the specified file!\n\n"
			<< "1. Try again\n"
			<< "2. Re-enter filename\n"
			<< "3. Exit\n\n"
			<< "Please enter your selection: ";
		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			choice = 0;
		}

		switch (choice)
		{
		default: cout << "\nInvalid selection\n";
		case 1: break;

		case 2:
			cout << "\nEnter the name of the input file: ";
			cin >> inputFile;
			break;

		case 3:
			cout << "\nExiting...\n";
			return "NUL"; // You can't name a file NUL in windows so we can return this and
			// know for sure that this isn't the file specified by the user.
		}
	}

	return inputFile;
}


/*	Function: string promptOutputFile()
*	Pre: None
*	Post: Either a string containing the path to the file to write to,
*	or NUL if the user chose to exit the program.
*	Purpose: Prompt the user for the location of the file to write to.
*********************************************************/
string promptOutputFile()
{
	string outputFile;

	bool overwrite = false;

	cout << "Enter the name of the file to output the processed data to: ";
	cin >> outputFile;

	while (fileAvailable(outputFile) && !overwrite)
	{
		int choice;

		cout << "\nFile already exists!\n"
			<< "1. Try again\n"
			<< "2. Re-enter filename\n"
			<< "3. Overwrite existing file\n"
			<< "4. Exit\n"
			<< "Please enter your selection: ";
		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			choice = 0;
		}

		switch (choice)
		{
		default: cout << "\nInvalid selection!\n";
		case 1: break;

		case 2:
			cout << "Enter the name of the file to output the processed data to: ";
			cin >> outputFile;
			break;

		case 3:
			overwrite = true;
			break;

		case 4:
			return "NUL";
		}
	}

	return outputFile;
}


/*	Function: bool saveOutput(covid arr[], int length)
*	Pre: An array of covid structs of length "length".
*	Post: Formatted data will be written to file.
*	Purpose: Format and write data to output file.
*********************************************************/
bool saveOutput(covid arr[], int length, string file)
{
	ofstream dataOUT;

	dataOUT.open(file.c_str(), ios::out | ios::trunc);

	// Check output stream.
	if (dataOUT.bad() || dataOUT.fail()) { return false; }

	for (int i = 0; i < length; i++)
	{
		// Break if we start getting empty entries.
		if (arr[i].code == "") { break; }

		dataOUT << fixed << setprecision(3);

		// Write date with width 12 aligned left.
		dataOUT << setw(12) << left << arr[i].date;

		// Write ISO code with width 10 aligned left.
		dataOUT << setw(10) << left << arr[i].code;

		// Write location with width 35 aligned left.
		// I'm assuming that by location you mean country name and continent,
		// the specification wasn't clear, althougl I could have just missed it.
		dataOUT << setw(35) << left << arr[i].name + ", " + arr[i].continent;

		// Write infected percentage with width 12 aligned right.
		dataOUT << setw(12) << right << arr[i].pctCases;

		// Write death percentage with width 12 aligned right.
		dataOUT << setw(12) << right << arr[i].pctDeaths << endl;
	}

	dataOUT.close();

	return true;
}
