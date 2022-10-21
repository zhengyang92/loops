#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int w2, int x, int16_t * temp, int16_t * b)
{
  for (x = 0; x < w2; x++)
     { IACA_START
      temp[x] = ((int) (b[x] - (unsigned) ((int) (b[x + w2] + 1U) >> 1)));
      temp[x + w2] = ((int) (b[x + w2] + (unsigned) (temp[x])));
} IACA_END }
