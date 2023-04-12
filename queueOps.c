/* queueOps.c */

#include "queue.h"
#include<stdio.h>
#include<stdlib.h>

QHEAD *createQueue(int maxSize)
{
	QHEAD *qhead;
	qhead=(QHEAD *)malloc(sizeof(QHEAD));
	qhead->numNodes=0;
	qhead->maxSize=maxSize;
	qhead->next=NULL;
	return qhead;
}

int isEmpty(QHEAD *qhead)
{
	if(qhead->next==NULL) return 1;
	else return 0;
}

int isFull(QHEAD *qhead)
{
	if(qhead->numNodes==qhead->maxSize) return 1;
	else return 0;
}

job * frontQ(QHEAD *qhead)
{
	QNODE *temp;
	if(isEmpty(qhead))
		return NULL;
	else
	{
		temp=qhead->next;
		while(temp->next!=NULL)
			temp=temp->next;
		return temp->jobPtr;		
	}
}

void addQ(QHEAD *qhead, job *jobPtr)
{
	QNODE *qnode;
	if(isFull(qhead))
		printf("The Queue is Full\n");
	else
	{
		qnode=(QNODE *)malloc(sizeof(QNODE));
		qnode->jobPtr=jobPtr;
		qnode->next=qhead->next;
		qhead->next=qnode;
		qhead->numNodes=qhead->numNodes+1;
	}
}

void deleteFromQueue(QHEAD *qhead, job *jobPtr) {
	QNODE *temp = qhead->next;

	if (temp->jobPtr == jobPtr) {
		qhead->next = temp->next;
		free(temp);
		return;
	}

	while(temp->next) {
		if (temp->next->jobPtr == jobPtr) {
			QNODE *next = temp->next, *next2 = temp->next->next;
			temp->next = next2;
			free(next);
		}
		temp = temp->next;
	}
}

void updateQueueWithReadyJobs(QHEAD *qhead, job **jobs, int numberOfJobs, double currentTime, int *index) {
	
	while(*index < numberOfJobs && jobs[*index]->arrivalTime < currentTime) {
		addQ(qhead, jobs[*index]);
		*index = *index + 1;
	}
}