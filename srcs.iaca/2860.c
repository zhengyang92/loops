#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *tab0, int v1, unsigned int tmp0, int v2, int len, int *tab1, int j)
{
  for (j = 0; j < len; j++)
     { IACA_START
      tmp0 = tab0[j];
      tab0[j] = (((int64_t) ((int) (tmp0)) * (int64_t) ((v1))) >> (23));
      tab1[j] = (((int64_t) ((int) (tmp0)) * (int64_t) ((v2))) >> (23));
} IACA_END }
