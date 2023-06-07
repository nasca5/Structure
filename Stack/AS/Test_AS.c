#include "AS.h"

int main()
{
  int i = 0;
  ArrayStack *Stack;

  AS_CreateStack(&Stack, 10);

  AS_Push(Stack, 3);
  AS_Push(Stack, 37);
  AS_Push(Stack, 11);
  AS_Push(Stack, 12);

  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

  int size = AS_GetSize(Stack);

  for (; i < size; i++)
  {
    printf("Popped : %d\n", AS_Pop(Stack));

    if (!AS_IsEmpty(Stack))
    {
      printf("Current Top : %d\n", AS_Top(Stack));
    }

    else
    {
      printf("Stack is Empty..\n");
    }
  }

  printf("Stack is Full? : %d", AS_IsFull(Stack));

  AS_DestroyStack(Stack);

  return 0;
}
