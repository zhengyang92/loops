#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int top, int x, int width, int lefttop, ptrdiff_t fake_stride,
    const int max, uint16_t * dst, int left)
{
  for (x = 1; x < width; x++)
    {
      top = dst[x - fake_stride];
      lefttop = dst[x - (fake_stride + 1)];
      left += top - lefttop + dst[x];
      dst[x] = left & max;
    }
}
