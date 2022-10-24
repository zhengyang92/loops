#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * dither, uint8_t * dst, int i)
{
  IACA_START for (i = 0; i < 8; ++i)
    {
      const int delta0 = dither[i] - (1 << 7);
      const int delta1 = (delta0 + (1 << (4 - 1))) >> 4;
      dst[i] = clip_8b ((int) dst[i] + delta1);
}IACA_END}
