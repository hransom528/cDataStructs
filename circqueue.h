#ifndef CIRCQUEUE_H
#define CIRCQUEUE_H

#include <limits.h>
#define QUEUE_EMPTY INT_MIN

typedef struct myq queue;

void initQueue(queue *q, int maxSize);
bool isEmpty(queue *q);
bool isFull(queue *q);
void queueDestroy(queue *q);
bool enqueue(queue *q, int value);
int dequeue(queue *q);
void printQueue(queue *q);
#endif