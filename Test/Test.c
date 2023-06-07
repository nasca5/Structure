
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  char *str;
  double num;
  int dec, sign, ndig = 5;

  /* a regular number */
  num = 9.876;
  str = fcvt(num, ndig, &dec, &sign);
  printf("string  = %10s decimal place = %d sign = %d\n", str, dec, sign);

  return 0;
}
