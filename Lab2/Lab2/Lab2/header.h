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

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "covid.h"

using namespace std;

// Max length of the covid data array.
const int MAXLENGTH = 250;

bool fileAvailable(string file);

void initializeArray(covid arr[], int length);

covid parseLine(string line);

void populateArray(covid arr, int length, string file);
