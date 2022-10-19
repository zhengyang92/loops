#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int hasAlpha, int dstW, uint16_t ** dest16, int i)
{
  for (i = 0; i < dstW; i++)
    {
      dest16[0][i] = av_bswap16 (dest16[0][i]);
      dest16[1][i] = av_bswap16 (dest16[1][i]);
      dest16[2][i] = av_bswap16 (dest16[2][i]);
      if (hasAlpha)
	dest16[3][i] = av_bswap16 (dest16[3][i]);
    }
}
