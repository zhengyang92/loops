#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int h, const int A, uint8_t * dst,
    const ptrdiff_t step, uint8_t * src, const int E)
{
  for (i = 0; i < h; i++)
    {
      dst[0] = ((((A * src[0] + E * src[step + 0])) + 32) >> 6);
      dst[1] = ((((A * src[1] + E * src[step + 1])) + 32) >> 6);
      dst[2] = ((((A * src[2] + E * src[step + 2])) + 32) >> 6);
      dst[3] = ((((A * src[3] + E * src[step + 3])) + 32) >> 6);
      dst += stride;
      src += stride;
    }
}
