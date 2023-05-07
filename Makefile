CC  := gcc

a.out: main.c task.o utils.o queueOps.o job.o
	$(CC) main.c task.o utils.o queueOps.o job.o

task.o: task.c task.h
	$(CC) -c task.c

utils.o: utils.c utils.h
	$(CC) -c utils.c

queueOps.o: queueOps.c queueOps.h queue.h
	$(CC) -c queueOps.c

job.o: job.c job.h
	$(CC) -c job.c

clean:
	rm -f *.o *.out *.exe