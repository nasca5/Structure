#include "AS.h"

int main()
{
  int i = 0;
  ArrayStack *Stack;

  AS_CreateStack(&Stack, 10);

  printf("When you Push NewNode...\n\n");

  AS_Push(Stack, 1);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 2);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 3);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 4);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 5);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 6);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 7);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 8);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 9);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 10);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 11);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 12);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 13);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
  AS_Push(Stack, 14);
  printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));


  int size = AS_GetSize(Stack);

  printf("When you Pop Head Node..\n\n");

  for (; i < size; i++)
  {
    printf("Popped : %d, ", AS_Pop(Stack));

    if (!AS_IsEmpty(Stack))
    {
      printf("Current Top : %d\n", AS_Top(Stack));
      printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
    }

    else
    {
      printf("Stack is Empty..\n");
      printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
    }
  }

  printf("Stack is Full? : %d", AS_IsFull(Stack));

  AS_DestroyStack(Stack);

  return 0;
}
