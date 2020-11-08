#include <assert.h>
#include "Stack.h"

void testingOfStack(Stack* myStack)
{
	assert(isEmpty(myStack));
	push(myStack, 10);
	assert(!isEmpty(myStack));
	push(myStack, 20);
	assert(top(myStack) == 20);
	assert(pop(myStack) == 20);
	assert(top(myStack) == 10);
	push(myStack, 30);
	deleteStack(myStack);
	assert(isEmpty(myStack));
}

int main()
{
	Stack* myStack = createStack();
	testingOfStack(myStack);
}