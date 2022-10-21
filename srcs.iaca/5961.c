#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (int y, int prev_dc, ptrdiff_t stride, int16_t * data, int x, int height)
{
  for (y = 1; y < height - 1; y++)
     { IACA_START
      int dc;
      dc = -prev_dc + data[x + y * stride] * 8 - data[x + (y + 1) * stride];
      dc = (dc * 10923 + 32768) >> 16;
      prev_dc = data[x + y * stride];
      data[x + y * stride] = dc;
} IACA_END }
