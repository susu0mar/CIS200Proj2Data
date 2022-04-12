#pragma once
#include <iostream>
using namespace std;

struct job {

	char priority;
	int arrivalT;
	int processT;
};

struct task {
	char prior;
	int clock;
	task* next;
	task* prev;
};
