// Harris Ransom
// C Binary Search Tree
// Based on video by Jacob Sorber

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Inserts number recursively into search tree
bool insertNum(treenode **rootp, int value) {
	if (*rootp == NULL) {
		*rootp = createnode(value);
        return true;
	}
    else if (value == (*rootp)->value) {
        return false;
    }
    else if (value < (*rootp)->value) {
        return insertNum(&(*rootp)->left, value);
    }
    else {
        return insertNum(&(*rootp)->right, value);
    }
}

// Determines if number is in search tree
bool findNum(treenode *rootp, int value) {
    if (rootp == NULL) {
        return false;
    }
    else if (value == rootp->value) {
        return true;
    }
    else if (value < rootp->value) {
        return findNum(rootp->left, value);
    }
    else {
        return findNum(rootp->right, value);
    }
}

// Frees tree from memory
void deleteTree(treenode *rootp) {
    if (rootp == NULL) return;
    else if (rootp->left == NULL || rootp->right == NULL) {
        free(rootp);
        return;
    }
    else {
        deleteTree(rootp->right);
        deleteTree(rootp->left);
        free(rootp);
        return;
    }
}

// MAIN
int main() {
    // Creates binary tree
    treenode *root = NULL;

    // Builds tree
    insertNum(&root, 15);
    insertNum(&root, 11);
    insertNum(&root, 24);
    insertNum(&root, 5);
    insertNum(&root, 16);
    insertNum(&root, 19);

    printTree(root, 0);

    // Tests findNum
    printf("%d (%d)\n", 16, findNum(root, 16));
    printf("%d (%d)\n", 15, findNum(root, 15));
    printf("%d (%d)\n", 15, findNum(root, 5));
    printf("%d (%d)\n", 115, findNum(root, 115));
    printf("%d (%d)\n", 1, findNum(root, 1));
    printf("%d (%d)\n", 7, findNum(root, 7));

    // Deletes tree
    deleteTree(root);
    return 0;
}

