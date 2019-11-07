#include <iostream>
#include "Student.h"
using namespace std;

Student::Student()
{
	timeWindow = 0;
	timeEntry = 0;
	timeQueue = 0;
	timeIdle = 0;
}

Student::~Student()
{

};

Student::Student(int window, int entry)
{
	timeWindow = window;
	timeEntry = entry;
	timeQueue = 0;
	timeIdle = 0;
}