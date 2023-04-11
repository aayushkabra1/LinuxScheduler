#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "utils.h"

int main(int argc, char const *argv[])
{
    // Read "tasks.txt" and get all the task details.
    task *tasks[50];
    int numberOfTasks = 0;
    getTasks(tasks, &numberOfTasks);

    double hyperPeriod = lcm(tasks, numberOfTasks);
    printf("%f\n", hyperPeriod);

    int currentTime = 0;


    return 0;
}
