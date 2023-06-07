#include "CDLL.h"

int main()
{
  int i = 0;
  int Count = 0;
  Node *List = NULL;
  Node *NewNode = NULL;
  Node *Current = NULL;

  // add five NewNode
  for (; i < 5; i++)
  {
    NewNode = CDLL_CreateNode(i);
    CDLL_AppendNode(&List, NewNode);
  }

  // printf List
  Count = CDLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = CDLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->data);
  }

  // insert NewNode after 3rd index of List
  printf("\nInserting 3000 After [2]...\n");

  Current = CDLL_GetNodeAt(List, 2);
  CDLL_InsertAfter(Current, CDLL_CreateNode(3000));

  // printf List
  Count = CDLL_GetNodeCount(List);
  for (i = 0; i < Count * 2; i++)
  {
    Current = CDLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->data);
  }

  PrintReverse(List);

  // destroy all Node from memory space
  printf("\nDestroying List...\n");

  Count = CDLL_GetNodeCount(List);

  for (i = 0; i < Count; i++)
  {
    Current = CDLL_GetNodeAt(List, 0);

    if (Current != NULL)
    {
      CDLL_RemoveNode(&List, Current);
      CDLL_DestroyNode(Current);
    }
  }

  return 0;
}
