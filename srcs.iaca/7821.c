#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int h, const int A, uint8_t * dst, uint8_t * src)
{
  for (i = 0; i < h; i++)
     { IACA_START
      dst[0] = ((((A * src[0])) + 32) >> 6);
      dst += stride;
      src += stride;
     } IACA_END
}
