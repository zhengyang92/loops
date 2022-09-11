#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int h, const int D, const int A, const int B,
    const int C, uint8_t * dst, uint8_t * src)
{
  for (i = 0; i < h; i++)
    {
      dst[0] =
	((((A * src[0] + B * src[1] + C * src[stride + 0] +
	    D * src[stride + 1])) + 32) >> 6);
      dst += stride;
      src += stride;
    }
}
