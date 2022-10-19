#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (const int uv_offset, int w, const int rnd, const uint8_t * yuv2, int x,
    int crv, int cgu, const int sh, const uint8_t * yuv0, int16_t * rgb1,
    int16_t * rgb2, const uint8_t * yuv1, int cgv, int cy,
    const int16_t * yuv_offset, int cbu, int16_t * rgb0)
{
  for (x = 0; x < w; x++)
    {
      int y00 = yuv0[x << 0] - yuv_offset[0];
      int u = yuv1[x] - uv_offset, v = yuv2[x] - uv_offset;
      rgb0[x << 0] = av_clip_int16_c ((y00 * cy + crv * v + rnd) >> sh);
      rgb1[x << 0] =
	av_clip_int16_c ((y00 * cy + cgu * u + cgv * v + rnd) >> sh);
      rgb2[x << 0] = av_clip_int16_c ((y00 * cy + cbu * u + rnd) >> sh);
}}
