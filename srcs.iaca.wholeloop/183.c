#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float mult, const float *src, const float scale,
    const int nb_samples, float *dst, float *prv)
{
  IACA_START for (int n = 0; n < nb_samples; n++)
    {
      float current = src[n];
      if (1)
	{
	  dst[n] = (current - prv[0] * mult) * scale;
	  prv[0] = dst[n];
	}
      else
	{
	  dst[n] = current + (current - prv[0]) * mult;
	  prv[0] = current;
	}
      if (1)
	{
	  dst[n] = av_clipf_sse (dst[n], -1.f, 1.f);
	}
     } IACA_END
}
