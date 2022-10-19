#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const float *src_b, int w, const float *src_r, const float *src_g, int x,
    uint8_t * dstp_b, uint8_t * dstp_g, uint8_t * dstp_r)
{
  for (x = 0; x < w; x++)
    {
      dstp_r[x] =
	av_clip_uint8_c (src_r[x] * 0.5773502691896258f +
			 src_g[x] * 0.7071067811865475f +
			 src_b[x] * 0.4082482904638631f);
      dstp_g[x] =
	av_clip_uint8_c (src_r[x] * 0.5773502691896258f +
			 src_b[x] * -0.8164965809277261f);
      dstp_b[x] =
	av_clip_uint8_c (src_r[x] * 0.5773502691896258f +
			 src_g[x] * -0.7071067811865475f +
			 src_b[x] * 0.4082482904638631f);
    }
}
