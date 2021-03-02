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
#include <iostream>

/*	Function: void displayArray(int rows, int cols, int** arr)
*	Pre: A populated 2D pointer-pointer array with rows equal to
*	the parameter "rows" and columns equal to the parameter "cols".
*	Post: The contents of the array will be output to the console.
*	Purpose: Display the contents of a given array.
*********************************************************/
void displayArray(int rows, int cols, int** arr)
{
	// The length of the maximum value.
	const int MAXLENGTH = 3;

	// Loop through array.
	for (int i = 0; i < rows; i++)
	{
		cout << "  ";
		for (int j = 0; j < cols; j++)
		{
			cout << setw(MAXLENGTH) << right << arr[i][j];

			// Add comma and space if not last in column.
			if (j + 1 < cols)
			{
				cout << ", ";
			}
		}
		cout << endl;
	}
	cout << endl;
}


/*	Function: void divisibleByN(int n, int rows, int cols, int** arr)
*	Pre: The number to check divisibility of, and a populated 2D pointer-pointer
*	integer array with rows equal to the parameter "rows" and columns equal to the
*	parameter "cols".
*	Post: The occurance of entries in the array that are evenly divisible by n will be
*	output to the console.
*	Purpose: Count the amount of entries in an array that are evenly divisible by n.
*********************************************************/
void divisibleByN(int n, int rows, int cols, int** arr)
{
	int count = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] % n == 0)
			{
				count++;
			}
		}
	}

	// Just a little grammer pedantry because I'm weird like that.
	if (count == 1)
	{
		cout << "There is 1 entry that is evenly divisible by " << n << ".\n";
	}
	else
	{
		cout << "There are " << count << " entries that are evenly divisible by " << n << ".\n\n";
	}
}


/*	Function: void populateArray(int row, int cols, int** arr)
*	Pre: An uninitialized 2D pointer-pointer integer array with an amount of rows
*	equal to the "rows" paramter and an amount of columns equal
*	to the "cols" parameter.
*	Post: The given array will be populated with random numbers
*	between 0 and 100.
*	Purpose: Fill the empty array with random numbers.
*********************************************************/
void populateArray(int rows, int cols, int** arr)
{
	const int MAX = 100; // Max value.

	// Seed random number generator.
	srand(time(NULL));

	// Loop through array.
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (MAX + 1);
		}
	}
}


/*	Function: void ProcessArray(int rows, int cols, int** arr)
*	Pre: A populated 2D pointer-pointer integer array with rows
*	equal to the "rows" parameter and columns equal to the "cols" parameter.
*	Post: Even columns will be sorted in descending order and odd columns
*	will be sorted in ascending order.
*	Purpose: Sort the columns of the given array in an alternating order.
*********************************************************/
void processArray(int rows, int cols, int** arr)
{
	// Loop through array.
	for (int i = 0; i < cols; i++)
	{
		// If odd sort ascending.
		if ((i + 1) % 2 != 0)
		{
			sortAscending(rows, cols, arr, i);
		}
		else // Otherwise sort descending
		{
			sortDescending(rows, cols, arr, i);
		}
	}
}


/*	Function: void sortAscending(int rows, int cols, int** arr, int targetCol)
*	Pre: A 2D pointer-pointer integer array with rows equal to the "rows" parameter
*	and columns equal to the "cols" parameter and the target column to sort.
*	Post: The target column will be sorted in ascending order.
*	Purpose: Sort a given column in a 2D array in ascending order.
*********************************************************/
void sortAscending(int rows, int cols, int** arr, int targetCol)
{
	// The code for this function was adapted from here: https://www.geeksforgeeks.org/bubble-sort/
	bool swapped;

	for (int i = 0; i < rows - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < rows - i - 1; j++)
		{
			if (arr[j][targetCol] > arr[j + 1][targetCol])
			{
				swap(&arr[j][targetCol], &arr[j + 1][targetCol]);
				swapped = true;
			}
		}

		// If we didn't swap anything then we know that we're done.
		if (!swapped)
		{
			break;
		}
	}
}


/*	Function: void sortDescending(int rows, int cols, int** arr, int targetCol)
*	Pre: A 2D pointer-pointer integer array with rows equal to the "rows" parameter
*	and columns equal to the "cols" parameter and the target column to sort.
*	Post: The target column will be sorted in descending order.
*	Purpose: Sort a given column in a 2D array in descending order.
*********************************************************/
void sortDescending(int rows, int cols, int** arr, int targetCol)
{
	// The code for this function was adapted from here: https://www.geeksforgeeks.org/bubble-sort/
	bool swapped;

	for (int i = 0; i < rows - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < rows - i - 1; j++)
		{
			if (arr[j][targetCol] < arr[j + 1][targetCol])
			{
				swap(&arr[j][targetCol], &arr[j + 1][targetCol]);
				swapped = true;
			}
		}

		// If we didn't swap anything then we know that we're done.
		if (!swapped)
		{
			break;
		}
	}
}


/*	Function: void swap(int* var1, int* var2)
*	Pre: Two variables.
*	Post: The values of the variables will be swapped.
*	i.e. var1 will equal var2 and var2 will equal var1.
*	Purpose: Swap the values of variables for sorting purposes.
*********************************************************/
void swap(int* var1, int* var2)
{
	// The code for this function has been adapted from here: https://www.geeksforgeeks.org/bubble-sort/
	int tmp = *var1;

	*var1 = *var2;
	*var2 = tmp;
}
