#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int ah, const int w, uint16_t * da, const uint16_t * sa, int ay)
{
  for (int x = 0; x < w; x++)
    {
      da[x] = sa[av_clip_c (x - ah, 0, w - 1) + ay];
}}
