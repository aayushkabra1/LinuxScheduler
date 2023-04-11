#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "utils.h"
#include "job.h"

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

    int currentTime = jobs[0]->arrivalTime;
    int index = 0;

    while(index < numberOfJobs || currentTime <= hyperPeriod) {
        if (index == numberOfJobs - 1) {
            printf("%d, %d completed.\n", jobs[index]->taskId, jobs[index]->jobId);
            jobs[index]->remainingTime = 0;
            index++;
            break;
        }

        double executionTime = min(jobs[index + 1]->arrivalTime, jobs[index]->remainingTime);
        
    }

    return 0;
}
