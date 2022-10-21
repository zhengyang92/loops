#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int i, int width, const uint16_t * src1, const uint16_t * src2,
    uint16_t * dstU, uint16_t * dstV)
{
  for (i = 0; i < width; i++)
     { IACA_START
      dstU[i] = av_bswap16 (src1[i]);
      dstV[i] = av_bswap16 (src2[i]);
     } IACA_END
}
