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

#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "student.h"

using namespace std;

void display(int size, Student* ptr);

void populate(int size, string filename, Student* ptr);

int promptSize();

void sort(int size, Student* ptr);

#endif
