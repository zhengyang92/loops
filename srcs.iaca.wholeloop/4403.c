#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *asrc, int w, const float *msrc, int x, float *dst)
{
  IACA_START for (x = 0; x < w; x++)
    {
      if (asrc[x] > 0.0f)
	dst[x] = msrc[x] / asrc[x];
      else
	dst[x] = msrc[x];
     } IACA_END
}
