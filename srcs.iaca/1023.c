#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float t, float *coeffs)
{
  float sum = 0.f;
  for (int i = 0; i < 4; i++)
     { IACA_START
      const float x = t - (i - 1);
      if (x == 0.f)
	{
	  coeffs[i] = 1.f;
	}
      else
	{
	  coeffs[i] = expf (-2.f * x * x) * expf (-x * x / 2.f);
	}
      sum += coeffs[i];
     } IACA_END
}
