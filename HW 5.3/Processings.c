#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Processings.h"
#include "..\Stack\Stack.h"

int priorityOfOperations(char operation)
{
	switch (operation)
	{
	case '(':
	case ')':
	{
		return 0;
	}
	case '+':
	case '-':
	{
		return 1;
	}
	case '*':
	case '/':
	{
		return 2;
	}
	}
	return -1;
}

void addingNumberToOutputQueue(char* postfixExpression, int* postfixIndex, char* infixExpression, int* infixIndex)
{
	while (infixExpression[*infixIndex] != '\0' && isdigit((unsigned char)infixExpression[*infixIndex]))
	{
		postfixExpression[*postfixIndex] = infixExpression[*infixIndex];
		(*postfixIndex)++;
		(*infixIndex)++;
	}
	postfixExpression[*postfixIndex] = ' ';
	(*postfixIndex)++;
	(*infixIndex)--;
}

void addingOperationToOutputQueue(Stack* operationStack, char* postfixExpression, int* postfixIndex)
{
	postfixExpression[*postfixIndex] = pop(operationStack);
	postfixExpression[*postfixIndex + 1] = ' ';
	*postfixIndex += 2;
}

void addingSeveralOperations(Stack* operationStack, char* postfixExpression, int* postfixIndex, char* infixExpression, int* infixIndex)
{
	int topLevel = priorityOfOperations(top(operationStack));
	int curLevel = priorityOfOperations(infixExpression[*infixIndex]);
	while (topLevel >= 0 && topLevel >= curLevel && top(operationStack) != '(')
	{
		addingOperationToOutputQueue(operationStack, postfixExpression, postfixIndex);
		topLevel = priorityOfOperations(top(operationStack));
	}
	push(operationStack, infixExpression[*infixIndex]);
}

char* shuntingYardAlgorithm(char* infixExpression)
{
	Stack* operationStack = createStack();
	char* postfixExpression = malloc(sizeof(char) * 100);
	if (postfixExpression == NULL)
	{
		exit(1);
	}

	int infixIndex = 0;
	int postfixIndex = 0;
	while (infixExpression[infixIndex] != '\0')
	{
		if (isdigit((unsigned char)infixExpression[infixIndex]))
		{
			addingNumberToOutputQueue(postfixExpression, &postfixIndex, infixExpression, &infixIndex);
		}
		else if (infixExpression[infixIndex] == '(')
		{
			push(operationStack, infixExpression[infixIndex]);
		}
		else if (priorityOfOperations(infixExpression[infixIndex]) >= 0)
		{
			addingSeveralOperations(operationStack, postfixExpression, &postfixIndex, infixExpression, &infixIndex);
		}
		else if (infixExpression[infixIndex] == '(')
		{
			while (top(operationStack) != '(')
			{
				addingOperationToOutputQueue(operationStack, postfixExpression, postfixIndex);
			}
		}
		infixIndex++;
	}
	while (!isEmpty(operationStack))
	{
		if (top(operationStack) != '(' && top(operationStack) != ')')
		{
			addingOperationToOutputQueue(operationStack, postfixExpression, &postfixIndex);
		}
		else
		{
			pop(operationStack);
		}
	}
	deleteStack(operationStack);
	postfixExpression[postfixIndex] = '\0';
	return postfixExpression;
}

void operationsProcessing(Stack* myStack, char operation)
{
	if (isEmpty(myStack))
	{
		exit(1);
	}
	int x = pop(myStack);
	if (isEmpty(myStack))
	{
		exit(1);
	}
	int y = pop(myStack);
	switch (operation)
	{
	case '+':
	{
		push(myStack, x + y);
		break;
	}
	case '-':
	{
		push(myStack, y - x);
		break;
	}
	case '*':
	{
		push(myStack, x * y);
		break;
	}
	case '/':
	{
		push(myStack, y / x);
		break;
	}
	}
}

void numbersProcessing(Stack* myStack, char* mathExpression, int* i)
{
	int x = 0;
	while (isdigit((unsigned char)mathExpression[*i]))
	{
		x = x * 10 + mathExpression[*i] - '0';
		(*i)++;
	}
	push(myStack, x);
}

int postfixExpressionProcessing(char* mathExpression)
{
	Stack* myStack = createStack();
	int i = 0;
	while (mathExpression[i] != '\0')
	{
		if (isdigit((unsigned char)mathExpression[i]))
		{
			numbersProcessing(myStack, mathExpression, &i);
		}
		else if (strchr("+-/*", mathExpression[i]))
		{
			operationsProcessing(myStack, mathExpression[i]);
		}
		i++;
	}
	if (!isEmpty(myStack))
	{
		const int answer = pop(myStack);
		if (!isEmpty(myStack))
		{
			deleteStack(myStack);
			exit(1);
		}
		else
		{
			deleteStack(myStack);
			return answer;
		}
	}
}