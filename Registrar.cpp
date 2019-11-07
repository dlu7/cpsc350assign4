#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Registrar.h"
using namespace std;

Registrar::Registrar()
{
	typeOfLine = 1;
	entryTime = 0;
	windowTime = 0;
	numAtClock = 0;

	mArraycount = 0;
	iArraycount = 0;

	windows = 0;
	students = 0;
}

Registrar::~Registrar()
{
	delete[] wArray;
	delete[] mArray;
	delete[] iArray;
}

bool Registrar::infile(string file)
{
	string str;
	int line = 1;

ifstream input;
input.open(file.c_str());

if (input.is_open())
{
	try
	{
		getline(input, str);
		windows = stoi(str);

		wArray = new Student*[windows];

		for (int i = 0; i < windows; ++i)
		{
			Student* S = new Student();
			wArray[i] = S;
		}
		line++;
	}
	catch (exception e)
	{
		cout << endl << "There is an error on line #" << line << endl;
		return false;
	}

	while (getline(input, str))
	{
		switch (typeOfLine)
		{
			//timing of the clock
		case(1):
		{
			try
			{
				entryTime = stoi(str);

				typeOfLine++;
				line++;
			}
			catch (exception e)
			{
				cout << endl << "There is an error on line #" << line << endl;
				return false;
			}
			break;
		}
		//number of students in the queue
		case(2):
		{
			try
			{
				if (str != "")
				{
					numAtClock = stoi(str);

					for (int i = 0; i < numAtClock; ++i)
					{
						getline(input, str);
						line++;

						try
						{
							windowTime = stoi(str);
						}
						catch (exception e)
						{
							cout << endl << "There is an error on line #" << line << endl;
							return false;
						}
						students++;
						Student* S = new Student(windowTime, entryTime);

						studentQueue.enqueue(S);
					}

					typeOfLine = 1;
				}
			}
			catch (exception e)
			{
				cout << endl << "There is an error on line #" << line << endl;
				return false;
			}
			break;
		}
		default: break;
		}
	}
}
else
return false;

return true;
}

bool Registrar::timer(int t)
{
	for (int i = 0; i < windows; ++i)
	{
		if (wArray[i]->timeWindow > 0)
		{
			wArray[i]->timeWindow--;
		}
		else
		{
			wArray[i]->timeIdle++;
		}
	}

	if (!studentQueue.isEmpty())
	{
		ListNode<Student*> *curr = studentQueue.front;

		while (curr != NULL)
		{
			if (curr->data->timeEntry < t)
			{
				curr->data->timeQueue += 1;
			}
			curr = curr->next;
		}
	}

	return true;
}

double Registrar::waitingMean()
{
	ListNode<int> *curr = waitList.front;

	double waitMean = 0;
	double sum = 0;
	int count = 0;

	while (curr != NULL)
	{
		sum += curr->data;
		curr = curr->next;
		count++;
	}

	if (count == 0)
		return 0;

	waitMean = sum / double(count);

	return waitMean;
}

double Registrar::waitingMedian()
{
	ListNode<int> *curr = waitList.front;

	double waitMed = 0;
	mArraycount = 0;

	while (curr != NULL)
	{
		curr = curr->next;
		mArraycount++;
	}

	if (mArraycount == 0)
		return 0;
	else
	{
		mArray = new int[mArraycount];
		curr = waitList.front;

		for (int i = 0; i < mArraycount; ++i)
		{
			mArray[i] = curr->data;
			curr = curr->next;
		}

		sort(mArray, mArray + mArraycount);
		
		if (mArraycount % 2 == 1)
		{
			double a = 0;
			int b = 0;

			b = (mArraycount / 2) + 1;
			a = mArray[b];

			return a;
		}
		else
		{
			double c = 0;
			int d = 0;
			int e = 0;

			d = mArraycount / 2;
			e = (mArraycount / 2) + 1;

			if (mArray[e] == 0)
				return 0;

			c = double(mArray[d]) / double(mArray[e]);

			return c;
		}
	}
}

int Registrar::longestWait()
{
	if (mArraycount == 0)
		return 0;
	else
		return mArray[mArraycount - 1];
}

int Registrar::wOverTen()
{
	if (mArraycount != 0)
	{
		int t = 0;

		for (int i = 0; i < mArraycount; ++i)
		{
			if (mArray[i] > 10)
				++t;
		}
		return t;
	}
	else
	{
		return 0;
	}
}

double Registrar::idleMean()
{
	ListNode<int> *curr = idleList.front;

	double idleMean = 0;
	double sum = 0;
	int count = 0;

	while (curr != NULL)
	{
		sum += curr->data;
		curr = curr->next;
		count++;
	}

	if (count == 0)
		return 0;

	idleMean = sum / double(count);

	return idleMean;
}

int Registrar::longestIdle()
{
	ListNode<int> *curr = idleList.front;
	iArraycount = 0;

	while (curr != NULL)
	{
		curr = curr->next;
		iArraycount++;
	}

	iArray = new int[iArraycount];
	curr = idleList.front;

	for (int i = 0; i < iArraycount; ++i)
	{
		iArray[i] = curr->data;
	}

	sort(iArray, iArray + iArraycount);
	return (iArray[iArraycount - 1]);
}

int Registrar::iOverFive()
{
	int t = 0;

	for (int i = 0; i < iArraycount; ++i)
	{
		if (iArray[i] > 5)
		{
			++t;
		}
	}
	return t;
}
