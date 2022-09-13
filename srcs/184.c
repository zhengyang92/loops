#include <stdint.h>
#include <stdio.h>






int
fn (const float mult, const float *src, const float scale,
    const int nb_samples, float *dst, float *prv, int c, const int channels)
{
  for (int n = 0; n < nb_samples; n++)
    {
      float current = src[c];
      if (0)
	{
	  dst[c] = (current - prv[c] * mult) * scale;
	  prv[c] = dst[c];
	}
      else
	{
	  dst[c] = current + (current - prv[c]) * mult;
	  prv[c] = current;
	}
      if (0)
	{
	  dst[c] = av_clipf_sse (dst[c], -1.f, 1.f);
	}
      dst += channels;
      src += channels;
    }
}
