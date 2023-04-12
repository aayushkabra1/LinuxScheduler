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

    // // generate actual jobs from tasks
    job *jobs[500];
    int numberOfJobs = 0;
    fillAndSortJobs(jobs, &numberOfJobs, tasks, numberOfTasks, hyperPeriod);

    // for (int i = 0; i < numberOfJobs; i++) {
    //     printf("%d, %d | %f %f\n", jobs[i]->taskId, jobs[i]->jobId, jobs[i]->arrivalTime, jobs[i]->deadline);
    // }

    // create a ready queue
    
    // int currentTime = jobs[0]->arrivalTime;
    // int index = 0;

    // while(index < numberOfJobs || currentTime <= hyperPeriod) {
    //     updateLaxity(jobs, numberOfJobs, currentTime);

    //     updateQueueWithReadyJobs(head, tail, jobs, &index, numberOfJobs, currentTime);

    //     job *currentJob = getMinLaxityJob(head, tail);

    //     if (currentJob == NULL) {
    //         if (index >= numberOfJobs) exit(0);
            
    //         printf("%f | CPU is idle for %f\n", currentTime, jobs[index]->arrivalTime - currentTime);
    //         currentTime = jobs[index]->arrivalTime;
    //         continue;
    //     }

    //     double executionTime = currentJob->remainingTime;
        
    //     if (index < numberOfJobs) executionTime = min(executionTime, jobs[index]->arrivalTime);

    //     printf("%f | %d, %d job running for %f time.\n", currentTime, currentJob->taskId, currentJob->jobId, executionTime);

    //     currentJob->remainingTime -= executionTime;
    //     currentTime += executionTime;

    //     if (currentJob->remainingTime == 0) removeJobFromQueue(head, tail, currentJob);
    // }

    return 0;
}
