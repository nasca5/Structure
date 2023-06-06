#include "DLL.h"

Node* DLL_CreateNode(Element NewData)
{
  Node* NewNode = (*Node)malloc(sizeof(Node));

  NewNode->data = NewData;
  NewNode->PrevNode = NULL;
  NewNode->NextNode = NULL;

  return NewNode;
}

void DLL_DestroyNode(Node* Node)
{
  free(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode)
{
  if (*Head == NULL)
  {
    *Head = NewNode;
  }

  else
  {
    Node* Tail = *Head;
    while(Tail->NextNode != NULL)
  }
}
