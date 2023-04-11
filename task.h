#ifndef task_struct
#define task_struct

struct task {
    double arrivalTime;
    double deadline;
    double period;
    double worstCaseExecutionTime;
    int taskId;
};

typedef struct task task;

void getTasks(task **tasks, int *numberOfTasks);

#endif