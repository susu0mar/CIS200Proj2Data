// CIS200Proj2Data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
using namespace std;

struct job {

	char priority;
	int arrivalT;
	int processT;

};

int main()
{
	job a[100];

	//creating data for type a jobs
	//i think create at array with these values, then adjust the arrival time based on previous arrival time (so like prev arrival + arrival) to get actual arrival tiem
	for (int i = 0; i < 100; ++i){
	
		a[i] = { 'A', 4 + rand() % 3, 1 + rand() % 5 };
	
	}



	// adding arrival time to previous arrival time (cause cumulative)
	
	for (int i = 1, j=0; i < 100 && j<99; ++i, ++j) {
	
		a[i].arrivalT += a[j].arrivalT;

	}

	cout << "New arrival time for A" << endl;
	for (int i = 0; i < 100; ++i) {

		cout <<a[i].priority<< "  " << a[i].arrivalT << "   " << a[i].processT << endl;

	}

	job b[100];

	//creating data for type b jobs 
	for (int i = 0; i < 100; ++i) {
	
		b[i] = { 'B',6 + rand() % 3 , 2 + rand() % 10};
	}
	for (int i = 1, j = 0; i < 100 && j<99; ++i, ++j) {
	
	
		b[i].arrivalT += b[j].arrivalT;
	}
	cout << "arrival time b" << endl;
	for (int i = 0; i < 100; ++i) {

		cout << b[i].priority<<"  " << b[i].arrivalT << "   " << b[i].processT << endl;

	}

	job mergeAB[200];

	for (int i = 0; i < 100; ++i) {
	
		mergeAB[i] = a[i];

	}

	for(int i = 100, int k = 0; i < 200, k < 100; i++, k++) {
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



}




