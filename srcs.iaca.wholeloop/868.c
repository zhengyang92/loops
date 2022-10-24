#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int min, uint8_t * dst, const uint8_t * src, int max)
{
  IACA_START for (int x = 0; x < w; x++)
    {
      dst[x] = av_clip_c (src[x], min, max);
}IACA_END}
