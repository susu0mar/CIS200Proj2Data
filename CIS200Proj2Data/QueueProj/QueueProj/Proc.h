#pragma once
//Processor.h
#pragma once
#include "header.h"

class CPU {
public:
	unsigned int idletime; //maybe make unsigned
	unsigned int runningtime;//maybe make unsigned
	int totaljobsCompleted;
	bool isProcessing;
	int timecount;
	job currentJob;

	//functions for CPU

    //default constructor
    CPU() {

        idletime = 0;
        runningtime = 0;
        totaljobsCompleted = 0;
        isProcessing = false;
        timecount = 0;

    }

    //check if job is complete
    bool isJobComplete()
    {
        if (timecount == currentJob.processT)
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
    }

    //add run time total in main 
    void execution() {
        ++timecount;
        if (isProcessing) {
            ++runningtime;
        }
        else {
            ++idletime;
        }
    }



};
