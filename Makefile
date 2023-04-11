CC  := gcc

a.out: main.c task.o utils.o queue.o
	$(CC) main.c task.o utils.o queue.o

task.o: task.c task.h
	$(CC) -c task.c

utils.o: utils.c utils.h
	$(CC) -c utils.c

queue.o: queue.c queue.h
	$(CC) -c queue.c