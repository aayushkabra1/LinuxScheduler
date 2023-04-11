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

    double hyperPeriod = lcm(tasks, numberOfTasks);
    printf("Hyper period = %.2f\n\n", hyperPeriod);

    job *jobs[500];
    int numberOfJobs = 0;
    fillAndSortJobs(jobs, &numberOfJobs, tasks, numberOfTasks, hyperPeriod);

    // for (int i = 0; i < numberOfJobs; i++) {
    //     printf("%d, %d  |  ", jobs[i]->taskId, jobs[i]->jobId);
    //     printf("%.2f %.2f %.2f %.2f\n",jobs[i]->arrivalTime, jobs[i]->deadline, jobs[i]->worstCaseExecutionTime, jobs[i]->period);
    // }

    int currentTime = jobs[0]->arrivalTime;
    int index = 0;

    // while(index < numberOfJobs || currentTime <= hyperPeriod) {
    //     if (index == numberOfJobs - 1) {
    //         printf()
    //     }

    //     double executionTime = min(jobs[index + 1]->arrivalTime, jobs[index]->remainingTime);

    // }

    return 0;
}
