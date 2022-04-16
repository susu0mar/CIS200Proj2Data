#pragma once
//Processor.h
#pragma once
#include "header.h"
class Processor
{
private:
	job currentJob;
	int jobCount = 0;
public:
	Processor();
	void push(job inputJob);
	job pop();
	bool isEmpty();
	bool isFull();
	bool isComplete();
	void processJobOne();
	job peekJob() { return currentJob; }
	Processor();

};