#include <iostream>
using namespace std;

class Student
{
public:
	Student();
	~Student();
	Student(int window, int entry);

	int timeWindow;
	int timeEntry;
	int timeQueue;
	int timeIdle;
};