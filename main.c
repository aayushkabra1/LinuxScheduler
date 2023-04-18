#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "utils.h"
#include "job.h"
#include "queue.h"
#include "queueOps.h"

int main(int argc, char const *argv[])
{
    // Read "tasks.txt" and get all the task details.
    task *tasks[50];
    int numberOfTasks = 0;
    getTasks(tasks, &numberOfTasks);

    // get the hyper period
    double hyperPeriod = lcm(tasks, numberOfTasks);
    printf("Hyper period = %.2f\n\n", hyperPeriod);

    // // generate actual jobs from tasks
    job *jobs[500];
    int numberOfJobs = 0;
    fillAndSortJobs(jobs, &numberOfJobs, tasks, numberOfTasks, hyperPeriod);

    // create a ready queue
    QHEAD *qhead;
    qhead = createQueue(500);
    double currentTime = 0.0;
    int index = 0;

    while(index < numberOfJobs || currentTime <= hyperPeriod) {
        updateLaxity(jobs, numberOfJobs, currentTime);

        updateQueueWithReadyJobs(qhead, jobs, numberOfJobs, currentTime, &index);
        // printQueue(qhead);

        job *currentJob = getMinLaxityJob(qhead);

        if (currentJob == NULL) {
            if (index >= numberOfJobs) {
                printf("Done at %.2f.\n", currentTime);
                exit(0);
            }

            printf("%.2f | CPU is idle for %.2f units.\n\n", currentTime, jobs[index]->arrivalTime - currentTime);
            currentTime = jobs[index]->arrivalTime;
            continue;
        }

        double execTime = currentJob->remainingTime;

        if (index < numberOfJobs) execTime = min(execTime, jobs[index]->arrivalTime - currentTime);

        printf("%.2f | (%d, %d) task running for %.2f units.\n", currentTime, currentJob->taskId, currentJob->jobId, execTime);

        currentJob->remainingTime -= execTime;
        currentTime += execTime;

        if (currentJob->remainingTime == 0) deleteFromQueue(qhead, currentJob);
        printf("\n");   
    }

    return 0;
}
