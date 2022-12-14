#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t width, uint8_t prev, uint8_t * dst, uint8_t * src)
{
  IACA_START for (i = 0; i < width; i++)
    {
      *dst++ = src[i] - prev;
      prev = src[i];
     } IACA_END
}
