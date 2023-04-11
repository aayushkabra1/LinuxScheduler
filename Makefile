CC  := gcc

a.out: main.c task.o utils.o queue.o job.o
	$(CC) main.c task.o utils.o queue.o job.o

task.o: task.c task.h
	$(CC) -c task.c

utils.o: utils.c utils.h
	$(CC) -c utils.c

queue.o: queue.c queue.h
	$(CC) -c queue.c

job.o: job.c job.h
	$(CC) -c job.c