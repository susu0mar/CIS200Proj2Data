#include <iostream>
#include <fstream>
#include "Header.h"
#include "Proc.h"
#include "DataFile.cpp"
#include <vector>
using namespace std;
//hi
 void enQueue(struct queueNode** head, job ndata ) {

    queueNode* newNode = new queueNode; //creating new node to put data in
    queueNode* last = *head;  //creating a temp pointer with head address to traverse the list until it reaches end to insert the new node

    newNode->data = ndata; //giving node data

    newNode->next = NULL; //setting node to null since its the last item on list

    //if the list is empty, made head the new node 
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    //traverse the list until you reach the last node 
    while (last->next != NULL) {
        
        last = last->next;

    }

    //set last nodes next to be our new node :D
    last->next = newNode;
    return;


}

 void dequeue(struct queueNode* head)
{
	 if (isEmpty(&head)) 
		 return;
	 else {
		 //check if it is the head 
		 queueNode* temp = head;
		 head = head->next;
		 
		 delete temp;
	 }

}

void InsertHead(queueNode** oldHead, job newJob) {

	queueNode* newHead = new queueNode;
	newHead-> data = newJob;
	newHead->next = *oldHead;
	*oldHead = newHead;

}

bool isEmpty(queueNode** head)
{
	if (*head == NULL)
		return true;
	else
		return false;
}
 
job peek(queueNode** head) {

	return (*head)-> data;
}

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



	while //(//data still going )
	//{
	//insert
	//if (fullMerge.priorty == 'D')
	//insert in D linked list


	//else
	//insert in general linked List 
	//}


}