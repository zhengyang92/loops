#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * tmp, int x, int w2, int16_t * b)
{
  for (; x < w2; x++)
     { IACA_START
      b[2 * x] = (tmp[x] + 1) >> 1;
      b[2 * x + 1] = (((int) (b[x + w2] + (unsigned) (tmp[x]))) + 1) >> 1;
} IACA_END }
