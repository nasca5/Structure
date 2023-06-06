#include <stdio.h>

void bubble_sort(int *ptr, int size);

int main()
{
  int arr[10];
  int i = 0;

  printf("input 10 num : ");
  for (; i < 10; i++)
  {
    scanf("%d", &arr[i]);
  }

  bubble_sort(arr, sizeof(arr) / sizeof(int));
  for (i -= 1; i >= 0; i--)
  {
    printf("%dth num is %d\n", 10 - i, arr[i]);
  }
  return 0;
}

void bubble_sort(int *ptr, int size)
{
  for (int i = 1; i < size; i++)
  {
    for (int j = 0; j < size - i; j++)
    {
      if (ptr[j] > ptr[j + 1])
      {
        int temp = ptr[j];
        ptr[j] = ptr[j + 1];
        ptr[j + 1] = temp;
      }
    }
  }
}
