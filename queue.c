#include <stdio.h>
#include "queue.h"

task * getFront(queueNode *head, queueNode *tail) {
    if (head == NULL && tail == NULL) return NULL;

    return head->taskPtr;
}

void pushBack(queueNode *head, queueNode *tail, task *taskPtr) {
    if (head == NULL && tail == NULL) {
        head = (queueNode *)malloc(sizeof(queueNode));
        tail = head;

        head->taskPtr = taskPtr;

        return;
    }

    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    newNode->taskPtr = taskPtr;
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

task * getMinLaxityTask(queueNode *head, queueNode *tail) {
    queueNode *retTask = head, *temp = head;
    double minLaxity = retTask->taskPtr->laxity;

    while(temp) {
        if (temp->taskPtr->laxity < minLaxity) {
            retTask = temp;
            minLaxity = retTask->taskPtr->laxity;
        }

        temp = temp->next;
    }

    return retTask->taskPtr;
}