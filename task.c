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

        

        task *temp = (task *)malloc(sizeof(task));
        if (temp == NULL) {
            perror("malloc failed.\n");
            exit(0);
        }

        temp->arrivalTime = a;
        temp->deadline = d;
        temp->period = p;
        temp->worstCaseExecutionTime = e;
        temp->taskId = i + 1;

        tasks[i++] = temp;
    }

    *numberOfTasks = i;
}

void updateLaxity(task **tasks, int numberOfTasks, int currentTime) {
    // TODO
}