#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int w, const float *asrc, const float *msrc, int x, float *dst,
    float offsetf)
{
  IACA_START for (x = 0; x < w; x++)
    {
      if (asrc[x] > 0.0f)
	dst[x] = (msrc[x] - offsetf) / asrc[x] + offsetf;
      else
	dst[x] = msrc[x];
     } IACA_END
}
