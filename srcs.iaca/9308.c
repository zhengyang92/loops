#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int dstStride, int srcStride, const uint8_t * src,
    const uint8_t * cm, uint8_t * dst)
{
  const int h = 2;
  for (i = 0; i < h; i++)
     { IACA_START
      dst[0] =
	(((dst[0]) +
	  cm[(((src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 +
	       (src[-2] + src[3])) + 16) >> 5] + 1) >> 1);
      dst[1] =
	(((dst[1]) +
	  cm[(((src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 +
	       (src[-1] + src[4])) + 16) >> 5] + 1) >> 1);
      dst += dstStride;
      src += srcStride;
     } IACA_END
}
