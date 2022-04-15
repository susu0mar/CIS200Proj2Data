// CIS200Proj2Data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
using namespace std;
/*INFO: 2,300 A jobs
1,700 B jobs
950 C jobs
620 D jobs*/
//DONE! 
struct job {

	char priority;
	int arrivalT;
	int processT;

};

int main()
{
	ofstream dataFile;
	dataFile.open("Data file.txt");
	job a[2300];
	if (dataFile.fail()) {

		cout << "Error: unable to open file" << endl;

	}
	//creating data for type a jobs
	//i think create at array with these values, then adjust the arrival time based on previous arrival time (so like prev arrival + arrival) to get actual arrival tiem
	for (int i = 0; i < 2300; ++i){
	
		a[i] = { 'A', 4 + rand() % 3, 1 + rand() % 5 };
	
	}



	// adding arrival time to previous arrival time (cause cumulative)
	
	for (int i = 1, j=0; i < 2300 && j<2299; ++i, ++j) {
	
		a[i].arrivalT += a[j].arrivalT;

	}

	

	job b[1700];

	//creating data for type b jobs 
	for (int i = 0; i < 1700; ++i) {
	
		b[i] = { 'B',6 + rand() % 3 , 2 + rand() % 10};
	}
	for (int i = 1, j = 0; i < 1700 && j<1699; ++i, ++j) {
	
	
		b[i].arrivalT += b[j].arrivalT;
	}
	

	job mergeAB[4000];

	for (int i = 0; i < 2300; ++i) {
	
		mergeAB[i] = a[i];

	}

	for (int i = 2300 , k = 0; i < 4000, k < 1700; i++, k++) {
		mergeAB[i] = b[k];
	}

	job c[950];
	//creating data for type c jobs

	for (int i = 0; i < 950; ++i) {
	
		c[i] = { 'C',8 + rand() % 10, 6 + rand() % 6};

	}
	for (int i = 1, j = 0; i < 950 && j < 949; ++i, ++j) {


		c[i].arrivalT += c[j].arrivalT;
	}

	job d[620];
	//creating data for type d jobs

	for (int i = 0; i < 620; ++i) {
	
		d[i] = { 'D',14 + rand() % 10, 9 + rand() % 8};
	}
	for (int i = 1, j = 0; i < 620 && j < 619; ++i, ++j) {


		d[i].arrivalT += d[j].arrivalT;
	}

	//merging c and d data
	job mergeCD[1570];

	for (int i = 0; i < 620; ++i) {

		mergeCD[i] = d[i];

	}

	for (int i = 620, k = 0; i < 1570, k < 950; i++, k++) {
		mergeCD[i] = c[k];
	}



	//finally, combining CD and AB arrays together 
	//then fully sort after?
	job fullMerge[5570];
	for (int i = 0; i < 1570; ++i) {

		fullMerge[i] = mergeCD[i];

	}
	for (int i = 1570, k = 0; i < 5570, k < 4000; i++, k++) {
		fullMerge[i] = mergeAB[k];
	}
	cout << "FULL ARRAY UNSORTED"<<endl;
	for (int i = 0; i < 5570; ++i) {

		cout << fullMerge[i].priority << "  " << fullMerge[i].arrivalT << "   " << fullMerge[i].processT << endl;

	}



	//sort ascending order with arrival time
	for (int i = 0; i < 5570; i++) {
	
		for (int j = i + 1; j < 5570; j++) {
		
			if (fullMerge[i].arrivalT > fullMerge[j].arrivalT) {
				
				job temp = fullMerge[i];
				fullMerge[i] = fullMerge[j];
				fullMerge[j] = temp;
			
			}
		}
	}

	//sort the "sorted" with priority included
	for (int i = 0; i < 5570; i++) {

		for (int j = i + 1; j < 5570; j++) {

			if (fullMerge[i].arrivalT == fullMerge[j].arrivalT && fullMerge[i].priority < fullMerge[j].priority) {

				job temp = fullMerge[i];
				fullMerge[i] = fullMerge[j];
				fullMerge[j] = temp;

			}
		}
	}

	cout << "FULL ARRAY SORTED" << endl;
	for (int i = 0; i < 5570; ++i) {

		dataFile << fullMerge[i].priority << "  " << fullMerge[i].arrivalT << "   " << fullMerge[i].processT << endl;

	}

}








