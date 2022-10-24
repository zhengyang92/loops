#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float CLIPPED_ESCAPE, int i, const float *vec, int curbits,
    const float IQ, const float Q, const int dim, int BT_ESC, int j,
    const float *in)
{
  float rd = 0.0f;
  IACA_START for (j = 0; j < dim; j++)
    {
      float t = fabsf (in[i + j]);
      float di;
      if (BT_ESC && vec[j] == 64.0f)
	{
	  if (t >= CLIPPED_ESCAPE)
	    {
	      di = t - CLIPPED_ESCAPE;
	      curbits += 21;
	    }
	  else
	    {
	      int c = av_clip_uintp2_c (quant (t, Q), 13);
	      di = t - c * cbrtf (c) * IQ;
	      curbits += (31 - __builtin_clz ((c) | 1)) * 2 - 4 + 1;
	}}
      else
	{
	  di = t - vec[j] * IQ;
	}
      if (vec[j] != 0.0f)
	curbits++;
      rd += di * di;
     } IACA_END
}
