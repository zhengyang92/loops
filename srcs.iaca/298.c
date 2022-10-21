#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (int w, const int rnd, int cgu, int cgv, const int16_t * yuv_offset,
    int cby, int x, int cry, uint16_t * yuv0, const int sh,
    const int16_t * rgb1, const int16_t * rgb2, int cgy, uint16_t * yuv2,
    int cru, uint16_t * yuv1, const int16_t * rgb0, int cburv,
    const int uv_offset, int cbv)
{
  for (x = 0; x < w; x++)
     { IACA_START
      int r00 = rgb0[x << 0], g00 = rgb1[x << 0], b00 = rgb2[x << 0];
      yuv0[x << 0] =
	av_clip_uintp2_c (yuv_offset[0] +
			  ((r00 * cry + g00 * cgy + b00 * cby + rnd) >> sh),
			  10);
      yuv1[x] =
	av_clip_uintp2_c (uv_offset +
			  (((r00) * cru + (g00) * cgu + (b00) * cburv +
			    rnd) >> sh), 10);
      yuv2[x] =
	av_clip_uintp2_c (uv_offset +
			  (((r00) * cburv + (g00) * cgv + (b00) * cbv +
			    rnd) >> sh), 10);
} IACA_END }
