#pragma once
#include <stdbool.h>

typedef struct
{
	struct StackElement* head;
} Stack;

// Inserting an item on the stack
void push(Stack* myStack, int value);

// Removing an item from the stack
int pop(Stack* myStack);

// Viewing the top of the stack without deleting it
int top(Stack* myStack);

// Checking the stack is empty
bool isEmpty(Stack* myStack);

// Deleting the stack
void deleteStack(Stack** myStack);

// Creating the stack
Stack* createStack(void);