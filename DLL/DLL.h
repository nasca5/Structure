#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
  ElementType data;
  struct TagNode* PrevNode;
  struct TagNode* NextNode;
} Node;

Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
void PrintReverse(Node* Head);

#endif
