#include <stdio.h>
#include <string.h>

#include "Calculator.h"

int main()
{
  char InFixExpression[100];
  char PostFixExpression[100];

  double Result = 0.0;

  memset(InFixExpression, 0, sizeof(InFixExpression));
  memset(PostFixExpression, 0, sizeof(PostFixExpression));

  printf("%d\n", OPERAND);
  printf("Enter InFix Expression : ");
  scanf("%[^\n]s", InFixExpression);

  GetPostFix(InFixExpression, PostFixExpression);

  printf("InFix : %s\n", InFixExpression);
  printf("PostFix : %s\n", PostFixExpression);

  Result = Calculate(PostFixExpression);

  printf("Calculation Result : %f\n", Result);

  return 0;
}
