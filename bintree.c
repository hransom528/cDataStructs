// Harris Ransom
// C Binary Tree
// Based on video by Jacob Sorber

#include <stdio.h>
#include <stdlib.h>

#define TREE_SIZE 5

typedef struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

// Creates new unconnected tree node
treenode *createnode(int value) {
    treenode *result = malloc(sizeof(treenode));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

// Outputs specified number of tabs
void printTabs(int numTabs) {
    for (int i = 0; i < numTabs; i++) {
        printf("\t");
    }
}

// Recursively prints out tree
void printTree(treenode *root, int level) {
    if (root == NULL) {
        printTabs(level);
        printf("---<Empty>---\n");
        return;
    }

    // Recursive Preorder Traversal
    printTabs(level);
    printf("value = %d\n", root->value);

    printTabs(level);
    printf("left\n");
    printTree(root->left, level+1);
    printTabs(level);

    printf("right\n");
    printTree(root->right, level+1);

    printTabs(level);
    printf("done\n");

}

// MAIN
int main() {
    // Creates binary tree
    treenode **tree = malloc(TREE_SIZE * sizeof(treenode));
    for (int i = 0; i < TREE_SIZE; i++) {
        tree[i] = createnode(10+i);
    }
    treenode *n1 = tree[0];
    treenode *n2 = tree[1];
    treenode *n3 = tree[2];
    treenode *n4 = tree[3];
    treenode *n5 = tree[4];

    // Builds tree structure
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    // Outputs tree
    printTree(tree[0], 0);

    // Deletes tree
    for (int i = 0; i < TREE_SIZE; i++) {
        free(tree[i]);
    }
    return 0;
}

