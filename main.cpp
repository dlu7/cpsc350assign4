#include <iostream>
#include "Registrar.h"
using namespace std;

int main(int argc, char** argv)
{
	Registrar r;

	int ctime = 0;
	int p = 0;
	bool inProgress = true;

	if (argc < 2)
		cout << "File not valid! Please try again." << endl;
		
	else if (argc >= 2)
	{
		string file = argv[1];
		if (r.infile(file))
		{
			while (inProgress)
			{
				if (r.studentQueue.isEmpty())
				{
					for (int i = 0; i < r.windows; ++i)
					{
						if ((r.wArray[i]->timeWindow < 1))
							p++;
					}
				}
				if (p == r.windows)
					inProgress = false;
			}
			for (int i = 0; i < r.windows; ++i)
			{
				if (r.wArray[i]->timeWindow < 1)
				{
					if (!r.studentQueue.isEmpty())
					{
						Student* stud = r.studentQueue.FrontOfQueue();

						if (stud->timeEntry <= ctime)
						{
							if (r.wArray[i]->timeIdle > 0)
								r.idleList.enqueue(r.wArray[i]->timeIdle);
						}

						r.wArray[i] = r.studentQueue.dequeue();

						r.waitList.enqueue(r.wArray[i]->timeQueue);
					}
				}
			}
			//tracking all times
			ctime++;
			r.timer(ctime);
		}
		for (int i = 0; i < r.windows; ++i)
		{
			if (r.wArray[i]->timeIdle > 0)
				r.idleList.enqueue(r.wArray[i]->timeIdle);
		}
		//printing data
		cout << "Calculations for the Student Waiting Times" << endl;
		cout << "The meean student wait time is: " << r.waitingMean() << endl;
		cout << "The median student wait time is: " << r.waitingMedian() << endl;
		cout << "The longest student wait time is: " << r.longestWait() << endl;
		cout << "The number of waits that were over 10 minutes is: " << r.wOverTen() << endl;
		cout << "The mean window idle time is: " << r.idleMean() << endl;
		cout << "The longest window idle time is: " << r.longestIdle() << endl;
		cout << "The number of idle times that were over 5 minutes is: " << r.iOverFive() << endl;
	}
	return 0;
}

