#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int dstStride, const uint8_t * src, int srcStride,
    const uint8_t * cm, uint8_t * dst)
{
  const int h = 2;
  for (i = 0; i < h; i++)
    {
      dst[0] =
	cm[(((src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 +
	     (src[-2] + src[3])) + 16) >> 5];
      dst[1] =
	cm[(((src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 +
	     (src[-1] + src[4])) + 16) >> 5];
      dst += dstStride;
      src += srcStride;
    }
}
