/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: PA3 - Part 3
Date Assigned: March 26 2021
Due Date: April 5 2021
Description: Make a banking system
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

#ifndef _BANKING_H
#define _BANKING_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>

#include "account.h"
#include "customer.h"
#include "employee.h"
#include "teller.h"

using namespace std;

// commonFunctions.cpp

void clearScreen();
bool convertStr2Double(string stringValue, double& doubleValue);
void displayLogo();
void displayMessage(int errorCode);
string mainMenu();
void systemPause();
string toUpper(string stringValue);

#endif
