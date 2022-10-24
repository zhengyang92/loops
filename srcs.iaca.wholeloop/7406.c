#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (int w, const int rnd, uint8_t * yuv1, ptrdiff_t s, int cgu, int cgv,
    const int16_t * yuv_offset, int cby, uint8_t * yuv0, int x, int cry,
    unsigned int mask, const int sh, const int16_t * rgb1,
    const int16_t * rgb2, int cgy, int y, int cru, const int16_t * rgb0,
    uint8_t * yuv2, int *(*rnd_scratch)[2], int cburv, const int uv_offset,
    ptrdiff_t s0, int cbv)
{
  IACA_START for (x = 0; x < w; x++)
    {
      int r00 = rgb0[x << 1], g00 = rgb1[x << 1], b00 = rgb2[x << 1];
      int y00;
      int r01 = rgb0[x * 2 + 1], g01 = rgb1[x * 2 + 1], b01 = rgb2[x * 2 + 1];
      int y01;
      int r10 = rgb0[x * 2 + 0 + s], g10 = rgb1[x * 2 + 0 + s], b10 =
	rgb2[x * 2 + 0 + s];
      int r11 = rgb0[x * 2 + 1 + s], g11 = rgb1[x * 2 + 1 + s], b11 =
	rgb2[x * 2 + 1 + s];
      int y10, y11;
      int u, v, diff;
      y00 =
	r00 * cry + g00 * cgy + b00 * cby + rnd_scratch[0][y & !1][x << 1];
      diff = (y00 & mask) - rnd;
      yuv0[x << 1] = av_clip_uint8_c (yuv_offset[0] + (y00 >> sh));
      rnd_scratch[0][(y & !1)][(x << 1) + 1] += (diff * 7 + 8) >> 4;
      rnd_scratch[0][!(y & !1)][(x << 1) - 1] += (diff * 3 + 8) >> 4;
      rnd_scratch[0][!(y & !1)][(x << 1) + 0] += (diff * 5 + 8) >> 4;
      rnd_scratch[0][!(y & !1)][(x << 1) + 1] += (diff * 1 + 8) >> 4;
      rnd_scratch[0][(y & !1)][(x << 1) + 0] = rnd;
      y01 =
	r01 * cry + g01 * cgy + b01 * cby + rnd_scratch[0][y & !1][x * 2 + 1];
      diff = (y01 & mask) - rnd;
      yuv0[x * 2 + 1] = av_clip_uint8_c (yuv_offset[0] + (y01 >> sh));
      rnd_scratch[0][(y & !1)][x * 2 + 2] += (diff * 7 + 8) >> 4;
      rnd_scratch[0][!(y & !1)][x * 2 + 0] += (diff * 3 + 8) >> 4;
      rnd_scratch[0][!(y & !1)][x * 2 + 1] += (diff * 5 + 8) >> 4;
      rnd_scratch[0][!(y & !1)][x * 2 + 2] += (diff * 1 + 8) >> 4;
      rnd_scratch[0][(y & !1)][x * 2 + 1] = rnd;
      y10 = r10 * cry + g10 * cgy + b10 * cby + rnd_scratch[0][1][x * 2 + 0];
      diff = (y10 & mask) - rnd;
      yuv0[x * 2 + 0 + s0] = av_clip_uint8_c (yuv_offset[0] + (y10 >> sh));
      rnd_scratch[0][1][x * 2 + 1] += (diff * 7 + 8) >> 4;
      rnd_scratch[0][0][x * 2 - 1] += (diff * 3 + 8) >> 4;
      rnd_scratch[0][0][x * 2 + 0] += (diff * 5 + 8) >> 4;
      rnd_scratch[0][0][x * 2 + 1] += (diff * 1 + 8) >> 4;
      rnd_scratch[0][1][x * 2 + 0] = rnd;
      y11 = r11 * cry + g11 * cgy + b11 * cby + rnd_scratch[0][1][x * 2 + 1];
      diff = (y11 & mask) - rnd;
      yuv0[x * 2 + 1 + s0] = av_clip_uint8_c (yuv_offset[0] + (y11 >> sh));
      rnd_scratch[0][1][x * 2 + 2] += (diff * 7 + 8) >> 4;
      rnd_scratch[0][0][x * 2 + 0] += (diff * 3 + 8) >> 4;
      rnd_scratch[0][0][x * 2 + 1] += (diff * 5 + 8) >> 4;
      rnd_scratch[0][0][x * 2 + 2] += (diff * 1 + 8) >> 4;
      rnd_scratch[0][1][x * 2 + 1] = rnd;
      u =
	(((r00) + (r01) + (r10) + (r11) + 2) >> 2) * cru +
	(((g00) + (g01) + (g10) + (g11) + 2) >> 2) * cgu +
	(((b00) + (b01) + (b10) + (b11) + 2) >> 2) * cburv +
	rnd_scratch[1][y & 1][x];
      diff = (u & mask) - rnd;
      yuv1[x] = av_clip_uint8_c (uv_offset + (u >> sh));
      rnd_scratch[1][(y & 1)][x + 1] += (diff * 7 + 8) >> 4;
      rnd_scratch[1][!(y & 1)][x - 1] += (diff * 3 + 8) >> 4;
      rnd_scratch[1][!(y & 1)][x + 0] += (diff * 5 + 8) >> 4;
      rnd_scratch[1][!(y & 1)][x + 1] += (diff * 1 + 8) >> 4;
      rnd_scratch[1][(y & 1)][x + 0] = rnd;
      v =
	(((r00) + (r01) + (r10) + (r11) + 2) >> 2) * cburv +
	(((g00) + (g01) + (g10) + (g11) + 2) >> 2) * cgv +
	(((b00) + (b01) + (b10) + (b11) + 2) >> 2) * cbv +
	rnd_scratch[2][y & 1][x];
      diff = (v & mask) - rnd;
      yuv2[x] = av_clip_uint8_c (uv_offset + (v >> sh));
      rnd_scratch[2][(y & 1)][x + 1] += (diff * 7 + 8) >> 4;
      rnd_scratch[2][!(y & 1)][x - 1] += (diff * 3 + 8) >> 4;
      rnd_scratch[2][!(y & 1)][x + 0] += (diff * 5 + 8) >> 4;
      rnd_scratch[2][!(y & 1)][x + 1] += (diff * 1 + 8) >> 4;
      rnd_scratch[2][(y & 1)][x + 0] = rnd;
}IACA_END}
