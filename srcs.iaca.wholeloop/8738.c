#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (int16_t * src2, int wx0, int wx1, int ox1, int x, int width,
    uint16_t * src, int ox0, uint16_t * dst, int log2Wd)
{
  IACA_START for (x = 0; x < width; x++)
    {
      dst[x] =
	av_clip_uintp2_c (((src[x] << (14 - 10)) * wx1 + src2[x] * wx0 +
			   (ox0 + ox1 + 1) * (1 << log2Wd)) >> (log2Wd + 1),
			  10);
     } IACA_END
}
