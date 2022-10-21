#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * xsrc, int y, int x, const int w, const int slinesize,
    uint8_t * dst, const uint8_t * src, const int h, const uint8_t * ysrc)
{
  for (x = 0; x < w; x++)
     { IACA_START
      int Y = av_clip_c (y + ysrc[x] - 128, 0, h - 1);
      int X = av_clip_c (x + xsrc[x] - 128, 0, w - 1);
      dst[x] = src[Y * slinesize + X];
} IACA_END }
