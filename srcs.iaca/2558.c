#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * src2, int wx0, int wx1, int ox1, int width, int ox0, int x,
    uint8_t * src, uint8_t * dst, int log2Wd)
{
  for (x = 0; x < width; x++)
     { IACA_START
      dst[x] =
	av_clip_uint8_c (((src[x] << (14 - 8)) * wx1 + src2[x] * wx0 +
			  (ox0 + ox1 + 1) * (1 << log2Wd)) >> (log2Wd + 1));
     } IACA_END
}
