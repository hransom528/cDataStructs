#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// LinkedList node struct
struct node {
    int value;
    struct node *next;
};
typedef struct node node_t;


void printList(node_t *head);

node_t *addNode(int value);

node_t *insertHeadNode(node_t *head, node_t *insert);

node_t *insertAfterNode(node_t *node, node_t *insert);

node_t *findNode(node_t *head, int value);
#endif