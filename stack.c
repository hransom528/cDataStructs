// Harris Ransom
// C Stack
// Based on video by Jacob Sorber
// Note: It is also possible to implement a stack using a linked list instead of an array

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "stack.h"

// Pushes value onto stack
bool push(int value) {
    if (top >= STACK_LENGTH-1) return false;
    
    top++;
    stack[top] = value;
    return true;
}

// Pops value off of stack
int pop() {
    if (top == EMPTY) return STACK_EMPTY;

    int result = stack[top];
    top--;
    return result;
}