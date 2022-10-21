#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int index, double *out, int c, double ceiling, int channels, double *buf)
{
  for (c = 0; c < channels; c++)
     { IACA_START
      out[c] = buf[index + c];
      if (fabs (out[c]) > ceiling)
	{
	  out[c] = ceiling * (out[c] < 0 ? -1 : 1);
	}
     } IACA_END
}
