#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int h, uint16_t * src, const int A,
    const ptrdiff_t step, uint16_t * dst, const int E)
{
  for (i = 0; i < h; i++)
     { IACA_START
      dst[0] = ((((A * src[0] + E * src[step + 0])) + 32) >> 6);
      dst[1] = ((((A * src[1] + E * src[step + 1])) + 32) >> 6);
      dst += stride;
      src += stride;
     } IACA_END
}
