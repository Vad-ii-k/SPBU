#include <stdlib.h>
#include "..\Stack\Stack.h"

typedef struct StackElement
{
	int value;
	struct StackElement* next;
} StackElement;

Stack* createStack(void)
{
	Stack* myStack = malloc(sizeof(Stack));
	if (myStack == NULL)
	{
		return NULL;
	}
	myStack->head = NULL;
	return myStack;
}

void push(Stack* myStack, int value)
{
	StackElement* newElement = malloc(sizeof(StackElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->value = value;
	newElement->next = myStack->head;
	myStack->head = newElement;
}

int pop(Stack* myStack)
{
	if (isEmpty(myStack))
	{
		return -1;
	}
	int item = myStack->head->value;

	StackElement* tmp = myStack->head;
	myStack->head = myStack->head->next;
	free(tmp);
	return item;
}

int top(Stack* myStack)
{
	if (isEmpty(myStack))
	{
		return -1;
	}
	return myStack->head->value;
}

void deleteStack(Stack** myStack)
{
	while (!isEmpty(myStack))
	{
		pop(myStack);
	}
	free(*myStack);
	*myStack = NULL;
}

bool isEmpty(Stack* myStack)
{
	return myStack->head == NULL;
}