#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int w2, int i, float nzslope, float nzl, const float ethresh, float e2,
    const float *scaled, int swb_size, float e)
{
  float maxval = 0.0f;
  for (i = 0; i < swb_size; i++)
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
    }
}
