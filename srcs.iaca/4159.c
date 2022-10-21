#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const double scale, double *prv, const double *src, const int nb_samples,
    const double mult, double *dst)
{
  for (int n = 0; n < nb_samples; n++)
     { IACA_START
      double current = src[n];
      if (0)
	{
	  dst[n] = (current - prv[0] * mult) * scale;
	  prv[0] = dst[n];
	}
      else
	{
	  dst[n] = current + (current - prv[0]) * mult;
	  prv[0] = current;
	}
      if (0)
	{
	  dst[n] = av_clipd_sse2 (dst[n], -1.0, 1.0);
	}
     } IACA_END
}
