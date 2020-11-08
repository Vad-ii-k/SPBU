#include "CorrectnessOfParenthesis.h"
#include "../Stack/Stack.h"
#include <iso646.h>
#include <string.h>
#include <stdlib.h>

bool correctnessOfParenthesis(char* parenthesisExpression)
{
	Stack* myStack = createStack();
	int i = 0;
	while (parenthesisExpression[i] != '\0')
	{
		if (strchr("({[", parenthesisExpression[i]))
		{
			push(myStack, parenthesisExpression[i]);
		}
		else if (strchr(")}]", parenthesisExpression[i]))
		{
			if (isEmpty(myStack))
			{
				deleteStack(myStack);
				return false;
			}
			char left = pop(myStack);
			char right = parenthesisExpression[i];
			if (!(left == '(' and right == ')' or left == '{' and right == '}' or left == '[' and right == ']'))
			{
				deleteStack(myStack);
				return false;
			}
		}
		i++;
	}
	if (isEmpty(myStack) && (strchr(parenthesisExpression, '[') || strchr(parenthesisExpression, '{') || strchr(parenthesisExpression, '(')))
	{
		deleteStack(myStack);
		return true;
	}
	else
	{
		deleteStack(myStack);
		return false;
	}
}