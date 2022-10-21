#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int stride, int y, int offset, int weights, int weightd, uint8_t * dst,
    uint8_t * src, int height, int log2_denom)
{
  for (y = 0; y < height; y++, dst += stride, src += stride)
     { IACA_START
      dst[0] =
	av_clip_uint8_c ((src[0] * weights + dst[0] * weightd +
			  offset) >> (log2_denom + 1));
      dst[1] =
	av_clip_uint8_c ((src[1] * weights + dst[1] * weightd +
			  offset) >> (log2_denom + 1));
      if (8 == 2)
	continue;
      dst[2] =
	av_clip_uint8_c ((src[2] * weights + dst[2] * weightd +
			  offset) >> (log2_denom + 1));
      dst[3] =
	av_clip_uint8_c ((src[3] * weights + dst[3] * weightd +
			  offset) >> (log2_denom + 1));
      if (8 == 4)
	continue;
      dst[4] =
	av_clip_uint8_c ((src[4] * weights + dst[4] * weightd +
			  offset) >> (log2_denom + 1));
      dst[5] =
	av_clip_uint8_c ((src[5] * weights + dst[5] * weightd +
			  offset) >> (log2_denom + 1));
      dst[6] =
	av_clip_uint8_c ((src[6] * weights + dst[6] * weightd +
			  offset) >> (log2_denom + 1));
      dst[7] =
	av_clip_uint8_c ((src[7] * weights + dst[7] * weightd +
			  offset) >> (log2_denom + 1));
      if (8 == 8)
	continue;
      dst[8] =
	av_clip_uint8_c ((src[8] * weights + dst[8] * weightd +
			  offset) >> (log2_denom + 1));
      dst[9] =
	av_clip_uint8_c ((src[9] * weights + dst[9] * weightd +
			  offset) >> (log2_denom + 1));
      dst[10] =
	av_clip_uint8_c ((src[10] * weights + dst[10] * weightd +
			  offset) >> (log2_denom + 1));
      dst[11] =
	av_clip_uint8_c ((src[11] * weights + dst[11] * weightd +
			  offset) >> (log2_denom + 1));
      dst[12] =
	av_clip_uint8_c ((src[12] * weights + dst[12] * weightd +
			  offset) >> (log2_denom + 1));
      dst[13] =
	av_clip_uint8_c ((src[13] * weights + dst[13] * weightd +
			  offset) >> (log2_denom + 1));
      dst[14] =
	av_clip_uint8_c ((src[14] * weights + dst[14] * weightd +
			  offset) >> (log2_denom + 1));
      dst[15] =
	av_clip_uint8_c ((src[15] * weights + dst[15] * weightd +
			  offset) >> (log2_denom + 1));
     } IACA_END
}
