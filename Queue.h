#include <iostream>
#include "ListNode.h"
using namespace std;

template <class Q>
class Queue
{
public:
	ListNode<Q> *front;
	ListNode<Q> *back;
	unsigned int size;

	Queue();
	~Queue()
	{
		//empty
	};

	void enqueue(Q d);
	Q dequeue();

	Q FrontOfQueue();
	Q BackOfQueue();
	void printQueue();
	unsigned int getSize();

	bool isEmpty();
};

template <class Q>
Queue<Q>::Queue()
{
	size = 0;
	front = NULL;
	back = NULL;
}

template <class Q>
void Queue<Q>::enqueue(Q d)
{
	ListNode<Q> *node = new ListNode<Q>(d);

	//checking to see if queue is empty
	if (size == 0)
	{
		front = node;
	}
	else
	{
		back->next = node;
		node->prev = back;
	}
	back = node;
	size++;
}

template <class Q>
Q Queue<Q>::dequeue()
{
	if (!isEmpty())
	{
		ListNode<Q> *prevFront = front;
		Q node = prevFront->data;

		if (front->next == NULL)
		{
			front = NULL;
			back = NULL;
		}
		else
		{
			front->next->prev = NULL;
			front = front->next;
		}
		delete prevFront;
		size--;
		return node;
	}
	else
	{
		return Q();
	}
}

template <class Q>
Q Queue<Q>::FrontOfQueue()
{
	return front->data;
}

template <class Q>
Q Queue<Q>::BackOfQueue()
{
	return back->data;
}

template <class Q>
void Queue<Q>::printQueue()
{
	ListNode<Q> *curr = front;

	while (true)
	{
		if (curr == NULL)
			break;

		cout << curr->data << endl;
		curr = curr->next;
	}
}

template <class Q>
unsigned int Queue<Q>::getSize()
{
	return size;
}

template <class Q>
bool Queue<Q>::isEmpty()
{
	return (size == 0);
}