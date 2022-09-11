#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int width, int step, int B, int C, int A,
    uint8_t * bsrc)
{
  for (i = step; i < width * step; i += step)
    {
      A = bsrc[i - stride];
      B = bsrc[i - (stride + step)];
      C = bsrc[i - step];
      bsrc[i] = (A - B + C + bsrc[i]) & 0xFF;
    }
}
