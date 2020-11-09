#define _CRT_SECURE_NO_WARNINGS

#include "..\Stack\Stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tests()
{

}

int priority(char operation)
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

void numbersProcessing(char* postfixExpression, int* postfixIndex, char* infixExpression, int* infixIndex)
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
			numbersProcessing(postfixExpression, &postfixIndex, infixExpression, &infixIndex);
		}
		else if (infixExpression[infixIndex] == '(')
		{
			push(operationStack, infixExpression[infixIndex]);
		}
		else if (priority(infixExpression[infixIndex]) >= 0)
		{
			int topLevel = priority(top(operationStack));
			int curLevel = priority(infixExpression[infixIndex]);
			while (topLevel >= 0 && topLevel >= curLevel && top(operationStack) != '(')
			{
				postfixExpression[postfixIndex] = pop(operationStack);
				postfixExpression[postfixIndex + 1] = ' ';
				postfixIndex += 2;
				topLevel = priority(top(operationStack));
			}
			push(operationStack, infixExpression[infixIndex]);
		}
		else if (infixExpression[infixIndex] == '(')
		{
			while (top(operationStack) != '(')
			{
				postfixExpression[postfixIndex] = pop(operationStack);
				postfixExpression[postfixIndex + 1] = ' ';
				postfixIndex += 2;
			}
		}
		infixIndex++;
	}
	while (!isEmpty(operationStack))
	{
		char currentChar = pop(operationStack);
		if (currentChar != '(' && currentChar != ')')
		{
			postfixExpression[postfixIndex] = currentChar;
			postfixExpression[postfixIndex + 1] = ' ';
			postfixIndex += 2;
		}
	}
	deleteStack(operationStack);
	postfixExpression[postfixIndex] = '\0';
	return postfixExpression;
}

int main()
{
	tests();
	printf("Enter an expression: ");
	char infixExpression[100];
	gets_s(infixExpression, 99);
	printf("%s\n", shuntingYardAlgorithm(infixExpression));
}