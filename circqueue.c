// Harris Ransom
// C Circular Queue w/arrays
// Based on video by Jacob Sorber

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "circqueue.h"

#define QUEUE_SIZE 5

typedef struct myq {
	int *values;
    int head, tail, n, size;
} queue;

// Initializes queue
void initQueue(queue *q, int maxSize) {
    q->size = maxSize;
	q->values = malloc(sizeof(int) * q->size);
	q->n = 0;
	q->head = 0;
	q->tail = 0;
}

// Checks if queue is empty
bool isEmpty(queue *q) {
	return (q->n == 0) ? true : false;
}

// Checks if queue is full
bool isFull(queue *q) {
	return (q->n == q->size) ? true : false;
}

// Frees queue memory
void queueDestroy(queue *q) {
	free(q->values);
}

// Adds node to queue
bool enqueue(queue *q, int value) {
	if (isFull(q)) return false;

	q->values[q->tail] = value;
	q->n++;
	q->tail++;
	q->tail %= q->size;
	return true;
}

// Removes node from queue
int dequeue(queue *q) {
	int result;
	
	// Check if queue is empty
	if (isEmpty(q)) return false;

	result = q->values[q->head];
	q->head++;
	q->head %= q->size;
	q->n--;	
    return result;
}

// Outputs queue
void printQueue(queue *q) {
	if (isEmpty(q)) { 
		printf("<Empty>\n");
	}
	else {
		for (int i = 0; i < q->n; i++) {
			printf("%d\t%d\n", i+1, q->values[i]);
		}
		printf("end\n");
	}
}

// MAIN
/*
int main() {
	// Initializes queue
	queue q1;
	initQueue(&q1, QUEUE_SIZE);
	printQueue(&q1);

	// Adds items to queue
	enqueue(&q1, 56);
	enqueue(&q1, 78);
	enqueue(&q1, 23);
	enqueue(&q1, 988);
	enqueue(&q1, 13);
	enqueue(&q1, 2);
	printQueue(&q1);

	// Frees queue
	queueDestroy(&q1);
	return 0;
}
*/