#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *su1, int nsample, float *su2, int band)
{
  for (; nsample < band + 256; nsample++)
     { IACA_START
      float c1 = su1[nsample];
      float c2 = su2[nsample];
      su1[nsample] = (c1 + c2) * 2.0;
      su2[nsample] = c2 * -2.0;
} IACA_END }
