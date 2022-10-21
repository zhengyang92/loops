#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int num_pixels, uint16_t * s, int i, uint16_t * d)
{
  for (i = 0; i < num_pixels; i++)
     { IACA_START
      d[4 * i] = 1 ? av_bswap16 (s[3 * i + 2]) : s[3 * i + 2];
      d[4 * i + 1] = 1 ? av_bswap16 (s[3 * i + 1]) : s[3 * i + 1];
      d[4 * i + 2] = 1 ? av_bswap16 (s[3 * i]) : s[3 * i];
      d[4 * i + 3] = 0xFFFF;
     } IACA_END
}
