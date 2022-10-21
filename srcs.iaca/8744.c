#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (int16_t * src2, int wx0, int wx1, int x, int width, int ox1,
    uint16_t * src, int ox0, uint16_t * dst, int log2Wd)
{
  for (x = 0; x < width; x++)
     { IACA_START
      dst[x] =
	av_clip_uintp2_c (((src[x] << (14 - 12)) * wx1 + src2[x] * wx0 +
			   (ox0 + ox1 + 1) * (1 << log2Wd)) >> (log2Wd + 1),
			  12);
     } IACA_END
}
