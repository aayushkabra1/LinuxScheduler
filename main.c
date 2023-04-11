#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "utils.h"
#include "job.h"
#include "queue.h"

int main(int argc, char const *argv[])
{
    // Read "tasks.txt" and get all the task details.
    task *tasks[50];
    int numberOfTasks = 0;
    getTasks(tasks, &numberOfTasks);

    // get the hyper period
    double hyperPeriod = lcm(tasks, numberOfTasks);
    printf("Hyper period = %.2f\n\n", hyperPeriod);

    // generate actual jobs from tasks
    job *jobs[500];
    int numberOfJobs = 0;
    fillAndSortJobs(jobs, &numberOfJobs, tasks, numberOfTasks, hyperPeriod);

    // create a ready queue
    queueNode *head, *tail;

    int currentTime = jobs[0]->arrivalTime;
    int index = 0;

    while(index < numberOfJobs || currentTime <= hyperPeriod) {
        updateLaxity(jobs, numberOfJobs, currentTime);
        updateQueueWithReadyJobs(head, tail, jobs, &index, numberOfJobs, currentTime);

        job *currentJob = getMinLaxitJob(head, tail);
        double executionTime = currentJob->remainingTime;
        
        if (index < numberOfJobs) executionTime = min(executionTime, jobs[index]->arrivalTime);

        currentJob->remainingTime -= executionTime;
        if (currentJob->remainingTime == 0) removeJobFromQueue(head, tail, currentJob);
    }

    return 0;
}
