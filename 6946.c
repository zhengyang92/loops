#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int width, int B, int C, int A, uint8_t * bsrc)
{
  for (i = 1; i < width; i++)
    {
      B = bsrc[i - stride];
      bsrc[i] += mid_pred (A, B, (uint8_t) (A + B - C));
      C = B;
      A = bsrc[i];
    }
}
