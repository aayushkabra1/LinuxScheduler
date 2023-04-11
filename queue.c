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