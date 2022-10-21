#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int tmp[16], int i, int16_t * out)
{
  for (i = 0; i < 4; ++i)
     { IACA_START
      const int a0 = (tmp[0 + i] + tmp[12 + i]);
      const int a1 = (tmp[4 + i] + tmp[8 + i]);
      const int a2 = (tmp[4 + i] - tmp[8 + i]);
      const int a3 = (tmp[0 + i] - tmp[12 + i]);
      out[0 + i] = (a0 + a1 + 7) >> 4;
      out[4 + i] = ((a2 * 2217 + a3 * 5352 + 12000) >> 16) + (a3 != 0);
      out[8 + i] = (a0 - a1 + 7) >> 4;
      out[12 + i] = ((a3 * 2217 - a2 * 5352 + 51000) >> 16);
} IACA_END }
