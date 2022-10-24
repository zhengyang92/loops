#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float cnt, const uint8_t * xf0, float progress, const uint8_t * xf1,
    const int width, const int size, uint8_t * dst)
{
  float sum1 = 0.f;
  float sum0 = 0.f;
  IACA_START for (int x = 0; x < width; x++)
    {
      dst[x] = mix (sum0 / cnt, sum1 / cnt, progress);
      if (x + size < width)
	{
	  sum0 += xf0[x + size] - xf0[x];
	  sum1 += xf1[x + size] - xf1[x];
	}
      else
	{
	  sum0 -= xf0[x];
	  sum1 -= xf1[x];
	  cnt--;
	}
     } IACA_END
}
