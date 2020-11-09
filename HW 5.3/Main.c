#define _CRT_SECURE_NO_WARNINGS

#include "..\Stack\Stack.h"
#include "Processings.h"
#include <stdio.h>
#include <assert.h>

void tests();

int main()
{
	tests();
	printf("Enter an infix expression: ");
	char infixExpression[100];
	gets_s(infixExpression, 99);
	char* postfixExpression = shuntingYardAlgorithm(infixExpression);
	printf("Postfix expression: %s\n", postfixExpression);
	printf("Answer: %d\n", postfixExpressionProcessing(postfixExpression));
}

void tests()
{
	assert(!strcmp(shuntingYardAlgorithm("(20 - 10)"), "20 10 - "));
	assert(!strcmp(shuntingYardAlgorithm("4 + 8 * 5"), "4 8 5 * + "));
	assert(postfixExpressionProcessing(shuntingYardAlgorithm("(1+2)")) == 3);
	assert(postfixExpressionProcessing(shuntingYardAlgorithm("1 + 2 * 3")) == 7);
	assert(postfixExpressionProcessing(shuntingYardAlgorithm("(1 + 2) * 3 - 4")) == 5);
	assert(postfixExpressionProcessing(shuntingYardAlgorithm("((100 - 50) / 5 - 10) * 99 + 5 * 5")) == 25);
	assert(postfixExpressionProcessing(shuntingYardAlgorithm("30 + 4 * 20 / ( 1 - 5 )")) == 10);
}