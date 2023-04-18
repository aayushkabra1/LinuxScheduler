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
    
    int currentTime = 0;
    int index = 0;

    while(index < numberOfJobs || currentTime <= hyperPeriod) {
        updateLaxity(jobs, numberOfJobs, currentTime);

        updateQueueWithReadyJobs(qhead, jobs, numberOfJobs, currentTime, &index);
        printQueue(qhead);

        job *currentJob = getMinLaxityJob(qhead);
        
        if (currentJob == NULL) {
            // TODO
        }

        double execTime = currentJob->remainingTime;

        if (index < numberOfJobs) execTime = min(execTime, jobs[index]->arrivalTime - currentTime);

        printf("Execution Time = %f\n", execTime);
        printf("(%d, %d)\n", currentJob->taskId, currentJob->jobId);
        

        printf("%f | (%d, %d) job running for %f time.\n\n", currentTime, currentJob->taskId, currentJob->jobId, execTime);

        // currentJob->remainingTime -= execTime;
        // currentTime += execTime;

        // if (currentJob->remainingTime == 0) deleteFromQueue(qhead, currentJob);
    }

    return 0;
}
