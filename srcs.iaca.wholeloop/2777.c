#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int top, int width, int x, int lefttop, ptrdiff_t fake_stride,
    const int max, uint16_t * dst, int left)
{
  IACA_START for (x = 1; x < width; x++)
    {
      top = dst[x - fake_stride];
      lefttop = dst[x - (fake_stride + 1)];
      left += top - lefttop + dst[x];
      dst[x] = left & max;
     } IACA_END
}
