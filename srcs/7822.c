#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int h, const int D, const int A, const int B,
    const int C, uint8_t * dst, uint8_t * src)
{
  for (i = 0; i < h; i++)
    {
      dst[0] =
	((((A * src[0] + B * src[1] + C * src[stride + 0] +
	    D * src[stride + 1])) + 32) >> 6);
      dst[1] =
	((((A * src[1] + B * src[2] + C * src[stride + 1] +
	    D * src[stride + 2])) + 32) >> 6);
      dst += stride;
      src += stride;
    }
}
