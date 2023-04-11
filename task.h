#ifndef task_struct
#define task_struct

struct task {
    double arrivalTime;
    double deadline;
    double period;
    double worstCaseExecutionTime;
    double laxity;
    double remainingTime;
    double actualBurstTime;
};

typedef struct task task;

void getTasks(task **tasks, int *numberOfTasks);

void updateLaxity(task **tasks, int numberOfTasks, int currentTime);

#endif