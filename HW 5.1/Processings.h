#pragma once
#include "Stack.h"
#include <string.h>
#include <ctype.h>

void operationsProcessing(Stack* myStack, char operation);

void numbersProcessing(Stack* myStack, char* mathExpression, int* i);

void expressionProcessing(Stack* myStack, char* mathExpression);