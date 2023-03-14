#ifndef STACK_H
#define STACK_H

#define STACK_LENGTH 100
#define EMPTY -1
#define STACK_EMPTY INT_MIN

int stack[STACK_LENGTH] = { 0 };
int top = EMPTY;

bool push(int value);

int pop();

#endif