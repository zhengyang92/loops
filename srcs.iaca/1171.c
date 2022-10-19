#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (float cnt, const int size, float progress, const int width,
    const uint16_t * xf1, const uint16_t * xf0, uint16_t * dst)
{
  float sum1 = 0.f;
  float sum0 = 0.f;
  for (int x = 0; x < width; x++)
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
    }
}
