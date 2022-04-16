#include <iostream>
#include "Header.h"
#include "DataFile.cpp"
using namespace std;

 void enQueue(struct queue** head, job ndata ) {

    queue* newNode = new queue; //creating new node to put data in
    queue* last = *head;  //creating a temp pointer with head address to traverse the list until it reaches end to insert the new node

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

 void dequeue(struct queue* head)
{
	 if (isEmpty(&head)) 
		 return;
	 else {
		 //check if it is the head 
		 queue* temp = head;
		 head = head->next;
		 
		 delete temp;
	 }

}

void InsertHead(queue** oldHead, job newJob) {

	queue* newHead = new queue;
	newHead-> data = newJob;
	newHead->next = *oldHead;
	*oldHead = newHead;

}

bool isEmpty(queue** head)
{
	if (*head == NULL)
		return true;
	else
		return false;
}
 
job peek(queue** head) {

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
	
	queue* regQ=NULL;

	queue* priQ=NULL;



	while (//data still going )
	{
	//insert
	//if (fullMerge.priorty == 'D')
	//insert in D linked list


	//else
	//insert in general linked List 
	}


}