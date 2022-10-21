#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (const unsigned int color, int y, ptrdiff_t stride, int x, int b_w,
    uint8_t * dst)
{
  for (x = 0; x < b_w; x++)
     { IACA_START
      dst[x + y * stride] = color;
     } IACA_END
}
