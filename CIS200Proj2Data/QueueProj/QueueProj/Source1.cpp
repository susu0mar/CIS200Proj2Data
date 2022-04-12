#include <iostream>
#include "Header.h"
using namespace std;

task* front = NULL;
//head
//tail
//remove
void insert(char prior, int clock, task** front)
{
	task* currPtr,
		* insertedItem = new task;
	insertedItem->prior = prior;
	if (*front == NULL) {  //new list
		insertedItem->prev = nullptr;
		insertedItem->next = nullptr;
		*front = insertedItem;
	}
}

//void  InsertList(char  item, node** head) {
	task* currPtr,
		* insertItem = new task;
	insertItem->letr = item;
	if (*head == NULL) {  //new list
		insertItem->prev = nullptr;
		insertItem->next = nullptr;
		*head = insertItem;
	}
	else if ((*head)->letr > item) { //new first item in list
		insertItem->prev = nullptr;
		insertItem->next = (*head);
		(*head)->prev = insertItem;
		*head = insertItem;
	}
	else {
		currPtr = *head;
		while (currPtr->next != NULL && item > (currPtr->next)->letr)
		{
			currPtr = currPtr->next;
		}
		//either we're at the end of list or before insertion point
		if (currPtr->next == NULL) { //end of list
			insertItem->next = NULL;
			insertItem->prev = currPtr;
			currPtr->next = insertItem;
		}
		else { //middle 
			of list
				insertItem->next = currPtr->next;
			insertItem->prev = currPtr;
			insertItem->next->prev = insertItem;
			currPtr->next = insertItem;
		}

		//remove
