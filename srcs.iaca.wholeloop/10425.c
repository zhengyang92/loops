#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float mean, float var, int i, float *output, float *delta, int n,
    float thresh)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      if (delta[i] > mean + thresh * sqrt (var))
	delta[i] = output[i];
      else
	delta[i] = 0;
     } IACA_END
}
