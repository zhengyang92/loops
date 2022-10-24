#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (int i, int d1, int b, int d, int16_t * left, int c,
    ptrdiff_t right_stride, int rnd2, int a, int16_t * right, int d2,
    int rnd1, int flags, ptrdiff_t left_stride)
{
  IACA_START for (i = 0; i < 8; i++)
    {
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
