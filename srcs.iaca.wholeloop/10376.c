#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *mask, int i, char *a)
{
  int n = 1;
  IACA_START for (i = 0; i < n; ++i)
    {
      int val = atoi (a);
      mask[i] = val;
      a = strchr (a, ',') + 1;
}IACA_END}
