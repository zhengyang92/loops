#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t width, uint8_t prev, uint8_t * dst, uint8_t * src)
{
  for (i = 0; i < width; i++)
     { IACA_START
      *dst++ = src[i] - prev;
      prev = src[i];
     } IACA_END
}
