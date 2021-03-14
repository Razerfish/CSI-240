/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: Lab 4
Date Assigned: March 8 2021
Due Date: March 15 2021
Description: Create a dynamic array of Student objects.
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


/*	Functoin: void display(int size, Student* ptr);
*	Pre: The length of the array and a dynamic array of student entries.
*	Post: The data from the array will be displayed in the console.
*	Purpose: Display the data in the array.
*********************************************************/
void display(int size, Student* ptr)
{

}


/*	Function: void populate(int size, string filename, Student* ptr);
*	Pre: Provide the amount of entries to load, the file to load from and
*	the dynamic array to load them into.
*	Post: The provided array will be populated with the specified amount of
*	entries from the specified file.
*	Purpose: Populate an array with data from a file.
*********************************************************/
void populate(int size, string filename, Student* ptr)
{
	ifstream din;

	din.open(filename.c_str());

	for (int i = 0; i < size; i++)
	{
		din >> ptr[i];
	}

	din.close();
}


/*	Function: int promptSize();
*	Pre: None.
*	Post: Returns a number between 1 and 1000 indicating how many entries to read
*	into memory.
*	Purpose: Get the amount of entries to load.
*********************************************************/
int promptSize()
{
	int size;
	string line;

	cout << "Input the amount of entries to load (1-1000): ";

	getline(cin, line);

	// Attempt to convert the input to an int. Set the size to -1 if the conversion fails.
	try
	{
		size = stoi(line);
	}
	catch (invalid_argument)
	{
		size = -1;
	}

	while (size < 1 || size > 1000)
	{
		cout << "Invalid input. Enter a number between 1 and 1000: ";
		getline(cin, line);

		// Same method of attempting conversion as above.
		try
		{
			size = stoi(line);
		}
		catch (invalid_argument)
		{
			size = -1;
		}
	}

	return size;
}


/*	Function: void sort(int size, Student *ptr);
*	Pre: The length of an array and the array to sort.
*	Post: The array will be sorted in ascending order based
*	on student ID numbers.
*	Purpose: Sort an array of students.
*********************************************************/
void sort(int size, Student* ptr)
{

}
