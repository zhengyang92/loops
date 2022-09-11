#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int w, const int rnd, uint8_t * yuv1, int cgu, int cgv,
    const int16_t * yuv_offset, int cby, uint8_t * yuv0, int x, int cry,
    const int sh, const int16_t * rgb1, const int16_t * rgb2, int cgy,
    int cru, const int16_t * rgb0, uint8_t * yuv2, int cburv,
    const int uv_offset, int cbv)
{
  for (x = 0; x < w; x++)
    {
      int r00 = rgb0[x << 1], g00 = rgb1[x << 1], b00 = rgb2[x << 1];
      int r01 = rgb0[x * 2 + 1], g01 = rgb1[x * 2 + 1], b01 = rgb2[x * 2 + 1];
      yuv0[x << 1] =
	av_clip_uint8_c (yuv_offset[0] +
			 ((r00 * cry + g00 * cgy + b00 * cby + rnd) >> sh));
      yuv0[x * 2 + 1] =
	av_clip_uint8_c (yuv_offset[0] +
			 ((r01 * cry + g01 * cgy + b01 * cby + rnd) >> sh));
      yuv1[x] =
	av_clip_uint8_c (uv_offset +
			 (((((r00) + (r01) + 1) >> 1) * cru +
			   (((g00) + (g01) + 1) >> 1) * cgu +
			   (((b00) + (b01) + 1) >> 1) * cburv + rnd) >> sh));
      yuv2[x] =
	av_clip_uint8_c (uv_offset +
			 (((((r00) + (r01) + 1) >> 1) * cburv +
			   (((g00) + (g01) + 1) >> 1) * cgv +
			   (((b00) + (b01) + 1) >> 1) * cbv + rnd) >> sh));
}}
