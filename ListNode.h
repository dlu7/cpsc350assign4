#include <iostream>
using namespace std;

template <class T>
class ListNode
{
public:
	T data;
	ListNode<T> *next;
	ListNode<T> *prev;

	ListNode()
	{
		//empty
	};

	~ListNode();
	ListNode(T data);
};

template <class T>
ListNode<T>::~ListNode()
{
	if (next != NULL)
	{
		next = NULL;
		prev = NULL;

		delete next;
		delete prev;
	}
}

template <class T>
ListNode<T>::ListNode(T d)
{
	data = d;
	next = NULL;
	prev = NULL;
}

