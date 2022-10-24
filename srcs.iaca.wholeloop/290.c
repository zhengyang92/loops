#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int w, const int rnd, uint8_t * yuv1, int cgu, int cgv,
    const int16_t * yuv_offset, int cby, uint8_t * yuv0, int x, int cry,
    const int sh, const int16_t * rgb1, const int16_t * rgb2, int cgy,
    int cru, const int16_t * rgb0, uint8_t * yuv2, int cburv,
    const int uv_offset, int cbv)
{
  IACA_START for (x = 0; x < w; x++)
    {
      int r00 = rgb0[x << 0], g00 = rgb1[x << 0], b00 = rgb2[x << 0];
      yuv0[x << 0] =
	av_clip_uint8_c (yuv_offset[0] +
			 ((r00 * cry + g00 * cgy + b00 * cby + rnd) >> sh));
      yuv1[x] =
	av_clip_uint8_c (uv_offset +
			 (((r00) * cru + (g00) * cgu + (b00) * cburv +
			   rnd) >> sh));
      yuv2[x] =
	av_clip_uint8_c (uv_offset +
			 (((r00) * cburv + (g00) * cgv + (b00) * cbv +
			   rnd) >> sh));
}IACA_END}
