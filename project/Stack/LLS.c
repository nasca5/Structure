#include "LLS.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
  *Stack = (LinkedListStack*)malloc(sizeof(LinkedListStack));
  (*Stack)->List = NULL;
  (*Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack *Stack)
{
  while(! LLS_IsEmpty(Stack))
  {
    Node* Popped = LLS_Pop(Stack);
    LLS_DestroyNode(Popped);
  }

  free(Stack);
}

void LLS_DestroyNode(Node* Node)
{
  free(Node->Data);
  free(Node);
}

Node* LLS_CreateNode(char* NewData)
{
  int i = 0;

  Node* NewNode = (Node*)malloc(sizeof(Node));
  NewNode->Data = (char*)malloc(sizeof(NewData));

  for (; NewData[i] != '\0'; i++)
  {
    NewNode->Data[i] = NewData[i];
  }

  NewNode->Data[i] = '\0';
  NewNode->NextNode = NULL;

  return NewNode;
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
  if (Stack->List == NULL)
  {
    Stack->List = NewNode;
  }

  else
  {
    Stack->Top->NextNode = NewNode;
  }
    Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
  Node* temp = Stack->Top;

  if (Stack->List == Stack->Top)
  {
    Stack->List = NULL;
    Stack->Top = NULL;
  }

  else
  {
    Node* Current = Stack->List; 
    while(Current != NULL && Current->NextNode != Stack->Top)
    {
      Current = Current->NextNode;
    }

    Stack->Top = Current;
    Stack->Top->NextNode = NULL;
  }
  
  return temp;
}

Node* LLS_Top(LinkedListStack* Stack)
{
  return Stack->Top;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
  return (Stack->List == NULL);
}

int LLS_GetSize(LinkedListStack* Stack)
{
  if (Stack->List == Stack->Top)
  {
    if (LLS_IsEmpty(Stack))
    {
      return 0;
    }

    else 
    {
      return 1;
    }
  }

  else
  {
    int Size = 2;
    Node* Current = Stack->List;
  
    while(Current->NextNode != Stack->Top)
    {
      Current = Current->NextNode;
      Size++;
    }

    return Size;
  }
}
