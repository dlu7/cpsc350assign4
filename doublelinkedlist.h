#include <iostream>
#include "ListNode.h"
using namespace std;

template <class D>
class DoubleLL
{
public:
	ListNode<D> *front;
	ListNode<D> *back;
	unsigned int size;

	DoubleLL();
	~DoubleLL()
	{
		//empty
	};

	void insertBack(D d);
	D removeFront();
	D getFront()
		return front->data;

	void removePos(int pos);

	void printList();

	unsigned int getSize()
		return size;

	bool isEmpty()
		return (size == 0);
};

template <class D>
DoubleLL<D>::DoubleLL()
{
	front = NULL;
	back = NULL;
	size = 0;
}

template <class D>
void DoubleLL<D>::insertBack(D d)
{
	ListNode<D> *node = new ListNode<D>(d);

	if (size == 0)
		front = node;
	else
	{
		back->next = node;
		node->prev = back;
	}
	back = node;
	++size;
}

template <class D>
D DoubleLL<D>::removeFront()
{
	if (!isEmpty())
	{
		ListNode<D> *prevFront = front;
		D node = prevFront->data;

		if (front->next) == NULL)
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
		return D();
}

template <class D>
void DoubleLL<D>::removePos(int pos)
{
	int position = 0;
	ListNode *curr = front;
	ListNode *prev = front;

	while (position != pos)
	{
		prev = curr;
		curr = curr->next;
		position++;
	}

	prev->next = curr->next;
	curr->next->prev = prev;
	curr->next = NULL;
	curr->prev = NULL;
	curr->data = NULL;

	size--;
	delete curr;
}

template <class D>
void DoubleLL<D>::printList()
{
	ListNode<D> *curr = front;

	while (true)
	{
		if (curr->next == NULL)
			break;

		cout << curr->data << endl;
		curr = curr->next;
	}
}