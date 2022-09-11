#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float cnt, const uint8_t * xf0, const uint8_t * xf1, const int size,
    const int width, float progress, uint8_t * dst)
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
