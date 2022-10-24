#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int h, const int A, uint8_t * dst, uint8_t * src)
{
  IACA_START for (i = 0; i < h; i++)
    {
      dst[0] = (((dst[0]) + (((A * src[0]) + 32) >> 6) + 1) >> 1);
      dst[1] = (((dst[1]) + (((A * src[1]) + 32) >> 6) + 1) >> 1);
      dst[2] = (((dst[2]) + (((A * src[2]) + 32) >> 6) + 1) >> 1);
      dst[3] = (((dst[3]) + (((A * src[3]) + 32) >> 6) + 1) >> 1);
      dst += stride;
      src += stride;
     } IACA_END
}
