/* queue.h */

/* NODE */

#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include "job.h"

struct queue_list
{
	job *jobPtr;
	struct queue_list *next;
};
typedef struct queue_list QNODE;

/* HEAD */
typedef struct
{
	int numNodes;
	int maxSize;
	QNODE *next;
}QHEAD;

#endif