#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int ry, const int bh, const int w, const uint8_t * sb, uint8_t * dr,
    const int by, const uint8_t * sr, uint8_t * dg, const int gh,
    const int gy, uint8_t * db, const uint8_t * sg, const int rh)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      dr[x] = sr[av_clip_c (x - rh, 0, w - 1) + ry];
      dg[x] = sg[av_clip_c (x - gh, 0, w - 1) + gy];
      db[x] = sb[av_clip_c (x - bh, 0, w - 1) + by];
} IACA_END }
