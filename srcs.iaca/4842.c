#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int i, ptrdiff_t stride, int h, uint16_t * src, const int A,
    uint16_t * dst)
{
  for (i = 0; i < h; i++)
     { IACA_START
      dst[0] = (((dst[0]) + (((A * src[0]) + 32) >> 6) + 1) >> 1);
      dst[1] = (((dst[1]) + (((A * src[1]) + 32) >> 6) + 1) >> 1);
      dst[2] = (((dst[2]) + (((A * src[2]) + 32) >> 6) + 1) >> 1);
      dst[3] = (((dst[3]) + (((A * src[3]) + 32) >> 6) + 1) >> 1);
      dst[4] = (((dst[4]) + (((A * src[4]) + 32) >> 6) + 1) >> 1);
      dst[5] = (((dst[5]) + (((A * src[5]) + 32) >> 6) + 1) >> 1);
      dst[6] = (((dst[6]) + (((A * src[6]) + 32) >> 6) + 1) >> 1);
      dst[7] = (((dst[7]) + (((A * src[7]) + 32) >> 6) + 1) >> 1);
      dst += stride;
      src += stride;
     } IACA_END
}
