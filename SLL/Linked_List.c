#include "LinkedList.h"

Node *SLL_CreateNode(ElementType data)
{
  Node *NewNode = (Node *)malloc(sizeof(Node));

  NewNode->data = data;
  NewNode->NextNode = NULL;

  return NewNode;
}

void SLL_DestroyNode(Node *Remove)
{
  free(Remove);
}

void SLL_AppendNode(Node **Head, Node *NewNode)
{
  if (*Head == NULL)
  {
    *Head = NewNode;
  }

  else
  {
    Node *Tail = *Head;
    while (Tail->NextNode != NULL)
    {
      Tail = Tail->NextNode;
    }
    Tail->NextNode = NewNode;
  }
}

Node *SLL_GetNodeAt(Node *Head, int Location)
{
  Node *Current = Head;
  while (Current != NULL && --Location >= 0)
  {
    Current = Current->NextNode;
  }

  if (Current != NULL)
  {
    return Current;
  }

  else
  {
    printf("a Node you find doesn't exist. please check again.\n");
    return Current;
  }
}

void SLL_InsertNewHead(Node **Head, Node *NewHead)
{
  if (*Head == NULL)
  {
    *Head = NewHead;
  }

  else
  {
    NewHead->NextNode = *Head;
    *Head = NewHead;
  }
}

void SLL_RemoveNode(Node **Head, Node *Remove)
{
  if (*Head == Remove)
  {
    (*Head) = Remove->NextNode;
    printf("Remove Head Node\n");
  }

  Node *Current = *Head;
  while (Current != NULL && Current != Remove)
  {
    Current = Current->NextNode;
  }

  if (Current != NULL)
  {
    printf("Removing Node is success.\n");
    Current->NextNode = Remove->NextNode;
  }
}

void SLL_InsertAfter(Node *Current, Node *NewNode)
{
  NewNode->NextNode = Current->NextNode;
  Current->NextNode = NewNode;
}

int SLL_GetNodeCount(Node *Head)
{
  int count = 0;
  while (Head != NULL)
  {
    Head = Head->NextNode;
    count++;
  }
  return count;
}

void SLL_InsertBefore(Node **Head, Node *Current, Node *NewNode)
{
  if (*Head == Current)
  {
    NewNode->NextNode = *Head;
    *Head = NewNode;
  }

  else
  {
    Node *Before = *Head;
    while (Before->NextNode != Current && Before != NULL)
    {
      Before = Before->NextNode;
    }
    if (Before != NULL)
    {
      Before->NextNode = NewNode;
      NewNode->NextNode = Current;
    }
  }
}

void SLL_DestroyAllNode(Node *Head)
{
  Node *Destroy;
  while (Head != NULL)
  {
    Destroy = Head;
    Head = Head->NextNode;
    SLL_DestroyNode(Destroy);
    printf("Remove Node\n");
  }
}
