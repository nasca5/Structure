#include "LinkedList.h"

int main()
{
  int i = 0;
  int Count = 0;
  Node *List = NULL;
  Node *Current = NULL;
  Node *NewNode = NULL;

  for (; i < 5; i++)
  {
    NewNode = SLL_CreateNode(i);
    SLL_AppendNode(&List, NewNode);
  }

  NewNode = SLL_CreateNode(-1);
  SLL_InsertNewHead(&List, NewNode);

  NewNode = SLL_CreateNode(-2);
  SLL_InsertNewHead(&List, NewNode);

  // print List
  Count = SLL_GetNodeCount(List);
  for (i = 0; i < 5; i++)
  {
    Current = SLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->data);
  }

  // insert NewNode after 3rd of List
  printf("\nInserting 3000 After [2]...\n\n");

  Current = SLL_GetNodeAt(List, 2);
  SLL_InsertAfter(Current, SLL_CreateNode(3000));

  Current = SLL_GetNodeAt(List, 3);
  SLL_InsertBefore(&List, Current, SLL_CreateNode(2000));
  // print List
  Count = SLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = SLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->data);
  }

  // Remove all Node at memory space
  printf("\nDestroying List...\n");

  SLL_DestroyAllNode(List);

  return 0;
}
