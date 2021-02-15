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

using namespace std;
int main()
{
	//covid data[MAXLENGTH];
	covid* data = new covid[MAXLENGTH];

	initializeArray(data, MAXLENGTH);

	populateArray(data, MAXLENGTH, "data.txt");

	cout << getGlobalCaseRate(data, MAXLENGTH) << endl;
	cout << getGlobalDeathRate(data, MAXLENGTH) << endl;

	for (int i = 0; i < MAXLENGTH; i++)
	{
		getLocalCaseRate(data[i]);
		getLocalDeathRate(data[i]);
	}

	cout << data[10].pctCases << endl << data[10].pctDeaths << endl;

	saveOutput(data, MAXLENGTH, "output.txt");

	delete[] data;

	return 0;
}
