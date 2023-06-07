#include "AS.h"

void AS_CreateStack(ArrayStack **Stack, int Capacity)
{
  *Stack = (ArrayStack *)malloc(sizeof(ArrayStack));

  (*Stack)->Nodes = (Node *)malloc(sizeof(Node) * Capacity);
  (*Stack)->Capacity = Capacity;
  (*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack *Stack)
{
  free(Stack->Nodes);
  free(Stack);
}

void AS_Push(ArrayStack *Stack, ElementType NewData)
{
  Stack->Nodes[++(Stack->Top)].data = NewData;
}

int AS_Pop(ArrayStack *Stack)
{
  return Stack->Nodes[(Stack->Top)--].data;
}

int AS_Top(ArrayStack *Stack)
{
  return Stack->Nodes[Stack->Top].data;
}

int AS_GetSize(ArrayStack *Stack)
{
  return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack *Stack)
{
  return (Stack->Top == -1);
}

int AS_IsFull(ArrayStack *Stack)
{
  return (Stack->Capacity == Stack->Top + 1);
}
