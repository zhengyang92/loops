#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int h, uint8_t * dst, const int A,
    const ptrdiff_t step, uint8_t * src, const int E)
{
  IACA_START for (i = 0; i < h; i++)
    {
      dst[0] =
	(((dst[0]) + ((((A * src[0] + E * src[step + 0])) + 32) >> 6) +
	  1) >> 1);
      dst[1] =
	(((dst[1]) + ((((A * src[1] + E * src[step + 1])) + 32) >> 6) +
	  1) >> 1);
      dst += stride;
      src += stride;
     } IACA_END
}
