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
     { IACA_START
      int x_index = (plane_count + 1) * x;
      unsigned u =
	s[x_index + plane] * a[x_index] +
	target_table[((x ^ y) >> 5) & 1][plane] * (max - a[x_index]) + off;
      d[plane_count * x + plane] =
	av_clip_c ((u + (u >> shift)) >> shift, 0, max);
} IACA_END }
