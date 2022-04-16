#pragma once
#include <iostream>
using namespace std;

struct job {

	char priority;
	int arrivalT;
	int processT;
};

struct queue {
	job data; 
	queue* next;
};
