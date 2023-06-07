#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "LLS.h"

typedef enum
{
  LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
  PLUS = '+', MINUS = '-',
  MULTIPLY = '*', DIVIDE = '/',
  SPACE = ' ', OPERAND
} SYMBOL;

int IsNumber(char Ciper);
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE);
int IsPrior(char Operator1, char Operator2);
void GetPostFix(char* InFixExpression, char* PostFixExpression);
double Calculate(char* PostFixExpression);

#endif
