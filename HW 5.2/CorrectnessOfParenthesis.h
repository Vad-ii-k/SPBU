#pragma once
#include "Stack.h"
#include <iso646.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Checks whether parentheses are correct
bool correctnessOfParenthesis(Stack* myStack, char* parenthesisExpression);