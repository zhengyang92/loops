#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int w2, int i, float nzslope, float nzl, const float ethresh,
    const float *scaled, float e2, int swb_size, float e)
{
  float maxval = 0.0f;
  IACA_START for (i = 0; i < swb_size; i++)
    {
      float s = fabsf (scaled[w2 * 128 + i]);
      maxval = ((maxval) > (s) ? (maxval) : (s));
      e += s;
      e2 += s *= s;
      if (s >= ethresh)
	{
	  nzl += 1.0f;
	}
      else
	{
	  if (nzslope == 2.f)
	    nzl += (s / ethresh) * (s / ethresh);
	  else
	    nzl += ff_fast_powf (s / ethresh, nzslope);
	}
     } IACA_END
}
