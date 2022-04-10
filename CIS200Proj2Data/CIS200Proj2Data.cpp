// CIS200Proj2Data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
using namespace std;

struct job {

	//char priority;
	int arrivalT;
	int processT;

};
int main()
{
	job a[100];

	//creating data for type a jobs
	//i think create at array with these values, then adjust the arrival time based on previous arrival time (so like prev arrival + arrival) to get actual arrival tiem
	for (int i = 0; i < 100; ++i){
	
		a[i] = { 4 + rand() % 3, 1 + rand() % 5 };
	
	}

	for (int i = 0; i < 100; ++i) {
	
		cout << a[i].arrivalT <<"   "<< a[i].processT<<endl;

	}


	// adding arrival time to previous arrival time 
	
	for (int i = 1, j=0; i < 100 && j<99; ++i, ++j) {
	
		a[i].arrivalT += a[j].arrivalT;

	}

	cout << "New arrival time for A" << endl;
	for (int i = 0; i < 100; ++i) {

		cout << a[i].arrivalT << "   " << a[i].processT << endl;

	}

	job b[100];

	//creating data for type b jobs
	for (int i = 0; i < 100; ++i) {
	
		b[i] = { 6 + rand() % 3 , 2 + rand() % 10 };
	}
	for (int i = 1, j = 0; i < 100 && j<99; ++i, ++j) {
	
	
		b[i].arrivalT += b[j].arrivalT;
	}
	cout << "arrival time b" << endl;
	for (int i = 0; i < 100; ++i) {

		cout << b[i].arrivalT << "   " << b[i].processT << endl;

	}

	job c[100];
	//creating data for type c jobs

	for (int i = 0; i < 100; ++i) {
	
		c[i] = { 8 + rand() % 10, 6 + rand() % 6 };

	}
	for (int i = 1, j = 0; i < 100 && j < 99; ++i, ++j) {


		c[i].arrivalT += c[j].arrivalT;
	}

	job d[100];
	//creating data for type d jobs

	for (int i = 0; i < 100; ++i) {
	
		d[i] = { 14 + rand() % 10, 9 + rand() % 8 };
	}
	for (int i = 1, j = 0; i < 100 && j < 99; ++i, ++j) {


		d[i].arrivalT += d[j].arrivalT;
	}

}


