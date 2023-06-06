#ifndef CDLL_H
#define CDLL_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
  ElementType data;
  struct TagNode* PrevNode;
  struct TagNode* NextNode;
} Node;

Node* CDLL_CreateNode(ElementType NewData);
void CDLL_DestroyNode(Node* Node);
void CDLL_AppendNode(Node** Head, Node* NewNode);
Node* CDLL_GetNodeAt(Node* Head, int Location);
int CDLL_GetNodeCount(Node* Head);
void CDLL_InsertAfter(Node* Current, Node* NewNode);
void CDLL_RemoveNode(Node** Head, Node* Remove);
void PrintReverse(Node* Head);

#endif
