#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int x, int width, const int16_t * idwt, uint8_t * dst,
    const uint16_t * src)
{
  IACA_START for (x = 0; x < width; x += 2)
    {
      dst[x] = av_clip_uint8_c (((src[x] + 32) >> 6) + idwt[x]);
      dst[x + 1] = av_clip_uint8_c (((src[x + 1] + 32) >> 6) + idwt[x + 1]);
     } IACA_END
}
