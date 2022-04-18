#include <iostream>
#include <fstream>
#include "Header.h"
#include "Proc.h"
#include "DataFile.cpp"
#include <vector>
using namespace std;
//hi

//TODO: SIZE OF QUEUE

/* switch (tempJob.jobType)
{
case 'A':
aCount++;
break;
case 'B':
bCount++;
break;
case 'C':
cCount++;
break;
case 'D':
dCount++;
break;
}*/

int main()
{
	
	

	int ProcSize = 4;
	vector<CPU> Proc(ProcSize);
	int aJobT = 0, bJobT = 0, cJobT = 0; // METRICS to count job types
	int total_jobs = 0; // METRICS to count total
	bool processing;
	

	//log file stuff
	fstream log;
	log.open("logFile.txt");
	int maxQueueSize = 0; // what is this for
	int totaltimeproc = 0;
	int totalqueue = 0;
	int totaltimeinqueue = 0;
	int jobsprocessed = 0;
	int overall = 1;
	int job_queue = 0;



	//while //(//data still going )
	//{
	//insert
	//if (fullMerge.priorty == 'D')
	//insert in D linked list


	//else
	//insert in general linked List 
	//}


}