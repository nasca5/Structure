#include "DLL.h"

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
    NewNode = DLL_CreateNode(i);
    DLL_AppendNode(&List, NewNode);
  }

  // printf List
  Count = DLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = DLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->data);
  }

  // insert NewNode after 3rd index of List
  printf("\nInserting 3000 After [2]...\n");

  Current = DLL_GetNodeAt(List, 2);
  DLL_InsertAfter(Current, DLL_CreateNode(3000));

  // printf List
  Count = DLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = DLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->data);
  }

  PrintReverse(List);

  // destroy all Node from memory space
  printf("\nDestroying List...\n");

  Count = DLL_GetNodeCount(List);

  for (i = 0; i < Count; i++)
  {
    Current = DLL_GetNodeAt(List, 0);

    if (Current != NULL)
    {
      DLL_RemoveNode(&List, Current);
      DLL_DestroyNode(Current);
    }
  }

  return 0;
}
