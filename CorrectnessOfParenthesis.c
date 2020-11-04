#include "correctnessOfParenthesis.h"

bool correctnessOfParenthesis(Stack* myStack, char* parenthesisExpression)
{
	int i = 0;
	while (parenthesisExpression[i] != '\0')
	{
		if (strchr("({[", parenthesisExpression[i]))
		{
			push(myStack, parenthesisExpression[i]);
		}
		else if (strchr(")}]", parenthesisExpression[i]))
		{
			char left = pop(myStack);
			char right = parenthesisExpression[i];
			if (!(left == '(' and right == ')' or left == '{' and right == '}' or left == '[' and right == ']'))
			{
				return false;
			}
		}
		i++;
	}
	return true;
}