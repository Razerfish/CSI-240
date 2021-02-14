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


#pragma once

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

void displayArray(int rows, int cols, int** arr);
void divisibleByN(int n, int rows, int cols, int** arr);

void populateArray(int rows, int cols, int** arr);
void processArray(int rows, int cols, int** arr);

void sortAscending(int length, int* arr);
void sortAscending(int rows, int cols, int** arr, int targetCol);
void sortDescending(int length, int* arr);
void sortDescending(int rows, int cols, int** arr, int targetCol);
void swap(int* var1, int* var2);
