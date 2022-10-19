#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double qc, int i, int is_signed, int maxval, const float *scaled,
    int *out, int size, float Q34, const float *in)
{
  for (i = 0; i < size; i++)
    {
      qc = scaled[i] * Q34;
      out[i] =
	(int) ((qc + 0.4054) >
	       ((double) maxval) ? ((double) maxval) : (qc + 0.4054));
      if (is_signed && in[i] < 0.0f)
	{
	  out[i] = -out[i];
	}
    }
}
