#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *prv, const double *src, const double scale, const int nb_samples,
    int c, const int channels, const double mult, double *dst)
{
  for (int n = 0; n < nb_samples; n++)
    {
      double current = src[c];
      if (1)
	{
	  dst[c] = (current - prv[c] * mult) * scale;
	  prv[c] = dst[c];
	}
      else
	{
	  dst[c] = current + (current - prv[c]) * mult;
	  prv[c] = current;
	}
      if (1)
	{
	  dst[c] = av_clipd_sse2 (dst[c], -1.0, 1.0);
	}
      dst += channels;
      src += channels;
    }
}
