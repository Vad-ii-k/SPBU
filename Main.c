#include "Stack.h"
#include "CorrectnessOfParenthesis.h"
#include <assert.h>
#include <stdio.h>

void testing()
{
	Stack* testStack = createStack();
	assert(correctnessOfParenthesis(testStack, "{}[]()"));
	assert(isEmpty(testStack));
	assert(!correctnessOfParenthesis(testStack, "([)]{}"));
	assert(correctnessOfParenthesis(testStack, "[({})]"));
	assert(!correctnessOfParenthesis(testStack, "[(}]"));
	assert(!correctnessOfParenthesis(testStack, "[[))"));
}

int main()
{
	testing();
	Stack* myStack = createStack();
	printf("Enter the expression from the parentheses: ");
	char parenthesisExpression[100];
	gets_s(parenthesisExpression, 99);
	if (correctnessOfParenthesis(myStack, parenthesisExpression) and isEmpty(myStack))
	{
		printf("Correct\n");
	}
	else
	{
		printf("Uncorrect\n");
	}
}