#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
  ElementType data;
} Node;

typedef struct TagArrayStack
{
  int Capacity;
  int Top;
  Node *Nodes;
} ArrayStack;

void AS_CreateStack(ArrayStack **Stack, int Capacity);
void AS_DestroyStack(ArrayStack *Stack);
void AS_Push(ArrayStack *Stack, ElementType NewData);
int AS_Pop(ArrayStack *Stack);
int AS_Top(ArrayStack *Stack);
int AS_GetSize(ArrayStack *Stack);
int AS_IsEmpty(ArrayStack *Stack);
int AS_IsFull(ArrayStack *Stack);
