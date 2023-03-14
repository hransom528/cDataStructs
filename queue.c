// Harris Ransom
// C Queue
// Based on video by Jacob Sorber
// Note: You can also implement a queue using an array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "queue.h"

// Initializes queue
void initQueue(queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

// Adds node to queue
bool enqueue(queue *q, int value) {
    // Create new node
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL) return false;
    newnode->value = value;
    newnode->next = NULL;

    // If tail exists, connect new node to tail
    if (q->tail != NULL) {
        q->tail->next = newnode;
    }
    q->tail = newnode;

    // Check that the head is correct
    if (q->head == NULL) {
        q->head = newnode;
    }

    return true;
}

// Removes node from queue
int dequeue(queue *q) {
    // Check if queue is empty
    if (q->head == NULL) return QUEUE_EMPTY;

    // Save head of queue
    node *tmp = q->head;
    int result = tmp->value;

    // Remove from list
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(tmp);
    return result;
}