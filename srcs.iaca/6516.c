#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int top, int x, int width, int lefttop, ptrdiff_t fake_stride,
    uint8_t * dst, int left)
{
  for (x = 1; x < width; x++)
    {
      top = dst[x - fake_stride];
      lefttop = dst[x - (fake_stride + 1)];
      left += top - lefttop + dst[x];
      dst[x] = left;
    }
}
