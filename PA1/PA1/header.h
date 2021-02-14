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


#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


using namespace std;

struct entry
{
	string date = "";
	int infections = 0;
	int deaths = 0;
};


bool fileAvailable(string target);

double getAverage(vector<int> input);
double getAverage(int input[], int length);
int getFileLength(string target);
vector<entry> getTop10(vector<entry> dataset);

entry parseLine(string line);
string promptInputFile();
string promptOutputFile();

vector<entry> readData(string target);
void readData(string target, int length, entry output[]);

bool writeData(string target, double avgCases, double avgDeaths, vector<entry> top10);
