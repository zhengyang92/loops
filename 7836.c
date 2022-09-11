#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int y, int offset, ptrdiff_t stride, uint8_t * block, int weight,
    int height, int log2_denom)
{
  for (y = 0; y < height; y++, block += stride)
    {
      block[0] = av_clip_uint8_c ((block[0] * weight + offset) >> log2_denom);
      block[1] = av_clip_uint8_c ((block[1] * weight + offset) >> log2_denom);
      if (8 == 2)
	continue;
      block[2] = av_clip_uint8_c ((block[2] * weight + offset) >> log2_denom);
      block[3] = av_clip_uint8_c ((block[3] * weight + offset) >> log2_denom);
      if (8 == 4)
	continue;
      block[4] = av_clip_uint8_c ((block[4] * weight + offset) >> log2_denom);
      block[5] = av_clip_uint8_c ((block[5] * weight + offset) >> log2_denom);
      block[6] = av_clip_uint8_c ((block[6] * weight + offset) >> log2_denom);
      block[7] = av_clip_uint8_c ((block[7] * weight + offset) >> log2_denom);
      if (8 == 8)
	continue;
      block[8] = av_clip_uint8_c ((block[8] * weight + offset) >> log2_denom);
      block[9] = av_clip_uint8_c ((block[9] * weight + offset) >> log2_denom);
      block[10] =
	av_clip_uint8_c ((block[10] * weight + offset) >> log2_denom);
      block[11] =
	av_clip_uint8_c ((block[11] * weight + offset) >> log2_denom);
      block[12] =
	av_clip_uint8_c ((block[12] * weight + offset) >> log2_denom);
      block[13] =
	av_clip_uint8_c ((block[13] * weight + offset) >> log2_denom);
      block[14] =
	av_clip_uint8_c ((block[14] * weight + offset) >> log2_denom);
      block[15] =
	av_clip_uint8_c ((block[15] * weight + offset) >> log2_denom);
    }
}
