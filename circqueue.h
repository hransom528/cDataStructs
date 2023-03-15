#ifndef CIRCQUEUE_H
#define CIRCQUEUE_H

#define QUEUE_EMPTY INT_MIN

typedef struct {
	int *values;
    int head, tail, n, size;
} queue;

void initQueue(queue *q, int maxSize);

bool isEmpty(queue *q);

bool isFull(queue *q);

void queueDestroy(queue *q);

bool enqueue(queue *q, int value);

int dequeue(queue *q);

void printQueue(queue *q);

#endif