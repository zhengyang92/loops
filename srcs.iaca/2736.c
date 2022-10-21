#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int w, int off, uint8_t * src)
{
  for (x = off; x < w; x += 3)
     { IACA_START
      int r = src[x + 0] - ((359 * (src[x + 2] - 128) + 490) >> 8);
      int g =
	src[x + 0] -
	((88 * (src[x + 1] - 128) - 183 * (src[x + 2] - 128) + 30) >> 8);
      int b = src[x + 0] + ((454 * (src[x + 1] - 128) + 574) >> 8);
      src[x + 0] = av_clip_uint8_c (r);
      src[x + 1] = av_clip_uint8_c (g);
      src[x + 2] = av_clip_uint8_c (b);
} IACA_END }
