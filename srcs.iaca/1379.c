#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, uint16_t * dst, int i, const uint16_t * src)
{
  for (i = 0; i + 8 <= w; i += 8)
    {
      dst[i + 0] = av_bswap16 (src[i + 0]);
      dst[i + 1] = av_bswap16 (src[i + 1]);
      dst[i + 2] = av_bswap16 (src[i + 2]);
      dst[i + 3] = av_bswap16 (src[i + 3]);
      dst[i + 4] = av_bswap16 (src[i + 4]);
      dst[i + 5] = av_bswap16 (src[i + 5]);
      dst[i + 6] = av_bswap16 (src[i + 6]);
      dst[i + 7] = av_bswap16 (src[i + 7]);
    }
}
