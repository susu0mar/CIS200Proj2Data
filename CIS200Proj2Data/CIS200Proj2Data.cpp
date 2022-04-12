// CIS200Proj2Data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
using namespace std;
/*INFO: 2,300 A jobs
1,700 B jobs
950 C jobs
620 D jobs*/
struct job {

	char priority;
	int arrivalT;
	int processT;

};

int main()
{
	ofstream dataFile;
	dataFile.open("Data file.txt");
	job a[100];
	if (dataFile.fail()) {

		cout << "Error: unable to open file" << endl;

	}
	//creating data for type a jobs
	//i think create at array with these values, then adjust the arrival time based on previous arrival time (so like prev arrival + arrival) to get actual arrival tiem
	for (int i = 0; i < 100; ++i){
	
		a[i] = { 'A', 4 + rand() % 3, 1 + rand() % 5 };
	
	}



	// adding arrival time to previous arrival time (cause cumulative)
	
	for (int i = 1, j=0; i < 100 && j<99; ++i, ++j) {
	
		a[i].arrivalT += a[j].arrivalT;

	}

	

	job b[100];

	//creating data for type b jobs 
	for (int i = 0; i < 100; ++i) {
	
		b[i] = { 'B',6 + rand() % 3 , 2 + rand() % 10};
	}
	for (int i = 1, j = 0; i < 100 && j<99; ++i, ++j) {
	
	
		b[i].arrivalT += b[j].arrivalT;
	}
	

	job mergeAB[200];

	for (int i = 0; i < 100; ++i) {
	
		mergeAB[i] = a[i];

	}

	for (int i = 100 , k = 0; i < 200, k < 100; i++, k++) {
		mergeAB[i] = b[k];
	}

	job c[100];
	//creating data for type c jobs

	for (int i = 0; i < 100; ++i) {
	
		c[i] = { 'C',8 + rand() % 10, 6 + rand() % 6};

	}
	for (int i = 1, j = 0; i < 100 && j < 99; ++i, ++j) {


		c[i].arrivalT += c[j].arrivalT;
	}

	job d[100];
	//creating data for type d jobs

	for (int i = 0; i < 100; ++i) {
	
		d[i] = { 'D',14 + rand() % 10, 9 + rand() % 8};
	}
	for (int i = 1, j = 0; i < 100 && j < 99; ++i, ++j) {


		d[i].arrivalT += d[j].arrivalT;
	}

	//merging c and d data
	job mergeCD[200];

	for (int i = 0; i < 100; ++i) {

		mergeCD[i] = d[i];

	}

	for (int i = 100, k = 0; i < 200, k < 100; i++, k++) {
		mergeCD[i] = c[k];
	}



	//finally, combining CD and AB arrays together 
	//then fully sort after?
	job fullMerge[400];
	for (int i = 0; i < 200; ++i) {

		fullMerge[i] = mergeCD[i];

	}
	for (int i = 200, k = 0; i < 400, k < 200; i++, k++) {
		fullMerge[i] = mergeAB[k];
	}
	cout << "FULL ARRAY UNSORTED"<<endl;
	for (int i = 0; i < 400; ++i) {

		cout << fullMerge[i].priority << "  " << fullMerge[i].arrivalT << "   " << fullMerge[i].processT << endl;

	}



	//sort ascending order with arrival time
	for (int i = 0; i < 400; i++) {
	
		for (int j = i + 1; j < 400; j++) {
		
			if (fullMerge[i].arrivalT > fullMerge[j].arrivalT) {
				
				job temp = fullMerge[i];
				fullMerge[i] = fullMerge[j];
				fullMerge[j] = temp;
			
			}
		}
	}

	//sort the "sorted" with priority included
	for (int i = 0; i < 400; i++) {

		for (int j = i + 1; j < 400; j++) {

			if (fullMerge[i].arrivalT == fullMerge[j].arrivalT && fullMerge[i].priority < fullMerge[j].priority) {

				job temp = fullMerge[i];
				fullMerge[i] = fullMerge[j];
				fullMerge[j] = temp;

			}
		}
	}

	cout << "FULL ARRAY SORTED" << endl;
	for (int i = 0; i < 400; ++i) {

		cout << fullMerge[i].priority << "  " << fullMerge[i].arrivalT << "   " << fullMerge[i].processT << endl;

	}

}








