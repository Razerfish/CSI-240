// Author: Bungo Baggins
// Class: CSI-240-03
// Assignment: PA-1
// Date Assigned: January 25 2021
// Due Date: February 1 2021
// Description: Read, parse and save data regarding COVID-19 infection and death statistics.
// Certification of Authenticity:
// I certify that this is entirely my own work, except where I have given fully documented references to the work of others. I understand the definition and
// consequences of plagiarism and acknowledge that the assessor of this assignment
// may, for the purpose of assessing this assignment:
// - Reproduce this assignment and provide a copy to another member of
// academic staff; and/or
// - Communicate a copy of this assignment to a plagiarism checking service
// (which may then retain a copy of this assignment on its database for
// the purpose of future plagiarism checking)


#include "header.h"

/*	Function: bool fileAvailable(string target)
*	Pre: A string containing the relative path to file that you want to check the existance of.
*	Post: Returns a bool representing whether or not the file exists.
*	Purpose: Check whether or not a file exists before attempting to read it or possibly overwrite it.
*	This is accomplished by checking if the file can be opened for reading, which in most cases serves as a good
*	enough proxy for a files existance, although it may run into problems for files that can be read from normally but
*	require elevated privileges to write to, so don't do that.
*********************************************************/
bool fileAvailable(string target)
{
	ifstream file;
	bool exists;

	file.open(target.c_str(), ios::in);

	if (file.fail() || file.bad())
	{
		exists = false;
	}
	else
	{
		exists = true;
	}

	file.close();

	return exists;
}


/*	Function: double getAverage(vector<int> input)
*	Pre: A vector containing a set of integers to average.
*	Post: Returns a double of the average of the supplied integer set.
*	Purpose: Average a set of integers.
*********************************************************/
double getAverage(vector<int> input)
{
	int sum = 0;

	for (int i = 0; i < input.size(); i++)
	{
		sum += input[i];
	}

	return double(sum) / double(input.size());
}


/*	Function: double getAverage(int input[], int length);
*	Pre: An array containing the integers to average and the length of that array.
*	Post: A double of the average of those integers.
*	Purpose: Average a set of integers.
*********************************************************/
double getAverage(int input[], int length)
{
	int sum = 0;

	for (int i = 0; i < length; i++)
	{
		sum += input[i];
	}

	return double(sum) / double(length);
}


/*	Function: int getFileLength(string target);
*	Pre: A string containing the relative path to a file to get the length of.
*	Post: An int representing how many lines the file contains.
*	Purpose: Get the amount of lines that a file contains for the purpose of array management.
*********************************************************/
int getFileLength(string target)
{
	ifstream fileIN;

	int length = 0;

	string line; // We don't use this for anything but getline needs somewhere to put stuff.

	fileIN.open(target.c_str(), ios::in);

	while (getline(fileIN, line))
	{
		length++;
	}

	fileIN.close();

	return length;
}


/*	Function: vector<entry> getTop10(vector<entry> dataset)
*	Pre: A vector containing the dataset to analyse.
*	Post: A vector containing the entries of the top 10 days in terms
*	of new infections.
*	Purpose: Get the top 10 days by infections.
*********************************************************/
vector<entry> getTop10(vector<entry> dataset)
{
	vector<entry> output;

	int
		index = 0,
		largest = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < dataset.size(); j++)
		{
			// WRONG. This should be in the loop above.
			index = 0;
			largest = 0;

			if (dataset[j].infections > largest)
			{
				largest = dataset[j].infections;
				index = j;
			}
		}

		output.push_back(dataset[index]);
		dataset.erase(dataset.begin() + index);
	}

	return output;
}


/*	Function: entry parseLine(string line)
*	Pre: A string containing the line to parse. Should be formatted like: YYYY-MM-DD INFECTIONS DEATHS
*	Post: Returns an entry struct containing the data on the supplied line.
*	Purpose: Parse and return the data in any given properly fomatted line.
*********************************************************/
entry parseLine(string line)
{
	entry output;

	size_t
		foundAt,
		last = 0;

	// We only need to extract 3 chunks of data so getting this to work with a loop would be more trouble than it's worth.
	foundAt = line.find('\t', 0);

	// Extract date
	output.date = line.substr(last, foundAt);
	last = foundAt + 1;

	// Extract infections
	foundAt = line.find('\t', last);
	output.infections = stoi(line.substr(last, foundAt - last));
	last = foundAt + 1;

	// Extract deaths
	foundAt = line.find('\t', last);
	output.deaths = stoi(line.substr(last, foundAt - last));

	return output;
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


/*	Function: vector<entry> readData(string target)
*	Pre: A string containing the relative path to the file containing the data to read.
*	This file should already be confirmed to exist.
*	Post: Returns a vector containing a entry struct for every entry in the dataFile.
*	Purpose: Read and return the data entries from the target file.
*********************************************************/
vector<entry> readData(string target)
{
	vector<entry> data;

	ifstream dataIN;

	string line;

	dataIN.open(target.c_str(), ios::in);

	while (getline(dataIN, line))
	{
		data.push_back(parseLine(line));
	}

	return data;
}


/*	Function: void readData(string target, int length, entry output[])
*	Pre: A string containing the relative path of the file to read from,
*	the amount of lines that the target file has and an array to store data in
*	that is the same length as the length parameter.
*	Post: The output array will be populated with the data from the target file.
*	Purpose: Read data from the target file and store it in an array.
*********************************************************/
void readData(string target, int length, entry output[])
{
	ifstream dataIN;

	string line;

	int i = 0;

	dataIN.open(target.c_str(), ios::in);

	if (getline(dataIN, line) && i < length)
	{
		do
		{
			output[i] = parseLine(line);
			i++;
		} while (getline(dataIN, line) && i < length);
	}
}


/*	Function: bool writeData(string target, double avgcases, double avgDeaths, vector<entry> top10)
*	Pre: A string containing the relative path to the target file, a double containing the average cases per day,
*	another double containing the average deaths per day and a vector containing the entries for the top 10 most infectious days.
*	Post: The supplied data will be written to the target file. Any data already in the target file will be truncated, so if the target
*	file already exists make sure to check that the user is okay with it being overwriten.
*	Purpose: Format and output the supplied data to a file and return a boolean representing whether or not the operation was successful.
*********************************************************/
bool writeData(string target, double avgCases, double avgDeaths, vector<entry> top10)
{
	ofstream dataOUT;

	// Open and truncate file.
	dataOUT.open(target.c_str(), ios::out | ios::trunc);

	// Check that the file was opened properly.
	if (dataOUT.bad() || dataOUT.fail()) { return false; }

	// Set precision.
	dataOUT << fixed << setprecision(3);

	// Write average infection data.
	dataOUT << "Average infections: " << avgCases << endl;

	// Write average death data.
	dataOUT << "Average deaths: " << avgDeaths << endl << endl;

	// Write top 10 days by infections.
	dataOUT << "Top 10 days by number of infections:\n";

	for (int i = 0; i < 10; i++)
	{
		entry date = top10[i];

		dataOUT << i + 1 << ". " << date.date << " " << date.infections << " infections " << date.deaths << " deaths\n";
	}

	// Close file.
	dataOUT.close();

	return true;
}
