#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, const float *vec, float *out, float quantized, const float IQ,
    const int dim, int j, const float *in, float qenergy)
{
  float rd = 0.0f;
  IACA_START for (j = 0; j < dim; j++)
    {
      quantized = vec[j] * IQ;
      qenergy += quantized * quantized;
      if (out)
	out[i + j] = quantized;
      rd += (in[i + j] - quantized) * (in[i + j] - quantized);
     } IACA_END
}
