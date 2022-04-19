#pragma once

class CPU {
public:
	unsigned int idletime; //maybe make unsigned
	unsigned int runningtime;//maybe make unsigned
	int totaljobsCompleted;
	bool isProcessing;
	int timecount;//maybe make unsigned
	totaljob currentJob;
	//Function that measures individual cpu idle time MAIN
	// write to log file in main when processing the data	

	CPU() {

		idletime = 0;
		runningtime = 0;
		totaljobsCompleted = 0;
		isProcessing = false;
		timecount = 0;

	}

	//function for incrementing the idle time and  running time
	void execution() {
		++timecount;
		if (isProcessing) {
			++runningtime;
		}
		else {
			++idletime;
		}
	}
	//add up the run the time total in main with a CPU object

	bool isJobComplete()
	{
		if (timecount == currentJob.data.processT)
		{
			totaljobsCompleted++;
			timecount = 0;
			isProcessing = false;
			return true;
		}
		else
		{
			return false;
		}
		//function put old function back in with new runtime 
	}

	////Adds an item to the stack
	//void push(totaljob inputJob)
	//{
	//	if (jobCount == 0) {
	//		currentJob = inputJob;
	//		jobCount++;
	//	}
	//}

	////Removes an item from the stack
	//job pop()
	//{
	//	job tempJob = currentJob;
	//	currentJob = {};
	//	jobCount--;
	//	return tempJob;
	//}
	////Returns true when the stack is empty
	//bool isEmpty()
	//{
	//	if (jobCount == 0) {
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}
	//}
	////Returns true when the stack is full(max of 1)
	//bool isFull()
	//{
	//	if (jobCount == 1) {
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}
	//}//Returns true when job in the processor has 0 time remaining

	totaljob peekJob() { return currentJob; }
	~CPU();
};



