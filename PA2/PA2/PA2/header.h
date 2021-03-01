// Author: Fiona Wilson
// Class: CSI-240-03
// Assignment: PA2
// Date Assigned: February 22 2021
// Due Date: March 1 2021
// Description: Simulate a vending machine.
// Certification of Authenticity:
// I certify that this is entirely my own work, except where I have given fully documented references to the work of others. I understand the definition and
// consequences of plagiarism and acknowledge that the assessor of this assignment
// may, for the purpose of assessing this assignment:
// - Reproduce this assignment and provide a copy to another member of
// academic staff; and/or
// - Communicate a copy of this assignment to a plagiarism checking service
// (which may then retain a copy of this assignment on its database for
// the purpose of future plagiarism checking)

#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <conio.h>
#include <string>

#include "vendingMachine.h"

using namespace std;

void changePassword(VendingMachine& machine);
void checkBalance(VendingMachine& machine);
double collectMoney(VendingMachine& machine);
void createItem(VendingMachine& machine);

void editItem(int index, VendingMachine& machine);

bool isDoubleString(string input);

string promptPassword();

void sellItem(int index, double payment, VendingMachine& machine);

void removeItem(int index, VendingMachine& machine);
void restockItem(int index, VendingMachine& machine);
void restockAll(VendingMachine& machine);

#endif
