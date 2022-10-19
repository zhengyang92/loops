#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int ry, uint16_t * dg, const int bh, const uint16_t * sg,
    const int w, const int by, uint16_t * dr, uint16_t * db, const int gh,
    const int gy, const uint16_t * sr, const uint16_t * sb, const int rh)
{
  for (int x = 0; x < w; x++)
    {
      dr[x] = sr[av_clip_c (x - rh, 0, w - 1) + ry];
      dg[x] = sg[av_clip_c (x - gh, 0, w - 1) + gy];
      db[x] = sb[av_clip_c (x - bh, 0, w - 1) + by];
}}
