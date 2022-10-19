#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int w, const int rnd, int cgu, int cgv, const int16_t * yuv_offset,
    int cby, int x, int cry, uint16_t * yuv0, const int sh, unsigned int mask,
    const int16_t * rgb1, const int16_t * rgb2, int cgy, int y,
    uint16_t * yuv2, int cru, uint16_t * yuv1, const int16_t * rgb0,
    int *(*rnd_scratch)[2], int cburv, const int uv_offset, int cbv)
{
  for (x = 0; x < w; x++)
    {
      int r00 = rgb0[x << 1], g00 = rgb1[x << 1], b00 = rgb2[x << 1];
      int y00;
      int r01 = rgb0[x * 2 + 1], g01 = rgb1[x * 2 + 1], b01 = rgb2[x * 2 + 1];
      int y01;
      int u, v, diff;
      y00 =
	r00 * cry + g00 * cgy + b00 * cby + rnd_scratch[0][y & !0][x << 1];
      diff = (y00 & mask) - rnd;
      yuv0[x << 1] = av_clip_uintp2_c (yuv_offset[0] + (y00 >> sh), 12);
      rnd_scratch[0][(y & !0)][(x << 1) + 1] += (diff * 7 + 8) >> 4;
      rnd_scratch[0][!(y & !0)][(x << 1) - 1] += (diff * 3 + 8) >> 4;
      rnd_scratch[0][!(y & !0)][(x << 1) + 0] += (diff * 5 + 8) >> 4;
      rnd_scratch[0][!(y & !0)][(x << 1) + 1] += (diff * 1 + 8) >> 4;
      rnd_scratch[0][(y & !0)][(x << 1) + 0] = rnd;
      y01 =
	r01 * cry + g01 * cgy + b01 * cby + rnd_scratch[0][y & !0][x * 2 + 1];
      diff = (y01 & mask) - rnd;
      yuv0[x * 2 + 1] = av_clip_uintp2_c (yuv_offset[0] + (y01 >> sh), 12);
      rnd_scratch[0][(y & !0)][x * 2 + 2] += (diff * 7 + 8) >> 4;
      rnd_scratch[0][!(y & !0)][x * 2 + 0] += (diff * 3 + 8) >> 4;
      rnd_scratch[0][!(y & !0)][x * 2 + 1] += (diff * 5 + 8) >> 4;
      rnd_scratch[0][!(y & !0)][x * 2 + 2] += (diff * 1 + 8) >> 4;
      rnd_scratch[0][(y & !0)][x * 2 + 1] = rnd;
      u =
	(((r00) + (r01) + 1) >> 1) * cru + (((g00) + (g01) + 1) >> 1) * cgu +
	(((b00) + (b01) + 1) >> 1) * cburv + rnd_scratch[1][y & 1][x];
      diff = (u & mask) - rnd;
      yuv1[x] = av_clip_uintp2_c (uv_offset + (u >> sh), 12);
      rnd_scratch[1][(y & 1)][x + 1] += (diff * 7 + 8) >> 4;
      rnd_scratch[1][!(y & 1)][x - 1] += (diff * 3 + 8) >> 4;
      rnd_scratch[1][!(y & 1)][x + 0] += (diff * 5 + 8) >> 4;
      rnd_scratch[1][!(y & 1)][x + 1] += (diff * 1 + 8) >> 4;
      rnd_scratch[1][(y & 1)][x + 0] = rnd;
      v =
	(((r00) + (r01) + 1) >> 1) * cburv +
	(((g00) + (g01) + 1) >> 1) * cgv + (((b00) + (b01) + 1) >> 1) * cbv +
	rnd_scratch[2][y & 1][x];
      diff = (v & mask) - rnd;
      yuv2[x] = av_clip_uintp2_c (uv_offset + (v >> sh), 12);
      rnd_scratch[2][(y & 1)][x + 1] += (diff * 7 + 8) >> 4;
      rnd_scratch[2][!(y & 1)][x - 1] += (diff * 3 + 8) >> 4;
      rnd_scratch[2][!(y & 1)][x + 0] += (diff * 5 + 8) >> 4;
      rnd_scratch[2][!(y & 1)][x + 1] += (diff * 1 + 8) >> 4;
      rnd_scratch[2][(y & 1)][x + 0] = rnd;
}}
