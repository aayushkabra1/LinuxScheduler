#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

job * getFront(queueNode *head, queueNode *tail) {
    if (head == NULL && tail == NULL) return NULL;

    return head->jobPtr;
}

void pushBack(queueNode *head, queueNode *tail, job *jobPtr) {
    if (head == NULL && tail == NULL) {
        head = (queueNode *)malloc(sizeof(queueNode));
        tail = head;

        head->jobPtr = jobPtr;

        return;
    }

    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    newNode->jobPtr = jobPtr;
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

job * getMinLaxityjob(queueNode *head, queueNode *tail) {
    queueNode *retJob = head, *temp = head;
    double minLaxity = retJob->jobPtr->laxity;

    while(temp) {
        if (temp->jobPtr->laxity < minLaxity) {
            retJob = temp;
            minLaxity = retJob->jobPtr->laxity;
        }

        temp = temp->next;
    }

    return retJob->jobPtr;
}



int removeJobFromQueue(queueNode *head, queueNode *tail, job *jobPtr) {
    if (head == NULL) return 0;

    if (head == tail && head->jobPtr == jobPtr) {
        free(head);
        head = tail = NULL;
        return 1;
    }

    if (head->jobPtr == jobPtr) {
        queueNode *temp = head;
        head = head->next;
        free(temp);
        return 1;
    }

    if (tail->jobPtr == jobPtr) {
        queueNode *temp = tail;
        tail = tail->prev;
        free(temp);
        return 1;
    }

    queueNode *temp = head;
    while(temp) {
        if (temp->jobPtr == jobPtr) {
            queueNode *prev = temp->prev;
            queueNode *next = temp->next;

            free(temp);
            prev->next = next;
            next->prev = prev;

            return 1;
        }
        temp = temp->next;
    }
    
    return 0;
}

void updateQueueWithReadyJobs(queueNode *head, queueNode *tail, job **jobs, int *index, int numberOfJobs, double currentTime) {
    while(*index < numberOfJobs && jobs[*index]->arrivalTime <= currentTime) {
        pushBack(head, tail, jobs[*index]);
        *index = *index + 1;
    }
}

int queueIsEmpty(queueNode *head, queueNode *tail) {
    return head == NULL;
}