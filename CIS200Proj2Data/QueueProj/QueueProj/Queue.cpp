#include <iostream>
#include "QueueClass.h"
using namespace std;


template<class type>
inline Queue<type>::Queue()
{
	//making initial linked list with size 0, and null pointers
	front = NULL;
	back = NULL;
	size = 0;
}

template<class type>
inline void Queue<type>::enqueue(type x)
{
	queueNode* temp = new queueNode;
	//delete temp; TODO: move to right place
	temp->data = x;
	if (back == NULL) {
		back = temp;
		front = temp;
		return;
	}

	back->next = temp;
	back = temp; //not sure if this is right******
	size++;

}

template<class type>
inline void Queue<type>::dequeue()
{
	if (front == NULL) {

		return;
	}
	//deleting first node(front node)
	queueNode* temp = front;
	front = front->next;
	if (front == NULL) {
		back == NULL;
	}
	delete temp;
	size--;
}

template<class type>
inline bool Queue<type>::isEmpty()
{
	if (size == 0) {
		return true;
	}
	else
		return false;

}

template<class type>
inline type Queue<type>::value()
{
	return front->data;
}

template<class type>
inline void Queue<type>::addFront(type x)
{

	queueNode* temp = new queueNode;
	temp->data = x;
	temp->next = front;
	front = temp; //front is now the new node!

}