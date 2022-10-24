#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int w, const int rnd, uint8_t * yuv1, int cgu, int cgv,
    const int16_t * yuv_offset, int cby, uint8_t * yuv0, int x, int cry,
    unsigned int mask, const int16_t * rgb1, const int sh,
    const int16_t * rgb2, int cgy, int y, int cru, const int16_t * rgb0,
    uint8_t * yuv2, int *(*rnd_scratch)[2], int cburv, const int uv_offset,
    int cbv)
{
  IACA_START for (x = 0; x < w; x++)
    {
      int r00 = rgb0[x << 0], g00 = rgb1[x << 0], b00 = rgb2[x << 0];
      int y00;
      int u, v, diff;
      y00 =
	r00 * cry + g00 * cgy + b00 * cby + rnd_scratch[0][y & !0][x << 0];
      diff = (y00 & mask) - rnd;
      yuv0[x << 0] = av_clip_uint8_c (yuv_offset[0] + (y00 >> sh));
      rnd_scratch[0][(y & !0)][(x << 0) + 1] += (diff * 7 + 8) >> 4;
      rnd_scratch[0][!(y & !0)][(x << 0) - 1] += (diff * 3 + 8) >> 4;
      rnd_scratch[0][!(y & !0)][(x << 0) + 0] += (diff * 5 + 8) >> 4;
      rnd_scratch[0][!(y & !0)][(x << 0) + 1] += (diff * 1 + 8) >> 4;
      rnd_scratch[0][(y & !0)][(x << 0) + 0] = rnd;
      u =
	(r00) * cru + (g00) * cgu + (b00) * cburv + rnd_scratch[1][y & 1][x];
      diff = (u & mask) - rnd;
      yuv1[x] = av_clip_uint8_c (uv_offset + (u >> sh));
      rnd_scratch[1][(y & 1)][x + 1] += (diff * 7 + 8) >> 4;
      rnd_scratch[1][!(y & 1)][x - 1] += (diff * 3 + 8) >> 4;
      rnd_scratch[1][!(y & 1)][x + 0] += (diff * 5 + 8) >> 4;
      rnd_scratch[1][!(y & 1)][x + 1] += (diff * 1 + 8) >> 4;
      rnd_scratch[1][(y & 1)][x + 0] = rnd;
      v =
	(r00) * cburv + (g00) * cgv + (b00) * cbv + rnd_scratch[2][y & 1][x];
      diff = (v & mask) - rnd;
      yuv2[x] = av_clip_uint8_c (uv_offset + (v >> sh));
      rnd_scratch[2][(y & 1)][x + 1] += (diff * 7 + 8) >> 4;
      rnd_scratch[2][!(y & 1)][x - 1] += (diff * 3 + 8) >> 4;
      rnd_scratch[2][!(y & 1)][x + 0] += (diff * 5 + 8) >> 4;
      rnd_scratch[2][!(y & 1)][x + 1] += (diff * 1 + 8) >> 4;
      rnd_scratch[2][(y & 1)][x + 0] = rnd;
}IACA_END}
