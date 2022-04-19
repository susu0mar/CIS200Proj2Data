#include <iostream>
#include <fstream>
#include "JobStruct.h"
#include "Proc.h"
#include "DataFile.cpp"
#include "QueueClass.h"
#include <vector>
using namespace std;


int main()
{
	
	int ProcSize = 4;
	vector<totaljob> exact;
	Queue<totaljob> REGp;

	vector<CPU> Proc(ProcSize);
	int aJobT = 0, bJobT = 0, cJobT = 0; // METRICS to count job types
	int total_jobs = 0; // METRICS to count total
	// what is this here for bool processing;

	//log file stuff
	ofstream log;
	log.open("logFile.txt");
	ifstream DataFile;
	DataFile.open("Data file.txt");
	int maxQueueSize = 0; // what is this for
	int totaltimeproc = 0;
	int totalqueue = 0;
	int totaltimeinqueue = 0;
	int jobsprocessed = 0;
	int overall = 1;
	int job_queue = 0;
	int typeA = 1;  //why 1 and not 0 
	int typeB = 1;
	int typeC = 1;


	while (!DataFile.eof())
	{
		totaljob temp;
		//creating a temp using our struct as template + increasing/tracking count 
		DataFile >> temp.data.priority >> temp.data.arrivalT >> temp.data.processT;
		switch (temp.data.priority)
		{
		case 'A': temp.EachPriorT = typeA++;
			break;
		case 'B': temp.EachPriorT = typeB++;
			break;
		case 'C': temp.EachPriorT = typeC++;
			break;
		}
		temp.PriorSUM = overall++;
		//All values from data file geetin stored into a new array
		exact.push_back(temp);

	}
	DataFile.close(); 


	int runtime = 10000; //why this number
	for (int time = 1; time <= runtime; ++time) {
		for (int i = 0; i < ProcSize; i++)
		{
			Proc.at(i).execution();
			if (Proc.at(i).isProcessing && Proc.at(i).isJobComplete())
			{
				// cout of complete job
				//check if time does not equal the job that is about to leave its arrive time;
				log << "Time " << time << ": Complete Processing Job:" << Proc.at(i).currentJob.PriorSUM << ", Job " <<
					Proc.at(i).currentJob.data.priority << ":" << Proc.at(i).currentJob.EachPriorT << " in CPU " << i + 1 << ";" << endl;;
				// check again for being processing

			}
		}
		//assigning jobs to CPU from queue
		while (!REGp.isEmpty())
		{
			bool isAssigned = false;
			for (int i = 0; i < ProcSize; i++)
			{//This is for when the queue has something waiting to be processed
				//so it just doesn't get used in the queue
				totaltimeinqueue++;
				if (!Proc.at(i).isProcessing)
				{//assigning a job to a CPU 
					Proc.at(i).isProcessing = true;
					Proc.at(i).currentJob = REGp.value();
					REGp.dequeue();
					Proc.at(i).timecount = 0;
					isAssigned = true;

					//cout begin job
					log << "Time " << time << ": " << "Begin Processing Job:" << Proc.at(i).currentJob.PriorSUM << ", Job "
						<< Proc.at(i).currentJob.data.priority << ":" << Proc.at(i).currentJob.EachPriorT << " in CPU " << i + 1 << ";" << endl;


					break;
				}
			}
			if (!isAssigned)
			{
				break;
			}
		}

		// arrivals 
		while (exact.at(0).data.arrivalT == time)
		{
			// cout arrival
			log << "Time " << time << ": " << "Arrival: Overall Job:" << exact.at(0).PriorSUM << ", Job " << exact.at(0).data.priority
				<< ":" << exact.at(0).EachPriorT << ", Processing Time " << exact.at(0).data.processT << ";" << endl;
			//++jobsprocessed;
			bool isAssigned = false;
			//assigning a job to a CPU directly without having being placed in the queue
			for (int i = 0; i < ProcSize; i++)
			{
				++jobsprocessed;
				if (!Proc.at(i).isProcessing)
				{
					// cout begin job
					Proc.at(i).isProcessing = true;
					Proc.at(i).currentJob = exact.at(0);
					Proc.at(i).timecount = 0;
					isAssigned = true;
					log << "Time " << time << ": " << "Begin Processing Job:" << exact.at(0).PriorSUM << ", Job " << exact.at(0).data.priority
						<< ":" << exact.at(0).EachPriorT << " in CPU " << i + 1 << ";" << endl;

					break;
				}
			}
			// put job in queue
			if (!isAssigned)
			{

				++totalqueue;
				REGp.enqueue(exact.at(0));
			}

			//Deleting the job because it was taken care of by either being enqueued or just straight up processed
			exact.erase(exact.begin());
		}


		log << "Time " << time << ": " << "Queue:" << REGp.size << "; ";
		for (int i = 0; i < ProcSize; i++)
		{
			if (Proc.at(i).isProcessing)
			{
				log << "CPU " << i + 1 << " Run Time:" << Proc.at(i).timecount;
			}
			else
			{
				log << "CPU " << i + 1 << " Idle Time:" << Proc.at(i).timecount;
			}
			log << "; ";
		}
		log << endl;



	}
	//Metric
	cout << "Number of Processor(s) being used " << ProcSize << endl;
	cout << "Current queue size: " << REGp.size << endl;
	cout << "Average queue size: " << runtime << endl;//help
	cout << "Maximum jobs in queue: " << job_queue << endl;//help
	cout << "Total time jobs in queue: " << totaltimeinqueue << " time units" << endl;
	cout << "Average time in queue: " << double(totaltimeinqueue) / runtime << " time units " << endl;
	cout << "Total number of jobs A arrived " << typeA << endl;
	cout << "Total number of jobs B arrived " << typeB << endl;
	cout << "Total number of jobs C arrived " << typeC << endl;
	cout << "Total jobs completed: " << jobsprocessed << endl;//help
	cout << "Total time CPU(s) were processing: " << totaltimeproc << " time units" << endl;//help
	cout << "Total time CPU(s) were idle: " << " time units" << endl;//help


	system("pause");
	return 1;

}