#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (int d1, int i, int b, int d, int16_t * left, int c, int rnd2,
    ptrdiff_t left_stride, int a, int16_t * right, int d2, int rnd1,
    int flags, ptrdiff_t right_stride)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      a = left[6];
      b = left[7];
      c = right[0];
      d = right[1];
      d1 = a - d;
      d2 = a - d + b - c;
      left[6] = ((a * 8) - d1 + rnd1) >> 3;
      left[7] = ((b * 8) - d2 + rnd2) >> 3;
      right[0] = ((c * 8) + d2 + rnd1) >> 3;
      right[1] = ((d * 8) + d1 + rnd2) >> 3;
      right += right_stride;
      left += left_stride;
      if (flags & 1)
	{
	  rnd2 = 7 - rnd2;
	  rnd1 = 7 - rnd1;
	}
     } IACA_END
}
