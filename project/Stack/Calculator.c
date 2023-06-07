#include "Calculator.h"

char NUMBER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

int IsNumber(char Cipher)
{
  int i = 0;
  int ArrayLength = sizeof(NUMBER);

  for (; i < ArrayLength; i++)
  {
    if (Cipher == NUMBER[i])
    {
      return 1;
    }
  }

  return 0;
}

unsigned int GetNextToken(char* Expression, char* Token, int* TYPE)
{
  unsigned int i = 0;

  for (; Expression[i] != 0; i++) 
  {
    Token[i] = Expression[i];

    if (IsNumber(Expression[i]) == 1)
    {
      *TYPE = OPERAND;

      if (IsNumber(Expression[i + 1]) != 1)
      {
        break;
      }
    }

    else
    {
      *TYPE = Expression[i];
      break;
    }
  }

  Token[++i] = '\0';
  return i;
}

int GetPriority(char Operator, int InStack) 
{
  int Priority = -1;

  switch (Operator)
  {
    case LEFT_PARENTHESIS:
      if (InStack)
      {
        Priority = 3;
      }

      else
      {
        Priority = 0;
      }
      break;

    case MULTIPLY:
    case DIVIDE:
      Priority = 1;
      break;

    case PLUS:
    case MINUS:
      Priority = 2;
      break;
  }

  return Priority;
}

int IsPrior(char OperatorInStack, char OperatorInToken)
{
  return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

void GetPostFix(char* InFixExpression, char* PostFixExpression)
{
  LinkedListStack* Stack;

  char Token[32];
  int type = -1;
  unsigned int Position = 0;
  unsigned int Length = strlen(InFixExpression);

  LLS_CreateStack(&Stack);

  while(Position < Length)
  {
    Position += GetNextToken(&InFixExpression[Position], Token, &type);

    if (type == OPERAND)
    {
      strcat(PostFixExpression, Token);
      strcat(PostFixExpression, " ");
    }

    else if (type == RIGHT_PARENTHESIS)
    {
      while(! LLS_IsEmpty(Stack))
      {
        Node* Popped = LLS_Pop(Stack);

        if (Popped->Data[0] == LEFT_PARENTHESIS)
        {
          LLS_DestroyNode(Popped);
          break;
        }
        else
        {
          strcat(PostFixExpression, Popped->Data);
          LLS_DestroyNode(Popped);
        }
      }
    }

    else if (type == SPACE)
    {
      continue;
    }

    else
    {
      while (! LLS_IsEmpty(Stack) && ! IsPrior(LLS_Top(Stack)->Data[0], Token[0]))
      {
        Node* Popped = LLS_Pop(Stack);

        if (Popped->Data[0] != LEFT_PARENTHESIS)
        {
          strcat(PostFixExpression, Popped->Data);
        }

        LLS_DestroyNode(Popped);
      }

      LLS_Push(Stack, LLS_CreateNode(Token));
    }
  }

  while(! LLS_IsEmpty(Stack))
  {
    Node *Popped = LLS_Pop(Stack);

    if (Popped->Data[0] != LEFT_PARENTHESIS)
    {
      strcat(PostFixExpression, Popped->Data);
    }

    LLS_DestroyNode(Popped);
  }

  LLS_DestroyStack(Stack);
}

double Calculate(char* PostFixExpression)
{
  LinkedListStack* Stack;
  Node* ResultNode;

  double Result;
  char Token[32];
  int type = -1;
  unsigned int Read = 0;
  unsigned int Length = strlen(PostFixExpression);

  LLS_CreateStack(&Stack);

  while(Read < Length)
  {
    Read += GetNextToken(&PostFixExpression[Read], Token, &type);

    if (type == SPACE)
    {
      continue;
    }

    if (type == OPERAND)
    {
      Node* NewNode = LLS_CreateNode(Token);
      LLS_Push(Stack, NewNode);
    }

    else
    {
      char ResultString[32];
      double Operator1, Operator2, TempResult;
      Node* OperatorNode;

      OperatorNode = LLS_Pop(Stack);
      Operator2 = atof(OperatorNode->Data);
      LLS_DestroyNode(OperatorNode);

      OperatorNode = LLS_Pop(Stack);
      Operator1 = atof(OperatorNode->Data);
      LLS_DestroyNode(OperatorNode);

      switch(type)
      {
        case PLUS: TempResult = Operator1 + Operator2; break;
        case MINUS: TempResult = Operator1 - Operator2; break;
        case MULTIPLY: TempResult = Operator1 * Operator2; break;
        case DIVIDE: TempResult = Operator1 / Operator2; break;
      }

      gcvt(TempResult, 10, ResultString);
      LLS_Push(Stack, LLS_CreateNode(ResultString));
    }
  }

  ResultNode = LLS_Pop(Stack);
  Result = atof(ResultNode->Data);

  LLS_DestroyNode(ResultNode);
  LLS_DestroyStack(Stack);

  return Result;
}
