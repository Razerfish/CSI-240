/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: Lab 1
Date Assigned: February 2 2021
Due Date: February 8 2021
Description: Create, populate and manipulate a 4x5 array.
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
	const int
		ROWS = 4,
		COLS = 5;

	const int SEARCHFOR = 5;

	// Create array.
	int** numbers;
	numbers = new int *[ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		numbers[i] = new int[COLS];
	}

	populateArray(ROWS, COLS, numbers);

	displayArray(ROWS, COLS, numbers);

	divisibleByN(SEARCHFOR, ROWS, COLS, numbers);

	processArray(ROWS, COLS, numbers);

	displayArray(ROWS, COLS, numbers);
}
