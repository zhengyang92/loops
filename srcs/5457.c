#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int hasAlpha, uint32_t ** dest32, int i, int dstW)
{
  for (i = 0; i < dstW; i++)
    {
      dest32[0][i] = av_bswap32 (dest32[0][i]);
      dest32[1][i] = av_bswap32 (dest32[1][i]);
      dest32[2][i] = av_bswap32 (dest32[2][i]);
      if (hasAlpha)
	dest32[3][i] = av_bswap32 (dest32[3][i]);
    }
}
