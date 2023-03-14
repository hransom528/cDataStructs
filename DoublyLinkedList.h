#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

// DoublyLinkedList node struct
struct node {
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node node_t;


void printList(node_t *head);

node_t *addNode(int value);

void removeNode(node_t *head, node_t *removal);

node_t *insertHeadNode(node_t *head, node_t *insert);

node_t *insertAfterNode(node_t *node, node_t *insert);

node_t *findNode(node_t *head, int value);

#endif