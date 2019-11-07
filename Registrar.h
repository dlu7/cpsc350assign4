#include <iostream>
#include "Student.h"
#include "Queue.h"
#include <string>
using namespace std;

class Registrar
{
public:
	Registrar();
	~Registrar();

	bool infile(string file);
	bool timer(int t);

	double waitingMean();
	double waitingMedian();
	int longestWait();
	int wOverTen();

	double idleMean();
	int longestIdle();
	int iOverFive();

	Student* *wArray;

	Queue<Student*> studentQueue;

	Queue<int> waitList;
	Queue<int> idleList;

	int *mArray;
	int *iArray;

	int windows;
	int students;

private:
	int typeOfLine;
	int entryTime;
	int windowTime;
	int numAtClock;
	int mArraycount;
	int iArraycount;
};
