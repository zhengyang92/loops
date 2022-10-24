#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int i, int dstStride, int srcStride, uint16_t * dst, const uint16_t * src)
{
  const int h = 4;
  IACA_START for (i = 0; i < h; i++)
    {
      dst[0] =
	av_clip_uintp2_c ((((src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 +
			    (src[-2] + src[3])) + 16) >> 5, 10);
      dst[1] =
	av_clip_uintp2_c ((((src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 +
			    (src[-1] + src[4])) + 16) >> 5, 10);
      dst[2] =
	av_clip_uintp2_c ((((src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 +
			    (src[0] + src[5])) + 16) >> 5, 10);
      dst[3] =
	av_clip_uintp2_c ((((src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 +
			    (src[1] + src[6])) + 16) >> 5, 10);
      dst += dstStride;
      src += srcStride;
     } IACA_END
}
