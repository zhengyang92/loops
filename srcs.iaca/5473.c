#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t component, int scale_low, uint16_t * dest, int x, int width,
    int scale_high, const uint16_t ** src)
{
  for (x = 0; x < width; x++)
     { IACA_START
      component = av_bswap16 (src[0][x]);
      *dest++ = av_bswap16 (component << scale_high | component >> scale_low);
      component = av_bswap16 (src[1][x]);
      *dest++ = av_bswap16 (component << scale_high | component >> scale_low);
      component = av_bswap16 (src[2][x]);
      *dest++ = av_bswap16 (component << scale_high | component >> scale_low);
      component = av_bswap16 (src[3][x]);
      *dest++ = av_bswap16 (component << scale_high | component >> scale_low);
     } IACA_END
}
