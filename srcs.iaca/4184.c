#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const int uv_offset, int w, const int rnd, const uint8_t * yuv2, int crv,
    int x, int16_t * rgb1, const uint8_t * yuv0, const int sh, int cgu,
    const uint8_t * yuv1, int16_t * rgb2, int cgv, int cy,
    const int16_t * yuv_offset, int cbu, int16_t * rgb0)
{
  for (x = 0; x < w; x++)
     { IACA_START
      int y00 = yuv0[x << 1] - yuv_offset[0];
      int y01 = yuv0[2 * x + 1] - yuv_offset[0];
      int u = yuv1[x] - uv_offset, v = yuv2[x] - uv_offset;
      rgb0[x << 1] = av_clip_int16_c ((y00 * cy + crv * v + rnd) >> sh);
      rgb0[2 * x + 1] = av_clip_int16_c ((y01 * cy + crv * v + rnd) >> sh);
      rgb1[x << 1] =
	av_clip_int16_c ((y00 * cy + cgu * u + cgv * v + rnd) >> sh);
      rgb1[2 * x + 1] =
	av_clip_int16_c ((y01 * cy + cgu * u + cgv * v + rnd) >> sh);
      rgb2[x << 1] = av_clip_int16_c ((y00 * cy + cbu * u + rnd) >> sh);
      rgb2[2 * x + 1] = av_clip_int16_c ((y01 * cy + cbu * u + rnd) >> sh);
} IACA_END }
