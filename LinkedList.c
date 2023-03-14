// Harris Ransom
// C Linked List
// Based on video by Jacob Sorber

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Prints current linked list
void printList(node_t *head) {
    node_t *temp = head;
    while (temp->next != NULL) {
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Adds node to end of list
node_t *addNode(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

// Creates new node at head of list
node_t *insertHeadNode(node_t *head, node_t *insert) {
    insert->next = head;
    return insert;
}

// Inserts new node after specified node in list
node_t *insertAfterNode(node_t *node, node_t *insert) {
    insert->next = node->next;
    node->next = insert;
}

// Find a node in the linked list
node_t *findNode(node_t *head, int value) {
    node_t *tmp = head;
    while (tmp != NULL) {
        if (tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}