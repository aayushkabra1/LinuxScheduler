/* queueOps.h */

#include "queue.h"

extern QHEAD *createQueue(int maxSize);

extern job * frontQ(QHEAD *qhead);

extern void addQ(QHEAD *qhead, job *jobPtr);

extern int deleteFromQueue(QHEAD *qhead, job *jobPtr);

extern void updateQueueWithReadyJobs(QHEAD *qhead, job **jobs, int numberOfJobs, double currentTime, int *index);

extern job * getMinLaxityJob(QHEAD *qhead);