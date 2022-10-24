#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int h, const int A, uint8_t * dst, uint8_t * src,
    const int E, const int step)
{
  IACA_START for (i = 0; i < h; i++)
    {
      dst[0] = ((((A * src[0] + E * src[step + 0])) + 32) >> 6);
      dst += stride;
      src += stride;
     } IACA_END
}
