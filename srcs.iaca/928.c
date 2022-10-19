#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * yptr, uint16_t * vptr, const float r, uint16_t * uptr,
    const int depth, const int width, const float ihigh, const float max,
    const float size, const int subw, const float b, const float imax)
{
  for (int x = 0; x < width; x++)
    {
      const int cx = x >> subw;
      float y = yptr[x] * imax;
      float u = uptr[cx] * imax - .5f;
      float v = vptr[cx] * imax - .5f;
      float tt, t, ny;
      ny = filter (b, r, u, v, size);
      tt = envelope (y);
      t = tt + (1.f - tt) * ihigh;
      ny = (1.f - t) * y + t * ny * y;
      yptr[x] = av_clip_uintp2_c (lrintf (ny * max), depth);
}}
