#include "CDLL.h"

Node *CDLL_CreateNode(ElementType NewData)
{
  Node *NewNode = (Node *)malloc(sizeof(Node));

  NewNode->data = NewData;
  NewNode->PrevNode = NULL;
  NewNode->NextNode = NULL;

  return NewNode;
}

void CDLL_DestroyNode(Node *Node)
{
  free(Node);
}

void CDLL_AppendNode(Node **Head, Node *NewNode)
{
  if (*Head == NULL)
  {
    *Head = NewNode;
    (*Head)->NextNode = (*Head);
    (*Head)->PrevNode = (*Head);
  }

  else
  {
    Node *Tail = (*Head)->PrevNode;

    (*Head)->PrevNode = NewNode;
    Tail->NextNode = NewNode;

    NewNode->PrevNode = Tail;
    NewNode->NextNode = (*Head);
  }
}

Node *CDLL_GetNodeAt(Node *Head, int Location)
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

void CDLL_RemoveNode(Node **Head, Node *Remove)
{
  if (*Head == Remove)
  {
    (*Head)->PrevNode->NextNode = (*Head)->NextNode;
    (*Head)->NextNode->PrevNode = (*Head)->PrevNode;
    (*Head) = (*Head)->NextNode;

    Remove->PrevNode = NULL;
    Remove->NextNode = NULL;

    printf("Remove Head Node.\n");
  }

  else
  {
    Remove->PrevNode->NextNode = Remove->NextNode;
    Remove->NextNode->PrevNode = Remove->PrevNode;

    Remove->NextNode = NULL;
    Remove->PrevNode = NULL;

    printf("Remove Node.\n");
  }
}

void CDLL_InsertAfter(Node *Current, Node *NewNode)
{
  NewNode->NextNode = Current->NextNode;
  NewNode->PrevNode = Current;

  Current->NextNode->PrevNode = NewNode;
  Current->NextNode = NewNode;
}

int CDLL_GetNodeCount(Node *Head)
{
  unsigned int Count = 0;
  Node* Current = Head;
  
  do
  {
    Current = Current->NextNode;
    Count++;
  } while(Current != Head);

  return Count;
}

void PrintReverse(Node* Head)
{
  int Count = CDLL_GetNodeCount(Head);
  Node* Current = CDLL_GetNodeAt(Head, --Count);

  while(Count >= 0)
  {
    printf("List[%d] : %d\n", Count--, Current->data);
    Current = Current->PrevNode;
  } 
}
