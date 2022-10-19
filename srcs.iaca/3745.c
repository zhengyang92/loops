#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int y, unsigned int max, int plane_count, unsigned int shift, int x,
    const uint16_t * s, int target_table[2][3], uint16_t * d, int plane,
    const uint16_t * a, unsigned int off)
{
  for (plane = 0; plane < plane_count; plane++)
    {
      int x_index = (plane_count + 1) * x;
      unsigned aswap = av_bswap16 (a[x_index]);
      unsigned u =
	av_bswap16 (s[x_index + plane]) * aswap +
	target_table[((x ^ y) >> 5) & 1][plane] * (max - aswap) + off;
      d[plane_count * x + plane] =
	av_clip_c ((u + (u >> shift)) >> shift, 0, max);
}}
