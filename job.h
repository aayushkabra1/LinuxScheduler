#ifndef job_struct
#define job_struct

#include "task.h"

struct job {
    double arrivalTime;
    double deadline;
    double period;
    double worstCaseExecutionTime;
    double laxity;
    double remainingTime;
    double actualBurstTime;
    int jobId;
    int taskId;
};

typedef struct job job;

void fillAndSortJobs(job **jobs, int *numberOfJobs, task **tasks, int numberOfTasks, double hyperPeriod);

void mergeSort(job **jobs, int l, int r);

void updateLaxity(job **jobs, int numberOfJobs, double currentTime);

#endif