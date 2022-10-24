#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, int top, ptrdiff_t stride, int width, const uint8_t * src,
    uint8_t * dst, int left)
{
  int lefttop = 0;
  IACA_START for (i = 1; i < width; i++)
    {
      top = src[i - stride];
      lefttop = src[i - (stride + 1)];
      left = src[i - 1];
      dst[i] = (src[i] - top) - left + lefttop;
     } IACA_END
}
