#ifndef LLS_H 
#define LLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TagNode
{
  char* Data;
  struct TagNode *NextNode;
} Node;

typedef struct TagLinkedListStack
{
  Node* Top;
  Node* List;
} LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);
Node* LLS_CreateNode(char* NewData);
void LLS_DestroyNode(Node* Node);
void LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);
Node* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);

#endif
