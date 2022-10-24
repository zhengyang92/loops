#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int num_pixels, uint16_t * s, int i, uint16_t * d)
{
  IACA_START for (i = 0; i < num_pixels; i += 3)
    {
      d[i] = 1 ? av_bswap16 (s[i + 2]) : s[i + 2];
      d[i + 1] = 1 ? av_bswap16 (s[i + 1]) : s[i + 1];
      d[i + 2] = 1 ? av_bswap16 (s[i]) : s[i];
     } IACA_END
}
