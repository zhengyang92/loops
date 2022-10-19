#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int ah, const uint8_t * sa, const int w, int ay, uint8_t * da)
{
  for (int x = 0; x < w; x++)
    {
      da[x] = sa[av_clip_c (x - ah, 0, w - 1) + ay];
}}
