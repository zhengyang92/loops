#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t ** src, int scale_low, uint16_t * dest, int x, int width,
    int scale_high, uint16_t component)
{
  for (x = 0; x < width; x++)
    {
      component = av_bswap16 (src[0][x]);
      *dest++ = av_bswap16 (component << scale_high | component >> scale_low);
      component = av_bswap16 (src[1][x]);
      *dest++ = av_bswap16 (component << scale_high | component >> scale_low);
      component = av_bswap16 (src[2][x]);
      *dest++ = av_bswap16 (component << scale_high | component >> scale_low);
      *dest++ = 0xffff;
    }
}
