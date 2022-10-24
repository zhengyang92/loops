#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (unsigned int acc, ptrdiff_t w, int i, unsigned int mask, uint16_t * dst,
    const uint16_t * src)
{
  IACA_START for (i = 0; i < w - 1; i++)
    {
      acc += src[i];
      dst[i] = acc &= mask;
      i++;
      acc += src[i];
      dst[i] = acc &= mask;
     } IACA_END
}
