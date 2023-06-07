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
  Stack->Top++;
  Stack->Nodes[Stack->Top].data = NewData;
  if (Stack->Top + 1 == Stack->Capacity)
  {
    Stack->Capacity = (Stack->Capacity * 1.3);
    Node* temp = Stack->Nodes;
    Stack->Nodes = (Node*)malloc((sizeof(Node) * Stack->Capacity));

    for (int i = 0; i < Stack->Capacity; i++)
    {
      Stack->Nodes[i] = temp[i];
    }

    free(temp);
  }
}

int AS_Pop(ArrayStack *Stack)
{
  int result = Stack->Nodes[Stack->Top--].data;
  if (Stack->Top + 1 < (int)(Stack->Capacity * 0.7))
  {
    Stack->Capacity = (int)(Stack->Capacity * 0.7);
    Node* temp = Stack->Nodes;
    Stack->Nodes = (Node*)malloc(sizeof(Node) * Stack->Capacity);

    for (int i = 0; i < Stack->Top + 1; i++)
    {
      Stack->Nodes[i] = temp[i];
    }

    free(temp);
  }
  return result;
}

int AS_Top(ArrayStack *Stack)
{
  if (Stack->Top != -1)
  {
    return Stack->Nodes[Stack->Top].data;
  }

  else 
  {
    return 0;
  }
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
