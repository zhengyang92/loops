#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *su2, float w[2][2], int nsample, int band, float *su1)
{
  IACA_START for (; nsample < band + 256; nsample++)
    {
      su1[nsample] *= w[1][0];
      su2[nsample] *= w[1][1];
     } IACA_END
}
