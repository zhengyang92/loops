#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * uptr, const float r, uint8_t * yptr, const int width,
    const float ihigh, uint8_t * vptr, const float max, const float size,
    const int subw, const float b, const float imax)
{
  for (int x = 0; x < width; x++)
     { IACA_START
      const int cx = x >> subw;
      float y = yptr[x] * imax;
      float u = uptr[cx] * imax - .5f;
      float v = vptr[cx] * imax - .5f;
      float tt, t, ny;
      ny = filter (b, r, u, v, size);
      tt = envelope (y);
      t = tt + (1.f - tt) * ihigh;
      ny = (1.f - t) * y + t * ny * y;
      yptr[x] = av_clip_uint8_c (lrintf (ny * max));
} IACA_END }
