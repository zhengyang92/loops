#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int width, int step, int B, int C, int A,
    uint8_t * bsrc)
{
  for (i = 0; i < width * step; i += step)
    {
      B = bsrc[i - stride];
      bsrc[i + stride] += mid_pred (A, B, (uint8_t) (A + B - C));
      C = B;
      A = bsrc[i + stride];
    }
}
