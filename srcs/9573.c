#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, int width, int B, int C, const ptrdiff_t stride2, uint8_t * bsrc,
    int A, int step)
{
  for (i = step; i < width * step; i += step)
    {
      A = bsrc[i - stride2];
      B = bsrc[i - (stride2 + step)];
      C = bsrc[i - step];
      bsrc[i] = (A - B + C + bsrc[i]) & 0xFF;
    }
}
