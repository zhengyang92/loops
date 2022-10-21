#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int weights, const uint8_t * src, int weightd, uint8_t * dst,
    int log2_denom)
{
  for (x = 0; x < 16; x++)
     { IACA_START
      dst[x] =
	av_clip_uint8_c ((src[x] * weights + dst[x] * weightd +
			  (1 << (log2_denom - 1))) >> log2_denom);
      dst[x + 1] =
	av_clip_uint8_c ((src[x + 1] * weights + dst[x + 1] * weightd +
			  (1 << (log2_denom - 1))) >> log2_denom);
     } IACA_END
}
