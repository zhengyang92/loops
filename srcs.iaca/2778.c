#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (ptrdiff_t stride, int width, int interlaced, int lefttop,
    ptrdiff_t fake_stride, int k, const int max, uint16_t * dst, int height,
    int left)
{
  for (k = 1 + interlaced; k < height; k++)
     { IACA_START
      magicyuv_median_pred16 (dst, dst - fake_stride, dst, width, &left,
			      &lefttop, max);
      lefttop = left = dst[0];
      dst += stride;
     } IACA_END
}
