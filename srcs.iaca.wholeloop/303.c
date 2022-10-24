#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (const uint16_t * yuv2, const int uv_offset, int w, const uint16_t * yuv0,
    const int rnd, int crv, int16_t * rgb0, int x, int cgu, const int sh,
    int16_t * rgb1, int16_t * rgb2, int cgv, int cy,
    const int16_t * yuv_offset, int cbu, const uint16_t * yuv1)
{
  IACA_START for (x = 0; x < w; x++)
    {
      int y00 = yuv0[x << 0] - yuv_offset[0];
      int u = yuv1[x] - uv_offset, v = yuv2[x] - uv_offset;
      rgb0[x << 0] = av_clip_int16_c ((y00 * cy + crv * v + rnd) >> sh);
      rgb1[x << 0] =
	av_clip_int16_c ((y00 * cy + cgu * u + cgv * v + rnd) >> sh);
      rgb2[x << 0] = av_clip_int16_c ((y00 * cy + cbu * u + rnd) >> sh);
}IACA_END}
