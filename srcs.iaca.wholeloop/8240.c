#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (unsigned int xpos, int i, int16_t * dst, int dstWidth,
    const uint8_t * src, int xInc)
{
  IACA_START for (i = 0; i < dstWidth; i++)
    {
      register unsigned int xx = xpos >> 16;
      register unsigned int xalpha = (xpos & 0xFFFF) >> 9;
      dst[i] = (src[xx] << 7) + (src[xx + 1] - src[xx]) * xalpha;
      xpos += xInc;
}IACA_END}
