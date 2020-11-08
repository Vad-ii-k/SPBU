#include "../Stack/Stack.h"
#include "CorrectnessOfParenthesis.h"
#include <assert.h>
#include <stdio.h>

void testing()
{
	assert(correctnessOfParenthesis("{}[]()"));
	assert(!correctnessOfParenthesis("([)]{}"));
	assert(correctnessOfParenthesis("[({})]"));
	assert(!correctnessOfParenthesis("[(}]"));
	assert(!correctnessOfParenthesis("[[))"));
	assert(!correctnessOfParenthesis("]["));
	assert(!correctnessOfParenthesis("abc"));
}

int main()
{
	testing();
	printf("Enter the expression from the parentheses: ");
	char parenthesisExpression[100];
	gets_s(parenthesisExpression, 99);
	if (correctnessOfParenthesis(parenthesisExpression))
	{
		printf("Correct\n");
	}
	else
	{
		printf("Uncorrect\n");
	}
}