#include <stdint.h>
#include <stdio.h>






int
fn (int w, const float *asrc, const float *msrc, int x, float *dst)
{
  for (x = 0; x < w; x++)
    {
      if (asrc[x] > 0.0f)
	dst[x] = msrc[x] / asrc[x];
      else
	dst[x] = msrc[x];
    }
}
