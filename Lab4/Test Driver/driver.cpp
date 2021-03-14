#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Lab4/student.h"
#include "Lab4/header.h"

using namespace std;

const string DATA_FILE = "../Lab4/data.txt";

int main()
{
	int size = promptSize();
	cout << size << endl;

	Student* school = new Student[size];

	populate(size, DATA_FILE, school);

	display(size, school);

	delete[] school;

	return 0;
}
