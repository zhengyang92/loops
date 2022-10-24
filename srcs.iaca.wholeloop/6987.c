#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int d1, int d, int16_t * left, int c, int a, int16_t * right,
    int d2, int rnd1, int b)
{
  int rnd2 = 4;
  IACA_START for (i = 0; i < 8; i++)
    {
      a = left[6];
      b = left[7];
      c = right[0];
      d = right[1];
      d1 = a - d;
      d2 = a - d + b - c;
      left[6] = ((a << 3) - d1 + rnd1) >> 3;
      left[7] = ((b << 3) - d2 + rnd2) >> 3;
      right[0] = ((c << 3) + d2 + rnd1) >> 3;
      right[1] = ((d << 3) + d1 + rnd2) >> 3;
      right += 8;
      left += 8;
      rnd2 = 7 - rnd2;
      rnd1 = 7 - rnd1;
     } IACA_END
}
