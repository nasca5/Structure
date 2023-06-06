#include "DLL.h"

Node *DLL_CreateNode(ElementType NewData)
{
  Node *NewNode = (Node *)malloc(sizeof(Node));

  NewNode->data = NewData;
  NewNode->PrevNode = NULL;
  NewNode->NextNode = NULL;

  return NewNode;
}

void DLL_DestroyNode(Node *Node)
{
  free(Node);
}

void DLL_AppendNode(Node **Head, Node *NewNode)
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
    NewNode->PrevNode = Tail;
  }
}

Node *DLL_GetNodeAt(Node *Head, int Location)
{
  while (Head != NULL && --Location >= 0)
  {
    Head = Head->NextNode;
  }

  if (Head != NULL)
  {
    return Head;
  }

  else
  {
    printf("There is any Node to find. please check again.\n");
    return NULL;
  }
}

void DLL_RemoveNode(Node **Head, Node *Remove)
{
  if (*Head == Remove)
  {
    *Head = Remove->NextNode;

    if ((*Head) != NULL)
    {
      (*Head)->PrevNode = NULL;
    }
    Remove->PrevNode = NULL;
    Remove->NextNode = NULL;
    printf("Remove Head Node.\n");
  }

  else
  {
    if (Remove->PrevNode != NULL)
    {
      Remove->PrevNode->NextNode = Remove->NextNode;
    }

    if (Remove->NextNode != NULL)
    {
      Remove->NextNode->PrevNode = Remove->PrevNode;
    }
    printf("Remove Node.\n");
  }
}

void DLL_InsertAfter(Node *Current, Node *NewNode)
{
  NewNode->NextNode = Current->NextNode;
  NewNode->PrevNode = Current;

  if (Current->NextNode != NULL)
  {
    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
  }
}

int DLL_GetNodeCount(Node *Head)
{
  unsigned int Count = 0;
  while (Head != NULL)
  {
    Head = Head->NextNode;
    Count++;
  }

  return Count;
}

void PrintReverse(Node* Head)
{
  int Count = DLL_GetNodeCount(Head);
  Head = DLL_GetNodeAt(Head, --Count);
  
  while(Head != NULL)
  {
    printf("List[%d] : %d\n", Count--, Head->data);
    Head = Head->PrevNode;
  }
}
