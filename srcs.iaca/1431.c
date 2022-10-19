#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float CLIPPED_ESCAPE, int i, const float *vec, float *out,
    int curbits, float quantized, const float IQ, const int dim,
    const float ROUNDING, const float Q, int BT_ESC, int j, const float *in,
    float qenergy)
{
  float rd = 0.0f;
  for (j = 0; j < dim; j++)
    {
      float t = fabsf (in[i + j]);
      float di;
      if (BT_ESC && vec[j] == 64.0f)
	{
	  if (t >= CLIPPED_ESCAPE)
	    {
	      quantized = CLIPPED_ESCAPE;
	      curbits += 21;
	    }
	  else
	    {
	      int c = av_clip_uintp2_c (quant (t, Q, ROUNDING), 13);
	      quantized = c * cbrtf (c) * IQ;
	      curbits += (31 - __builtin_clz ((c) | 1)) * 2 - 4 + 1;
	}}
      else
	{
	  quantized = vec[j] * IQ;
	}
      di = t - quantized;
      if (out)
	out[i + j] = in[i + j] >= 0 ? quantized : -quantized;
      if (vec[j] != 0.0f)
	curbits++;
      qenergy += quantized * quantized;
      rd += di * di;
    }
}
