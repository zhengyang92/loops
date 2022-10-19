#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int y, int w, unsigned int max, unsigned int shift, int x,
    const uint16_t * s, int target_table[2][3], int plane, uint16_t * d,
    const uint16_t * a, unsigned int off)
{
  for (x = 0; x < w; x++)
    {
      unsigned u =
	s[x] * a[x] + target_table[((x ^ y) >> 5) & 1][plane] * (max - a[x]) +
	off;
      d[x] = av_clip_c ((u + (u >> shift)) >> shift, 0, max);
}}
