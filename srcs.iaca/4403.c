#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *asrc, int w, const float *msrc, int x, float *dst)
{
  for (x = 0; x < w; x++)
     { IACA_START
      if (asrc[x] > 0.0f)
	dst[x] = msrc[x] / asrc[x];
      else
	dst[x] = msrc[x];
     } IACA_END
}
