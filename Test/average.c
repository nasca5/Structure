#include <stdio.h>

int main()
{
  int arr[5][3];

  printf("%d\n", sizeof(arr) / sizeof(arr[1]));
  printf("%d\n", sizeof(arr) / sizeof((*arr)[3]) / 5);
  for (int i = 0; i < sizeof(arr) / sizeof(arr[3]); i++)
  {
    printf("%dth student, input score\n", i + 1);
    printf("math / language / english\n");
    for (int j = 0; j < sizeof(arr) / sizeof(arr[5]); j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  return 0;
}
