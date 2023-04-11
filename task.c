#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "task.h"

void getTasks(task **tasks, int *numberOfTasks) {
    FILE *filePtr = fopen("tasks.txt", "r");
    if (filePtr == NULL) {
        perror("Can't open file 'tasks.txt'.\n");
        exit(0);
    }

    int i = 0;
    srand(time(0));
    
    while(!feof(filePtr)) {
        double a, d, p, e;
        fscanf(filePtr, "%lf", &a);
        fscanf(filePtr, "%lf", &d);
        fscanf(filePtr, "%lf", &p);
        fscanf(filePtr, "%lf", &e);

        int fraction = (rand() * 40.0 / RAND_MAX) + 60;

        task *temp = (task *)malloc(sizeof(task));
        if (temp == NULL) {
            perror("malloc failed.\n");
            exit(0);
        }

        temp->arrivalTime = a;
        temp->deadline = d;
        temp->period = p;
        temp->worstCaseExecutionTime = e;
        temp->actualBurstTime = fraction * temp->worstCaseExecutionTime / 100.0;
        temp->remainingTime = temp->actualBurstTime;

        tasks[i++] = temp;
    }

    *numberOfTasks = i;
}

void updateLaxity(task **tasks, int numberOfTasks, int currentTime) {
    for (int i = 0; i < numberOfTasks; i++) {
        tasks[i]->laxity = tasks[i]->deadline - currentTime - tasks[i]->remainingTime;
    }
}