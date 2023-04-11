#include <stdio.h>
#include <stdlib.h>
#include "job.h"
#include "task.h"
#include "utils.h"

void merge(job **jobs, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    job *L[n1], *M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = jobs[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = jobs[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i]->arrivalTime <= M[j]->arrivalTime) {
        jobs[k] = L[i];
        i++;
        } else {
        jobs[k] = M[j];
        j++;
        }
        k++;
    }

    while (i < n1) {
        jobs[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        jobs[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(job **jobs, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(jobs, l, m);
        mergeSort(jobs, m + 1, r);

        merge(jobs, l, m, r);
    }
}

void fillAndSortJobs(job **jobs, int *numberOfJobs, task **tasks, int numberOfTasks, double hyperPeriod) {
    int jobIndex = 0;
    for (int i = 0; i < numberOfTasks; i++) {
        int freq = hyperPeriod / tasks[i]->period;
        task *taskPtr = tasks[i];

        for (int j = 0; j < freq; j++) {
            job *newJob = (job *)malloc(sizeof(job));
            int fraction = (rand() * 40.0 / RAND_MAX) + 60;

            newJob->arrivalTime = taskPtr->arrivalTime + j*taskPtr->period;
            newJob->worstCaseExecutionTime = taskPtr->worstCaseExecutionTime;
            newJob->actualBurstTime = fraction * newJob->worstCaseExecutionTime / 100.0;
            newJob->remainingTime = newJob->actualBurstTime;
            newJob->deadline = newJob->arrivalTime + taskPtr->deadline;
            newJob->period = taskPtr->period;
            newJob->laxity = newJob->deadline - newJob->remainingTime;
            newJob->taskId = taskPtr->taskId;

            newJob->jobId = j + 1;

            jobs[jobIndex++] = newJob;
        }
    }

    *numberOfJobs = jobIndex;

    mergeSort(jobs, 0, *numberOfJobs - 1);
}

