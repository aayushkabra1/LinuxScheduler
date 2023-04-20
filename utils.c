#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "task.h"

void swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

long long gcd(long long a, long long b) {
    if (a < b) swap(&a, &b);

    if (b == 0) return a;
    return gcd(b, a % b);
}

double lcm(task **tasks, int numberOfTasks) {
    long long periods[50];
    for (int i = 0; i < numberOfTasks; i++) {
        periods[i] = (long long)(tasks[i]->period * 100);
    }

    long long ans = periods[0];
    for (int i = 1; i < numberOfTasks; i++) {
        ans = (((periods[i] * ans)) / (gcd(periods[i], ans)));
    }

    return ans / 100.0;
}

double min(double a, double b) {
    if (a <= b) return a;
    return b;
}