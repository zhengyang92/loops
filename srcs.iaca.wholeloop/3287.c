#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int y, const unsigned int color, ptrdiff_t stride, int x, int b_w,
    uint8_t * dst)
{
  IACA_START for (x = 0; x < b_w; x++)
    {
      dst[x + y * stride] = color;
     } IACA_END
}
