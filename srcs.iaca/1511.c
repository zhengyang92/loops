#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, const float Q34, int maxval, const float *scaled,
    const float rounding, int *out, int size, int is_signed, const float *in)
{
  for (i = 0; i < size; i++)
     { IACA_START
      float qc = scaled[i] * Q34;
      int tmp =
	(int) ((qc + rounding) >
	       ((float) maxval) ? ((float) maxval) : (qc + rounding));
      if (is_signed && in[i] < 0.0f)
	{
	  tmp = -tmp;
	}
      out[i] = tmp;
     } IACA_END
}
