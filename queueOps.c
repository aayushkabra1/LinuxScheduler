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

int deleteFromQueue(QHEAD *qhead, job *jobPtr) {
	if (qhead->next == NULL) return 0;
	
	QNODE *temp = qhead->next;

	if (temp->jobPtr == jobPtr) {
		qhead->next = temp->next;
		free(temp);
		return 1;
	}

	while(temp->next) {
		if (temp->next->jobPtr == jobPtr) {
			QNODE *next = temp->next, *next2 = temp->next->next;
			temp->next = next2;
			free(next);
			return 1;
		}
		temp = temp->next;
	}

	return 0;
}

void updateQueueWithReadyJobs(QHEAD *qhead, job **jobs, int numberOfJobs, double currentTime, int *index) {
	while(*index < numberOfJobs && jobs[*index]->arrivalTime <= currentTime) {
		addQ(qhead, jobs[*index]);
		*index = *index + 1;
	}
}

job * getMinLaxityJob(QHEAD *qhead) {
	if (qhead->next == NULL) return NULL;

	QNODE *temp = qhead->next;
	job *retJob = temp->jobPtr;
	double minLaxity = retJob->laxity;

	while(temp) {
		if (temp->jobPtr->laxity < minLaxity) {
			retJob = temp->jobPtr;
			minLaxity = temp->jobPtr->laxity;
		}
		temp = temp->next;
	}

	return retJob;
}

void printQueue(QHEAD *qhead) {
	QNODE *temp = qhead->next;
	while(temp) {
		printf("(%d, %d) -> ", temp->jobPtr->taskId, temp->jobPtr->jobId);
		temp = temp->next;
	}
	printf("\n");
}