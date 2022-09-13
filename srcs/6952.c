#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int width, int step, int A, uint8_t * bsrc)
{
  for (i = 0; i < width * step; i += step)
    {
      bsrc[stride + i] += A;
      A = bsrc[stride + i];
    }
}
