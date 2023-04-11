#ifndef queue
#define queue

#include "job.h"

struct queueNode {
    job *jobPtr;
    struct queueNode *next;
    struct queueNode *prev;
};

typedef struct queueNode queueNode;

job * getFront(queueNode *head, queueNode *tail);

void pushBack(queueNode *head, queueNode *tail, job *jobPtr);

job * getMinLaxitJob(queueNode *head, queueNode *tail);

#endif