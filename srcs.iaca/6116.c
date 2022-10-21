#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int h, uint16_t * src, const int A,
    uint16_t * dst)
{
  for (i = 0; i < h; i++)
     { IACA_START
      dst[0] = (((A * src[0]) + 32) >> 6);
      dst[1] = (((A * src[1]) + 32) >> 6);
      dst[2] = (((A * src[2]) + 32) >> 6);
      dst[3] = (((A * src[3]) + 32) >> 6);
      dst += stride;
      src += stride;
     } IACA_END
}
