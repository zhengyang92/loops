#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int w, const int rnd, ptrdiff_t s, int cgu, int cgv,
    const int16_t * yuv_offset, int cby, int x, int cry, uint16_t * yuv0,
    const int sh, const int16_t * rgb1, const int16_t * rgb2, int cgy,
    uint16_t * yuv2, int cru, uint16_t * yuv1, const int16_t * rgb0,
    int cburv, const int uv_offset, ptrdiff_t s0, int cbv)
{
  for (x = 0; x < w; x++)
     { IACA_START
      int r00 = rgb0[x << 1], g00 = rgb1[x << 1], b00 = rgb2[x << 1];
      int r01 = rgb0[x * 2 + 1], g01 = rgb1[x * 2 + 1], b01 = rgb2[x * 2 + 1];
      int r10 = rgb0[x * 2 + 0 + s], g10 = rgb1[x * 2 + 0 + s], b10 =
	rgb2[x * 2 + 0 + s];
      int r11 = rgb0[x * 2 + 1 + s], g11 = rgb1[x * 2 + 1 + s], b11 =
	rgb2[x * 2 + 1 + s];
      yuv0[x << 1] =
	av_clip_uintp2_c (yuv_offset[0] +
			  ((r00 * cry + g00 * cgy + b00 * cby + rnd) >> sh),
			  12);
      yuv0[x * 2 + 1] =
	av_clip_uintp2_c (yuv_offset[0] +
			  ((r01 * cry + g01 * cgy + b01 * cby + rnd) >> sh),
			  12);
      yuv0[x * 2 + 0 + s0] =
	av_clip_uintp2_c (yuv_offset[0] +
			  ((r10 * cry + g10 * cgy + b10 * cby + rnd) >> sh),
			  12);
      yuv0[x * 2 + 1 + s0] =
	av_clip_uintp2_c (yuv_offset[0] +
			  ((r11 * cry + g11 * cgy + b11 * cby + rnd) >> sh),
			  12);
      yuv1[x] =
	av_clip_uintp2_c (uv_offset +
			  (((((r00) + (r01) + (r10) + (r11) + 2) >> 2) * cru +
			    (((g00) + (g01) + (g10) + (g11) + 2) >> 2) * cgu +
			    (((b00) + (b01) + (b10) + (b11) +
			      2) >> 2) * cburv + rnd) >> sh), 12);
      yuv2[x] =
	av_clip_uintp2_c (uv_offset +
			  (((((r00) + (r01) + (r10) + (r11) +
			      2) >> 2) * cburv + (((g00) + (g01) + (g10) +
						   (g11) + 2) >> 2) * cgv +
			    (((b00) + (b01) + (b10) + (b11) + 2) >> 2) * cbv +
			    rnd) >> sh), 12);
} IACA_END }
