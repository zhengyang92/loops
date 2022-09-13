#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const float decay, const int width, float *osrc, uint16_t * dst,
    const uint16_t * src)
{
  for (int x = 0; x < width; x++)
    {
      const float v = fmaxf (src[x], osrc[x] * decay);
      osrc[x] = v;
      if (0)
	{
	  dst[x] = src[x];
	}
      else
	{
	  dst[x] = lrintf (v);
	}
    }
}
