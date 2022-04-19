#pragma once
#include <iostream>
using namespace std;

struct job {

	char priority;
	int arrivalT;
	int processT;
	//count??
};

//jobmetrics() - function??


//make 2 seperate instances for priority?
template<class type> class Queue{
struct queueNode {
	type data;
	queueNode* next;
};

private: 
	queueNode* front;
	queueNode* back; //why is back needed?


public:
	int size; //total size of queue
	Queue();
	void enqueue(type x);
	void dequeue();
	bool isEmpty();
	type value(); //like a peek function to see front of queue
	void addFront(type x);
	//maybe here or in main, write conditional to check type of job in cpu to determine priority


};

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


//not sure if it works
template<class type>
inline void Queue<type>::addFront(type x)
{

	queueNode* temp = new queueNode;
	temp->data = x;
	temp->next = front;
	front = temp; //front is now the new node!


}






