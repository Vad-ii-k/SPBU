#include <stdio.h>
#include <assert.h>
#include "Stack.h"
#include "Processings.h"

void testingOfProcessings();

int main()
{
	testingOfProcessings();
	Stack* myStack = createStack();
	printf("Enter an expression: ");
	char mathExpression[100];
	gets_s(mathExpression, 99);
	expressionProcessing(myStack, mathExpression);
	printf("%d\n", pop(myStack));
}

void testingOfProcessings()
{
	Stack* testStack = createStack();
	expressionProcessing(testStack, "abc148de300");
	assert(pop(testStack) == 300);
	assert(pop(testStack) == 148);

	push(testStack, 90);
	push(testStack, 10);
	operationsProcessing(testStack, '+');
	assert(pop(testStack) == 100);

	push(testStack, 90);
	push(testStack, 10);
	operationsProcessing(testStack, '-');
	assert(pop(testStack) == 80);

	expressionProcessing(testStack, "90 10...");
	operationsProcessing(testStack, '*');
	assert(pop(testStack) == 900);

	expressionProcessing(testStack, "90 10...");
	operationsProcessing(testStack, '/');
	assert(pop(testStack) == 9);

	expressionProcessing(testStack, "4 6 + 5 - 5 / 99 + 5 *");
	assert(pop(testStack) == 500);
	assert(isEmpty(testStack));
}