// Harris Ransom
// C Doubly Linked List
// Based on video by Jacob Sorber

#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

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
    result->prev = NULL;
    return result;
}

// Removes specified node from list
void removeNode(node_t *head, node_t *removal) {
    if (head == removal) {
        head = removal->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }
    else {
        removal->prev->next = removal->next;
        if (removal->next != NULL) {
            removal->next->prev = removal->prev;
        }
    }
    removal->next = NULL;
    removal->prev = NULL;
}

// Creates new node at head of list
node_t *insertHeadNode(node_t *head, node_t *insert) {
    insert->next = head;
    if (head != NULL) {
        head->prev = insert;
    }
    head = insert;
    insert->prev = NULL;
    return insert;
}

// Inserts new node after specified node in list
node_t *insertAfterNode(node_t *node, node_t *insert) {
    insert->next = node->next;
    if (insert->next != NULL) {
        insert->next->prev = node;
    }
    insert->prev = node;
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