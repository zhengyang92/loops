#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int w, int i, int radius, const uint16_t * filter, int k, int filt_w,
    ptrdiff_t src_stride, int j, const uint16_t * src)
{
  int sum = 0;
  for (k = 0; k < filt_w; k++)
     { IACA_START
      int j_tap =
	((j - radius + k) >= 0 ? (j - radius + k) : (-(j - radius + k)));
      if (j_tap >= w)
	{
	  j_tap = w - (j_tap - w + 1);
	}
      sum += filter[k] * src[i * src_stride + j_tap];
     } IACA_END
}
