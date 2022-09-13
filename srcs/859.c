#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const float decay, const int width, float *osrc, const uint8_t * src,
    uint8_t * dst)
{
  for (int x = 0; x < width; x++)
    {
      const float v = fmaxf (src[x], osrc[x] * decay);
      osrc[x] = v;
      if (1)
	{
	  dst[x] = src[x];
	}
      else
	{
	  dst[x] = lrintf (v);
	}
    }
}
