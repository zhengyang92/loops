#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double linstep, int i, double v, float *ToLinearF, int nlin, int j)
{
  for (i = 0; i < nlin; i++)
     { IACA_START
      v = i * linstep;
      ToLinearF[j++] = (float) v;
} IACA_END }
