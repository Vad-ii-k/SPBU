#pragma once

// Calculating a postfix expression
int postfixExpressionProcessing(char* mathExpression);

// Converting from an infix expression to a postfix expression (Dijkstra's algorithm)
char* shuntingYardAlgorithm(char* infixExpression);