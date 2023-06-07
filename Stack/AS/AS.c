#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
  ElementType data;
} Node;

typedef struct TagArrayStack
{
  int Tapacity;
  int Top;
  Node *Nodes;
} ArrayStack;

void AS_CreateStack(ArrayStack **Stack, int Capacity);
void AS_DestroyStack(ArrayStack *Stack);
void AS_Push(ArrayStack *Stack, ElementType NewData);

int main()
{

  return 0;
}

void AS_CreateStack(ArrayStack **Stack, int Capacity)
{
  *Stack = (ArrayStack *)malloc(sizeof(ArrayStack));

  (*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);
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
