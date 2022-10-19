#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int y, int w, unsigned int max, unsigned int shift, int x,
    const uint16_t * s, int target_table[2][3], uint16_t * d, int plane,
    const uint16_t * a, unsigned int off)
{
  for (x = 0; x < w; x++)
    {
      unsigned aswap = av_bswap16 (a[x]);
      unsigned u =
	av_bswap16 (s[x]) * aswap +
	target_table[((x ^ y) >> 5) & 1][plane] * (max - aswap) + off;
      d[x] = av_clip_c ((u + (u >> shift)) >> shift, 0, max);
}}
