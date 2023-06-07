#include "LLS.h"

int main() {
  int i = 0;
  int Count = 0;
  Node* Popped;

  LinkedListStack* Stack;
  
  LLS_CreateStack(&Stack);

  LLS_Push(Stack, LLS_CreateNode("abc"));
  LLS_Push(Stack, LLS_CreateNode("def"));
  LLS_Push(Stack, LLS_CreateNode("ghi"));
  LLS_Push(Stack, LLS_CreateNode("jkl"));

  Count = LLS_GetSize(Stack);
  printf("Size : %d / Top : %s\n", LLS_GetSize(Stack), LLS_Top(Stack)->Data);

  for (; i < Count; i++)
  {
    Popped = LLS_Pop(Stack);

    printf("Popped : %s, ", Popped->Data);

    LLS_DestroyNode(Popped);

    if (! LLS_IsEmpty(Stack))
    {
      printf("Current Top : %s\n", LLS_Top(Stack)->Data);
    }
    else
    {
      printf("Stack is Empty..\n");
    }
  }

  LLS_DestroyStack(Stack);
  
  return 0;
}
