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


#include <iostream>

#include "header.h"
#include <string>


using namespace std;
int main()
{
	string
		dataFile,
		outputFile;

	vector<entry> data;
	vector<entry> top10;

	vector<int> cases;
	vector<int> deaths;

	double
		avgCases,
		avgDeaths;

	bool overwrite = false;

	dataFile = promptInputFile();
	// Exit if NUL is returned.
	if (dataFile == "NUL")
	{
		return 0;
	}

	data = readData(dataFile);

	// Fill cases and deaths vectors.
	for (int i = 0; i < data.size(); i++)
	{
		cases.push_back(data[i].infections);
		deaths.push_back(data[i].deaths);
	}

	// Get averages.
	avgCases = getAverage(cases);
	avgDeaths = getAverage(deaths);

	// Get top 10.
	top10 = getTop10(data);

	outputFile = promptOutputFile();
	if (outputFile == "NUL")
	{
		return 0;
	}

	if (!writeData(outputFile, avgCases, avgDeaths, top10))
	{
		cout << "Failed to write to output file.\n";
		return -1;
	}
	else
	{
		cout << "Data written to output file!\n";
		return 0;
	}
}
