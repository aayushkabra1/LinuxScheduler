#ifndef queue
#define queue

#include "task.h"

struct queueNode {
    task *taskPtr;
    struct queueNode *next;
    struct queueNode *prev;
};

typedef struct queueNode queueNode;

task * getFront(queueNode *head, queueNode *tail);

void pushBack(queueNode *head, queueNode *tail, task *taskPtr);

#endif