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

}