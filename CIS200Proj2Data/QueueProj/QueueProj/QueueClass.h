#pragma once
#include <iostream>
using namespace std;

//make 2 seperate instances for priority?
template<class type> 
class Queue{
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








