#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
  ElementType data;
  struct TagNode* PrevNode;
  struct TagNode* NextNode;
} Node;
