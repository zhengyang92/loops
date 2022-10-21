#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * bottom, int i, int d1, int d, int16_t * top, int c, int a,
    int d2, int rnd1, int b)
{
  int rnd2 = 4;
  for (i = 0; i < 8; i++)
     { IACA_START
      a = top[48];
      b = top[56];
      c = bottom[0];
      d = bottom[8];
      d1 = a - d;
      d2 = a - d + b - c;
      top[48] = ((a << 3) - d1 + rnd1) >> 3;
      top[56] = ((b << 3) - d2 + rnd2) >> 3;
      bottom[0] = ((c << 3) + d2 + rnd1) >> 3;
      bottom[8] = ((d << 3) + d1 + rnd2) >> 3;
      bottom++;
      top++;
      rnd2 = 7 - rnd2;
      rnd1 = 7 - rnd1;
     } IACA_END
}
