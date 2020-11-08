#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Processings.h"

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

void expressionProcessing(Stack* myStack, char* mathExpression)
{
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
}