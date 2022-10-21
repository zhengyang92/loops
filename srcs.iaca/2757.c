#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t w, int i, int acc, const uint8_t * src, uint8_t * dst)
{
  for (; i < w; i++)
     { IACA_START
      acc += src[i];
      dst[i] = acc;
     } IACA_END
}
